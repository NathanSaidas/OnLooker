uniform sampler2D u_Texture1;
uniform sampler2D u_Texture2;
uniform sampler2D u_Mask;

uniform vec2 u_TexOffset;

varying vec4 v_Color;
varying vec2 v_TexCoords;

uniform vec3 u_Tint;

void main()
{

	vec4 color1 = texture2D(u_Texture1, v_TexCoords); //test
	vec4 color2 = texture2D(u_Texture2, v_TexCoords); //awesome
	vec4 colorMask = texture2D(u_Mask , v_TexCoords); //color mask

	float percentage = 0.01; // use time

	vec4 outcolor;
	if(colorMask.r < percentage)
	{
		outcolor = color1;
	}
	else
	{
		discard;//outcolor = color2;
	}

	gl_FragColor = outcolor;


	//gl_FragColor = color1 * colorMask + color2 * (1-colorMask);
	//clamp(perc-0.7)*5, 0, 1);
	//color2 * perc +color1 * (1-perc);

	
	
	
	
}