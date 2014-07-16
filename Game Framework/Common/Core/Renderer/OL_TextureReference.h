#ifndef OL_TEXTURE_REFERENCE_H
#define OL_TEXTURE_REFERENCE_H

#include <string>


namespace OnLooker
{
    class Texture;
    class TextureReference
    {
    public:
        TextureReference();
        ~TextureReference();
        bool load(std::string aFilename, int aUnit = 0, bool aUseUnit = false);
        std::string getName();

        void addReference();
        void removeReference();
        int getReferenceCount();
        
        Texture * m_Texture;
    private:
        int m_Count;

    };
}

#endif