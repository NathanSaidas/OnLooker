#include "OL_Renderer.h"
#include "../Memory/OL_Memory.h"
#include "../../Utilities/OL_Utilities.h"
#include "../../Math/OL_Math.h"
#include "OL_TextureReference.h"
#include "OL_Texture.h"

namespace OnLooker
{
    Renderer * Renderer::s_Instance = 0;
    Renderer * Renderer::instance()
    {
        if(s_Instance == 0)
        {
            s_Instance = Memory::instantiate<Renderer>();
        }
        return s_Instance;
    }
    void Renderer::destroy()
    {
        if(s_Instance != 0)
        {
            s_Instance = Memory::destroy<Renderer>(s_Instance);
        }
    }
    Renderer::Renderer()
    {
        m_Initialized = false;
    }
    Renderer::~Renderer()
    {

    }
    bool Renderer::isReady()
    {
        return m_Initialized;
    }
    void Renderer::initialize(double aWindowWidth, double aWindowHeight)
    {
        
        Debug::console->outputFormat("SetupContext-Begin-\n");
        glViewport(0,0,aWindowWidth,aWindowHeight);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0,aWindowWidth,aWindowHeight,0.0,-1.0,1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        setBackgroundColor(Colors::cornflowerBlue());
        setForegroundColor(Colors::turquoise());
        enableBlending();
        //Check Errors
        checkForErrors();
        m_Initialized = true;

        
        Debug::console->outputFormat("SetupContext-End-\n");
    }

    void Renderer::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    Color Renderer::getBackgroundColor()
    {
        return m_BackgroundColor;
    }
    void Renderer::setBackgroundColor(Color aBackgroundColor)
    {
        m_BackgroundColor = aBackgroundColor;
        glClearColor(m_BackgroundColor.red,m_BackgroundColor.green,m_BackgroundColor.blue,m_BackgroundColor.alpha);
    }

    Color Renderer::getForegroundColor()
    {
        return m_ForegroundColor;
    }
    void Renderer::setForegroundColor(Color aForegroundColor)
    {
        m_ForegroundColor = aForegroundColor;
    }

    void Renderer::enableClip(float x, float y, float width, float height)
    {
        glEnable(GL_SCISSOR_TEST);
        glScissor(x, y, width, height);
    }
    void Renderer::disableClip()
    {
        glDisable(GL_SCISSOR_TEST);
    }


    void Renderer::enableBlending(GLenum aSourceBlending, GLenum aDestinationBlending )
    {
		glDepthMask(GL_FALSE);
        glEnable(GL_BLEND);
        glBlendFunc(aSourceBlending, aDestinationBlending);
    }
    void Renderer::disableBlending()
    {
        glDisable(GL_BLEND);
    }

    float Renderer::getPointSize()
    {
        float pointSize;
        glGetFloatv(GL_POINT_SIZE, &pointSize);
        return pointSize;
    }
    void Renderer::setPointSize(float aPointSize)
    {
        glPointSize(aPointSize);
    }
    void Renderer::resetPointSize()
    {
        setPointSize(1.0f);
    }
    
    float Renderer::getLineWidth()
    {
        float lineWidth;
        glGetFloatv(GL_LINE_WIDTH, &lineWidth);
        return lineWidth;
    }
    void Renderer::setLineWidth(float aLineWidth)
    {
        glLineWidth(aLineWidth);
    }
    void Renderer::resetLineWidth()
    {
        setLineWidth(1.0f);
    }


