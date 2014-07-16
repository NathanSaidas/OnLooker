uniform sampler2D u_Texture1;
uniform sampler2D u_Texture2;

uniform vec2 u_TexOffset;
varying vec2 v_TexCoords;

void main()
{

	vec4 color1 = texture2D(u_Texture1, v_TexCoords); //test
	vec4 color2 = texture2D(u_Texture2, v_TexCoords); //awesome

	//if(color2.a < 0.5)
	//{
	//	gl_FragColor = color1;
	//}
	//else
	//{
	//	gl_FragColor = color2;
	//}

	gl_FragColor = color1;
	gl_FragColor = color2;

	//clamp(perc-0.7)*5, 0, 1);
	//color2 * perc +color1 * (1-perc);

	
	
	
	
}