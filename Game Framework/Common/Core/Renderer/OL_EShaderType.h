#ifndef OL_ESHADER_TYPE_H
#define OL_ESHADER_TYPE_H

namespace OnLooker
{
	enum EShaderType
	{
		SHADER_BASIC, //position / color attributes
		SHADER_TRANSFORM, //(basic) adds uniforms for position offset and color tint and time and rotation
		SHADER_TEXTURE,//(transform)[-color attributes] adds uniform for one texture and tex coords
		SHADER_TWO_TEXTURE//(texture)adds texture
	};

}

#endif