    void Renderer::drawPoint(float x, float y)
    {
        float vertices[] = { x, y };
	    int vertexSize = 2;
	    int vertexCount = 1;
	    drawPolygon(GL_POINTS, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawLine(float x1, float y1, float x2, float y2)
    {
        float vertices[] = { x1, y1, x2, y2 };
	    int vertexSize = 2;
	    int vertexCount = 2;
	    drawPolygon(GL_LINES, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
    {
        float vertices[] = { x1, y1, x2, y2, x3, y3 };
	    int vertexSize = 2;
	    int vertexCount = 3;
        drawPolygon(GL_TRIANGLES, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawCircle(float x, float y, float aRadius, bool aIsFilled, int aLineSegments )
    {
        int vertexSize = 2;
	    int vertexCount = aLineSegments;
	    float *  vertices = new float[vertexCount * vertexSize];
    
	    float rotationAmount = (360.0f / aLineSegments);
    
	    int count = 0;
	    for (float i = 0; i < 359.99f; i+= rotationAmount)
	    {
		    vertices[count++] = x + (cosf((PI * i / 180.0)) * aRadius);
            vertices[count++] = y + (sinf((PI * i / 180.0)) * aRadius);
	    }
    
	    drawPolygon(aIsFilled ? GL_TRIANGLE_FAN : GL_LINE_LOOP, vertices, vertexSize, vertexCount);
    }
    void Renderer::drawRectangle(float x, float y, float aWidth, float aHeight, bool aIsFilled )
    {
        const int vertexSize = 2;
	    const int vertexCount = 4;
	    float vertices[vertexSize * vertexCount];
    
	    vertices[0] = x;          vertices[1] = y;
	    vertices[2] = x + aWidth; vertices[3] = y;
	    vertices[4] = x + aWidth; vertices[5] = y + aHeight;
	    vertices[6] = x;          vertices[7] = y + aHeight;

    
		drawPolygon(aIsFilled ? GL_TRIANGLE_FAN : GL_LINE_LOOP, vertices, vertexSize, vertexCount);
    }

    void Renderer::drawPolygon(GLenum aRenderMode, float * aVertices, int aVertexSize, int aVertexCount)
    {
        //Setup the colors array based on the foreground color
	    int colorSize = 4;
	    float * colors = new float[colorSize * aVertexCount];
	    int count = 0;
	    for (int i = 0; i < aVertexCount; ++i)
	    {
		    colors[count++] = m_ForegroundColor.red;
            colors[count++] = m_ForegroundColor.green;
            colors[count++] = m_ForegroundColor.blue;
            colors[count++] = m_ForegroundColor.alpha;
	    }
    
	    //If the foreground alpha isn't full, enable blending
	    //if(m_ForegroundColor.alpha != 1.0f)
	    ///{
		    enableBlending();
	    //}
	    //Draw the polygon
	    drawPolygon(aRenderMode, aVertices, aVertexSize, aVertexCount, colors, colorSize);
    
	    //If the foreground alpha isn't full, blending is enabled, disable it
	    //if(m_ForegroundColor.alpha != 1.0f)
	    //{
		    disableBlending();
	    //}
    }
    void Renderer::drawPolygon(GLenum aRenderMode, float * aVertices, int aVertexSize, int aVertexCount, float * aColors, int aColorSize)
    {
        //Enable the vertex array
	    glEnableClientState(GL_VERTEX_ARRAY);
	    glVertexPointer(aVertexSize, GL_FLOAT, 0, aVertices);
	    //Enable the color array
	    glEnableClientState(GL_COLOR_ARRAY);
	    glColorPointer(aColorSize, GL_FLOAT, 0, aColors);
    
	    //Render the polygon.
	    glDrawArrays(aRenderMode, 0, aVertexCount);
    
	    //Disable the vertex array client state.
	    glDisableClientState(GL_VERTEX_ARRAY);
	    glDisableClientState(GL_COLOR_ARRAY);
    }

    void Renderer::drawTexture(unsigned int aTextureID, float x, float y, float aAngle )
    {
        Texture * texture = getTexture(aTextureID);
        if(texture != NULL)
        {
            drawTexture(aTextureID, x, y, texture->getSourceWidth(), texture->getSourceHeight(), aAngle);
        }
    }
    void Renderer::drawTexture(unsigned int aTextureID, float x, float y, float aWidth, float aHeight, float aAngle)
    {
        Texture * texture = getTexture(aTextureID); 
        //Safety check the texture
	    if(texture != NULL)
	    {
            float uvCoordinates[8];
		    float vertices[8];
        
		
		    uvCoordinates[0] = texture->getMinU(); uvCoordinates[1] = texture->getMinV();
		    uvCoordinates[2] = texture->getMaxU(); uvCoordinates[3] = texture->getMinV();
		    uvCoordinates[4] = texture->getMaxU(); uvCoordinates[5] = texture->getMaxV();
		    uvCoordinates[6] = texture->getMinU(); uvCoordinates[7] = texture->getMaxV();
        
		    //Set the vertices
		    vertices[0] = x;           vertices[1] = y;
		    vertices[2] = x + aWidth;  vertices[3] = y;
		    vertices[4] = x + aWidth;  vertices[5] = y + aHeight;
		    vertices[6] = x; 		   vertices[7] = y + aHeight;
        
           

            /*//Push the Matrix
            glPushMatrix();
        
            //Translate the texture
            glTranslatef(x, y, 0.0f);
        
            //Rotate the texture
            if(aAngle != 0.0f)
            {
                //Rotate around the center of the texture.
                glTranslatef(aWidth/2, aHeight/2, 0.0f);
                glRotatef(aAngle, 0.0f, 0.0f, 1.0f);
                glTranslatef(-aWidth/2, -aHeight/2, 0.0f);
            }*/
        
		    //Draw the texture
            drawTexture(aTextureID, uvCoordinates, vertices);
        
            //Pop the Matrix
            //glPopMatrix();
        }
    }

    void Renderer::drawTexture(unsigned int aTextureID, float * aTexCoordinates, float * aVertices)
    {
        Texture * texture = getTexture(aTextureID);
        if(texture != NULL)
	    {
		    int vertexCount = 4;
		    int vertexSize = 2;
        
		    //Setup the colors array based on the foreground color
		    int colorSize = 4;
		    float * colors = new float[colorSize * vertexCount];
		    int count = 0;
		    for (int i = 0; i < vertexCount; ++i)
		    {
                colors[count++] = 1.0f;
			    colors[count++] = 1.0f;
			    colors[count++] = 1.0f;
                colors[count++] = 1.0f;

		    }
        
		    //If the foreground alpha isn't full, enable blending
			enableBlending();   
            //Set the uvCoordinates of the texture.
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, aTexCoordinates);
        
		    //Enable the texture and bind it
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, texture->getID());
        
		    //Draw the texture
		    drawPolygon(GL_TRIANGLE_STRIP, aVertices, vertexSize, vertexCount, colors, colorSize);
        
            //Disable the client states
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glDisable(GL_TEXTURE_2D);
        
		    //If the foreground alpha isn't full, blending is enabled, disable it
			disableBlending();
	    }
    }

    unsigned int Renderer::loadTexture(std::string aTextureName)
    {
        //Check for reference
        for(int i = 0; i < m_Textures.size(); i++)
        {
            if(m_Textures[i] != 0)
            {
                if(m_Textures[i]->getName() == aTextureName)
                {
                    m_Textures[i]->addReference();
                    return i;
                }
            }
        }

        //If the texture didnt exist
        m_Textures.push_back(new TextureReference());
        int index = m_Textures.size() -1;
        m_Textures.at(index)->load(aTextureName);
        return index;
    }

    bool Renderer::unloadTexture(std::string aTextureName)
    {
        for(int i = 0; i < m_Textures.size(); i++)
        {
            if(m_Textures[i] != 0)
            {
                if(m_Textures[i]->getName() == aTextureName)
                {
                    m_Textures[i]->removeReference();
                    return true;
                }
            }
        }

        return false;
    }

    void Renderer::checkForErrors()
    {
        int error = glGetError();

        while(error != GL_NO_ERROR)
        {
            /*switch(error)
            {
            case GL_INVALID_ENUM:
                    Debug::console->output("GL_INVALID_ENUM",true);
                break;
            case GL_INVALID_VALUE:
                    Debug::console->output("GL_INVALID_VALUE",true);
                break;
            case GL_INVALID_OPERATION:
                    Debug::console->output("GL_INVALID_OPERATION",true);
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                    Debug::console->output("GL_INVALID_FRAMEBUFFER_OPERATION",true);
                break;

                
            }

            error = glGetError();*/
        }
    }
	std::string Renderer::toString()
	{
		return "";
	}
    Texture * Renderer::getTexture(unsigned int aID)
    {
        if(aID > m_Textures.size() -1)
        {
            Debug::console->outputFormat("Renderer::getTexture: ID out of range");
            return 0;
        }
        return m_Textures[aID]->m_Texture;
    }


	unsigned int Renderer::getMesh(std::string aMeshName)
	{
		//Search for mesh in list of meshes by name
		//return handle to mesh(index in list)
		return 2;
	}
	void Renderer::setMeshValue(unsigned int aLocation, float aMeshValue)
	{
		float ** mesh = new float *[3];
		mesh[0] = 0;
		mesh[1] = 0;
		mesh[2] = new float(5.0);
		//get mesh object at index (aLocation)

		//if not valid return
		if(mesh[aLocation] == 0)
		{
			Debug::console->output("Mesh not valid",false);
			return;
		}
		//get the mesh object and set it's value to meshvalue
		(*mesh[aLocation]) = aMeshValue;
	}
}