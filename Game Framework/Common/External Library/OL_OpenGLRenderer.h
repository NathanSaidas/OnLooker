#ifndef OL_RENDERER_H
#define OL_RENDERER_H

class OpenGLRenderer
{
    public:
        //Vertex Array
        void drawPoint(float x, float y);
        void drawLine(float x1, float y1, float x2, float y2);
        void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
        void drawCircle(float x, float y, float aRadius, bool aIsFilled = true, int aLineSegments = 36);
        void drawRectangle(float x, float y, float aWidth, float aHeight, bool aIsFilled = true);

        void drawPolygon(int aRenderMode, float * aVertices, int aVertexSize, int aVertexCount);
        void drawPolygon(int aRenderMode, float * aVertices, int aVertexSize, int aVertexCount, float * aColors, int aColorSize);
    private:

};

#endif