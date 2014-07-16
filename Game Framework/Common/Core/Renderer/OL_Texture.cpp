#include "OL_Texture.h"
#include "../../Utilities/OL_Utilities.h"
using namespace std;

namespace OnLooker
{
    Texture::Texture()
    {
        m_ID = 0;
        m_FileWidth = 0;
        m_FileHeight = 0;
    }
    Texture::~Texture()
    {
        glDeleteTextures(1,&m_ID);
    }


    unsigned int Texture::getID()
    {
        return m_ID;
    }
    unsigned int Texture::getFileWidth()
    {
        return m_FileWidth;
    }
    unsigned int Texture::getFileHeight()
    {
        return m_FileHeight;
    }

    string Texture::getFilename()
    {
        return m_Filename;
    }
    string Texture::getTextureName()
    {
        return m_TextureName;
    }
    unsigned int Texture::getSourceWidth()
    {
        return m_SourceWidth;
    }
    unsigned int Texture::getSourceHeight()
    {
        return m_SourceHeight;
    }
    unsigned int Texture::getSourceX()
    {
        return m_SourceX;
    }
    unsigned int Texture::getSourceY()
    {
        return m_SourceY;
    }
    float Texture::getMinU()
    {
        return m_MinU;
    }
    float Texture::getMinV()
    {
        return m_MinV;
    }
    float Texture::getMaxU()
    {
        return m_MaxU;
    }
    float Texture::getMaxV()
    {
        return m_MaxV;
    }


}