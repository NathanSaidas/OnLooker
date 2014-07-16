#ifndef OL_SHADER_H
#define OL_SHADER_H

#include <string>

namespace OnLooker
{

    /*
	*   Class: Shader
	*   Base Class: N/A
	*   Description: This class is responsible for holding data for the specified file name of the
	*	vertex and fragment shaders. The class also holds the data for the handles of the vertex and shader
	*	and program handles.
	*   Date Modified: 28/1/2014 by Nathan Hanlan
	*/

	class Shader
	{
	public:
		Shader();
		~Shader();


        bool loadShaderProgram(std::string aShaderProgramName);
		bool loadShaderProgram(std::string aVertexShaderFilename, std::string aFragmentShaderFilename);
		bool useThisShader(bool aLoadShader = false);
		

		std::string getVertexShaderFilename();
		std::string getFragmentShaderFilename();
		unsigned int getVertexShaderHandle();
		unsigned int getFragmentShaderHandle();
		unsigned int getShaderProgramHandle();
		bool getReadyToUse();


		void setVertexShaderFilename(std::string aVertexShaderFilename, bool aLoadShader = false);
		void setFragmentShaderFilename(std::string aFragmentShaderFilename, bool aLoadShader = false);
		
		void release();
		

	private:
		unsigned int loadShader(unsigned int type, const char * source);

		std::string m_VertexShaderFilename;
		std::string m_FragmentShaderFilename;
		std::string m_VertexShaderSource;
		std::string m_FragmentShaderSource;
		unsigned int m_VertexShaderHandle;
		unsigned int m_FragmentShaderHandle;
		unsigned int m_ShaderProgramHandle;
		bool m_ReadyToUse;


        std::string m_ShaderProgramName;
	};

}

#endif