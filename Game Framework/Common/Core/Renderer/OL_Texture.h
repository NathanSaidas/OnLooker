#ifndef OL_TEXTURE_H
#define OL_TEXTURE_H

#include <string>
#include "../../Libraries/OL_OpenGL.h"
#include "OL_Color.h"



namespace OnLooker
{

    class TextureReference;

    class Texture
    {
    public:
        Texture();
        ~Texture();

        unsigned int getID();
        unsigned int getFileWidth();
        unsigned int getFileHeight();

        std::string getFilename();
        std::string getTextureName();


        unsigned int getSourceWidth();
        unsigned int getSourceHeight();
        unsigned int getSourceX();
        unsigned int getSourceY();
        float getMinU();
        float getMinV();
        float getMaxU();
        float getMaxV();


    private:
        unsigned int m_ID;
        unsigned int m_FileWidth;
        unsigned int m_FileHeight;
        std::string m_Filename;
        std::string m_TextureName;

        unsigned int m_SourceWidth;
        unsigned int m_SourceHeight;
        unsigned int m_SourceX;
        unsigned int m_SourceY;


        float m_MinU;
        float m_MinV;
        float m_MaxU;
        float m_MaxV;

        friend TextureReference;
    };
}

#endif