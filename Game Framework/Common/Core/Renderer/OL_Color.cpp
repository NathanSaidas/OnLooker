#include "OL_Color.h"


namespace OnLooker
{

    Color::Color()
    {
        red = 0.0f;
        green = 0.0f;
        blue = 0.0f;
        alpha = 1.0f;
    }
    Color::Color(float aRed, float aGreen, float aBlue)
    {
        red = aRed;
        green = aGreen;
        blue = aBlue;
        alpha = aBlue;
    }
    Color::Color(float aRed, float aGreen, float aBlue, float aAlpha)
    {
        red = aRed;
        green = aGreen;
        blue = aBlue;
        alpha = aAlpha;
    }
    Color::~Color()
    {

    }
}