#include "OL_VertexAttribute.h"

namespace OnLooker
{
	VertexAttribute::VertexAttribute()
	{

	}

	VertexAttribute::VertexAttribute(float aX, float aY, float aRed, float aGreen, float aBlue, float aAlpha, float aU, float aV)
	{
		position.x = aX;
		position.y = aY;
		color.red = aRed;
		color.green = aGreen;
		color.blue = aBlue;
		color.alpha = aAlpha;
		texCoords.u = aU;
		texCoords.v = aV;
	}

}