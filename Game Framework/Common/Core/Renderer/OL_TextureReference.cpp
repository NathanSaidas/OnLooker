#include "OL_TextureReference.h"
#include "../../Utilities/OL_Utilities.h"
#include "../../Libraries/OL_OpenGL.h"
#include "OL_Texture.h"

namespace OnLooker
{
    TextureReference::TextureReference()
    {
        m_Count = 0;
        m_Texture = 0;
    }
    TextureReference::~TextureReference()
    {

    }
    bool TextureReference::load(std::string aFilename, int aUnit, bool aUseUnit)
    {
        addReference();

        if(m_Texture != 0)
        {
            //Texture already here
            return false;
        }
        std::string textureName = aFilename;
        aFilename = FilePath::getInstance()->convertPathForTextures(aFilename);

		unsigned char * data;
        int width(0),height(0);
        data = SOIL_load_image(aFilename.c_str(),&width,&height,0,SOIL_LOAD_RGBA);
		//unsigned int error = lodepng_decode32_file(&data,&width,&height,aFilename.c_str());

        if(data == 0)
        {
            SOIL_free_image_data(data);
            removeReference();
            //failure to load texture remove reference
            return false;
        }
        unsigned int textureHandle = 0;

        glGenTextures(1, &textureHandle);
		if(aUseUnit == true)
		{
			glActiveTexture(GL_TEXTURE0 + aUnit);
		}
        glBindTexture(GL_TEXTURE_2D,textureHandle);
        glTexImage2D(GL_TEXTURE_2D,
                    0,
                    GL_RGBA,
                    width,
                    height,
                    0,
                    GL_RGBA,
                    GL_UNSIGNED_BYTE,
                    data);
        SOIL_free_image_data(data);
        
        //GL_CLAMP - Does not repeat, just stretches lines
        //GL_REPEAT - repeats.. checker board pattern
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //GL_CLAMP / GL_CLAMP_TO_EDGE / GL_REPEAT / GL_MIRRORED_REPEAT
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //GL_CLAMP / GL_CLAMP_TO_EDGE GL_REPEAT / GL_MIRRORED_REPEAT
        //GL_LINEAR - Smooth
        //GL_NEAREST - 8 Bit graphics
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST / GL_LINEAR
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //GL_NEAREST / GL_LINEAR


		//the min filter is used whenever a surface is rendered with smaller dimensions that its corresponding texture
		//the mag filter is used whenever the surface is bigger than the texture being applied

        
        //Unbind
        glBindTexture(GL_TEXTURE_2D,0);

        m_Texture = new Texture();
        m_Texture->m_Filename = aFilename;
        m_Texture->m_TextureName = textureName;
        m_Texture->m_ID = textureHandle;
        m_Texture->m_FileWidth = width;
        m_Texture->m_FileHeight = height;

        m_Texture->m_SourceX = 0;
        m_Texture->m_SourceY = 0;
        m_Texture->m_SourceWidth = m_Texture->m_FileWidth;
        m_Texture->m_SourceHeight = m_Texture->m_FileHeight;

        m_Texture->m_MinU = 0.0f;//m_Texture->m_SourceX / width;
        m_Texture->m_MaxU = 1.0f;//m_Texture->m_SourceY / width;
        m_Texture->m_MinV = 0.0f;//m_Texture->m_SourceWidth / height;
        m_Texture->m_MaxV = 1.0f;//m_Texture->m_SourceHeight / height;

        return true;
    }

    std::string TextureReference::getName()
    {
        if(m_Texture != 0)
        {
            return m_Texture->getTextureName();
        }
        else
        {
            return "BadFileName";
        }
    }

    void TextureReference::addReference()
    {
        m_Count ++;
    }
    void TextureReference::removeReference()
    {
        m_Count --;
        if(m_Count <= 0)
        {
            m_Count = 0;
            if(m_Texture != 0)
            {
                delete m_Texture;
                m_Texture = 0;
            }
        }
    }
    int TextureReference::getReferenceCount()
    {
        return m_Count;
    }
}