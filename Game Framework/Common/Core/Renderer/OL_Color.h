#ifndef OL_COLOR_H
#define OL_COLOR_H

namespace OnLooker
{
    class Color
    {
    public:
        Color();
        Color(float aRed, float aGreen, float aBlue);
        Color(float aRed, float aGreen, float aBlue, float aAlpha);
        ~Color();

        float red;
        float green;
        float blue;
        float alpha;
    };
    namespace Colors
    {

        static inline Color setRGBA(float aRed, float aGreen, float aBlue, float aAlpha)
        {
            return Color(aRed,aGreen,aBlue,aAlpha);
        }
        static inline Color setRGB(float aRed, float aGreen, float aBlue)
        {
            return Color(aRed, aGreen, aBlue, 1.0f);
        }
        static inline Color setRGBANonNormalizedToNormalized(float aRed, float aGreen, float aBlue, float aAlpha)
        {
            return Color(aRed/255.0f,aGreen/255.0f,aBlue/255.0f,aAlpha/255.0f);
        }
		//(127.0f,255.0f,212.0f)
		//0.49, 1, 0.83
        static inline Color setRGBNonNormalizedToNormalized(float aRed, float aGreen, float aBlue)
        {
            return Color(aRed/255.0f,aGreen/255.0f,aBlue/255.0f,1.0f);
        }

        static inline Color black()
        {
            return setRGB(0.0f,0.0f,0.0f);
        }
        static inline Color gray()
        {
            return setRGB(0.5f,0.5f,0.5f);
        }
        static inline Color white()
        {
            return setRGB(1.0f,1.0f,1.0f);
        }

        static inline Color red()
        {
            return setRGB(1.0f,0.0f,0.0f);
        }
        static inline Color yellow()
        {
            return setRGB(1.0f,1.0f,0.0f);
        }
        static inline Color tomato()
        {
            return setRGBNonNormalizedToNormalized(255.0f,99.0f,71.0f);
        }
        static inline Color orange()
        {
            return setRGBNonNormalizedToNormalized(255.0f,97.0f,3.0f);
        }
        
        
        
        //Pink
        static inline Color pink()
        {
            return setRGBNonNormalizedToNormalized(255.0f,192.0f,203.0f);
        }
        static inline Color lightPink()
        {
            return setRGBNonNormalizedToNormalized(255.0f,174.0f,185.0f);
        }
        static inline Color hotPink()
        {
            return setRGBNonNormalizedToNormalized(255.0f,105.0f,180.0f);
        }
        //Purple
        static inline Color indigo()
        {
            return setRGBNonNormalizedToNormalized(75.0f,0.0f,130.0f);
        }
        static inline Color purple()
        {
            return setRGBNonNormalizedToNormalized(145.0f,44.0f,238.0f);
        }
        static inline Color magenta()
        {
            return setRGB(1.0f,0.0f,1.0f);
        }
        //Blue
        static inline Color royalBlue()
        {
            return setRGBNonNormalizedToNormalized(65.0f,105.0f,225.0f);
        }
        static inline Color blue()
        {
            return setRGBNonNormalizedToNormalized(0.0f,0.0f,255.0f);
        }
        static inline Color cornflowerBlue()
        {
            return setRGBNonNormalizedToNormalized(100,149.0f,237.0f);
        }
        //Turquoise
        static inline Color cyan()
        {
            return setRGBNonNormalizedToNormalized(0.0f,255.0f,255.0f);
        }
        static inline Color turquoise()
        {
            return setRGBNonNormalizedToNormalized(0.0f,197.0f,205.0f);
        }
        static inline Color aquamarine()
        {
            return setRGBNonNormalizedToNormalized(127.0f,255.0f,212.0f);
        }
        //Green
        static inline Color green()
        {
            return setRGB(0.0f,1.0f,0.0f);
        }
        static inline Color seaGreen()
        {
            return setRGBNonNormalizedToNormalized(84.0f,255.0f,159.0f);
        }
        static inline Color cobaltGreen()
        {
            return setRGBNonNormalizedToNormalized(61.0f,145.0f,64.0f);
        }
    }



}

#endif