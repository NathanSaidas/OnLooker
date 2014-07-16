#include "OL_OpenGLRenderer.h"
#include <math.h>
#include "../Libraries/glew-1.10.0/glew.h"
#include "../Math/OL_Math.h"
void OpenGLRenderer::drawPoint(float x, float y)
{
    float vertices[] = { x, y };
	int vertexSize = 2;
	int vertexCount = 1;
	drawPolygon(GL_POINTS, vertices, vertexSize, vertexCount);
}
void OpenGLRenderer::drawLine(float x1, float y1, float x2, float y2)
{
    float vertices[] = { x1, y1, x2, y2 };
	int vertexSize = 2;
	int vertexCount = 2;
	drawPolygon(GL_LINES, vertices, vertexSize, vertexCount);
}
void OpenGLRenderer::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float vertices[] = { x1, y1, x2, y2, x3, y3 };
	int vertexSize = 2;
	int vertexCount = 3;
    drawPolygon(GL_TRIANGLES, vertices, vertexSize, vertexCount);
}
void OpenGLRenderer::drawCircle(float x, float y, float aRadius, bool aIsFilled, int aLineSegments )
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
void OpenGLRenderer::drawRectangle(float x, float y, float aWidth, float aHeight, bool aIsFilled )
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

void OpenGLRenderer::drawPolygon(int aRenderMode, float * aVertices, int aVertexSize, int aVertexCount)
{
    //Setup the colors array based on the foreground color
	int colorSize = 4;
	float * colors = new float[colorSize * aVertexCount];
	int count = 0;
	for (int i = 0; i < aVertexCount; ++i)
	{
		colors[count++] = 1.f;
        colors[count++] = 1.f;
        colors[count++] = 1.f;
        colors[count++] = 1.f;
	}
    
	//If the foreground alpha isn't full, enable blending
	//if(m_ForegroundColor.alpha != 1.0f)
	///{
		//enableBlending();
	//}
	//Draw the polygon
	drawPolygon(aRenderMode, aVertices, aVertexSize, aVertexCount, colors, colorSize);
    
	//If the foreground alpha isn't full, blending is enabled, disable it
	//if(m_ForegroundColor.alpha != 1.0f)
	//{
		//disableBlending();
	//}
}
void OpenGLRenderer::drawPolygon(int aRenderMode, float * aVertices, int aVertexSize, int aVertexCount, float * aColors, int aColorSize)
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