#ifndef OL_VERTEX_ATTRIBUTE_H
#define OL_VERTEX_ATTRIBUTE_H

namespace OnLooker
{
    
    struct VertexAttribute
    {
        struct Color
        {
            float red;
            float green;
            float blue;
            float alpha;
        };
        struct Position
        {
            float x;
            float y;
        };
        struct TexCoord
        {
            float u;
            float v;
        };
		
        Position position;
        Color color;
        TexCoord texCoords;

		VertexAttribute();
		VertexAttribute(float aX, float aY, float aRed, float aGreen, float aBlue, float aAlpha, float aU, float aV);
		/*{
			m_Position.x = aX;
			m_Position.y = aY;
			m_Color.red = aRed;
			m_Color.green = aGreen;
			m_Color.blue = aBlue;
			m_Color.alpha = aAlpha;
			m_TexCoords.u = aU;
			m_TexCoords.v = aV;
		}*/
        
    };

}

#endif