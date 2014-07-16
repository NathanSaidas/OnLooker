#ifndef OL_MESH_H
#define OL_MESH_H

#include "OL_Color.h"

namespace OnLooker
{
    struct VertexAttribute;

    class Mesh
    {
    public:
        Mesh();
        ~Mesh();

        unsigned int getVBO();
        unsigned int getIBO();
        unsigned int getShaderHandle();
        unsigned int getTextureHandle();

        float getOffsetX();
        float getOffsetY();
        float getRotation();
        Color getColor();

        void setOffsetX(float x);
        void setOffsetY(float y);
        void setRotation(float rotation);
        void setColor(float aRed, float aGreen, float aBlue, float aAlpha);

    private:
        unsigned int m_VBO;
        unsigned int m_IBO;
        //Get Handles from Texture Manager Class
        unsigned int m_ShaderHandle;
        unsigned int m_TextureHandle;
        float m_OffsetX;
        float m_OffsetY;
        float m_Rotation;
        Color m_Tint;
        
        
        
    };

};

#endif