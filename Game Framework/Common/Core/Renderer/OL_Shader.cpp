#include "OL_Shader.h"
#include "OL_Renderer.h"
#include "../../Utilities/OL_Utilities.h"

using namespace std;

namespace OnLooker
{

    Shader::Shader()
	{
		m_VertexShaderHandle = 0;
		m_FragmentShaderHandle = 0;
		m_ShaderProgramHandle = 0;
		//m_VertexShaderSource;
		//m_FragmentShaderSource;
		
		m_ReadyToUse = false;
	}
	Shader::~Shader()
	{
		release();
	}

    bool Shader::loadShaderProgram(string aShaderProgramName)
    {
		string vertexShaderFilename = FilePath::getInstance()->convertPathForShaders(aShaderProgramName);
		string fragmentShaderFilename = FilePath::getInstance()->convertPathForShaders(aShaderProgramName);
        
        //vertexShaderFilename.append(aShaderProgramName);
        vertexShaderFilename.append(".vert");
        
        //fragmentShaderFilename.append(aShaderProgramName);
        fragmentShaderFilename.append(".frag");


        return loadShaderProgram(vertexShaderFilename,fragmentShaderFilename);
    }

	bool Shader::loadShaderProgram(std::string vertexShaderFilename, std::string fragmentShaderFilename)
	{
		//Create Shader x2
        
		//Create Program
		m_ShaderProgramHandle = glCreateProgram();

		//Get Source
		m_VertexShaderSource = loadCompleteFile(vertexShaderFilename.c_str());
		m_FragmentShaderSource = loadCompleteFile(fragmentShaderFilename.c_str());

        m_VertexShaderHandle = loadShader(GL_VERTEX_SHADER,m_VertexShaderSource.c_str());
        m_FragmentShaderHandle = loadShader(GL_FRAGMENT_SHADER,m_FragmentShaderSource.c_str());

		//attach
		glAttachShader(m_ShaderProgramHandle,m_VertexShaderHandle);
		glAttachShader(m_ShaderProgramHandle,m_FragmentShaderHandle);
		//link
		glLinkProgram(m_ShaderProgramHandle);

		int programStatus = 0;
		glGetProgramiv(m_ShaderProgramHandle,GL_LINK_STATUS,&programStatus);

		if(programStatus != GL_TRUE)
		{
			int logLength = 0;
			glGetProgramiv(m_ShaderProgramHandle,GL_INFO_LOG_LENGTH, &logLength);
			
			char * log = new char [logLength];

			glGetProgramInfoLog(m_ShaderProgramHandle,1,0,log);


            Debug::console->outputFormat(log);

			delete[] log;
			m_ReadyToUse = false;

			//Delete shaders
			release();

		}
		else
		{
			m_ReadyToUse = true;
		}
		return m_ReadyToUse;
	}
	bool Shader::useThisShader(bool aLoadShader)
	{
		if(m_ReadyToUse == true)
		{
			glUseProgram(m_ShaderProgramHandle);
			return true;
		}
		else if(m_ReadyToUse == false && aLoadShader == true)
		{
			loadShaderProgram(m_VertexShaderFilename,m_FragmentShaderFilename);
			useThisShader();
		}
		else if(m_ReadyToUse == false)
		{
			return false;
		}
	}

	std::string Shader::getVertexShaderFilename()
	{
		return m_VertexShaderFilename;
	}
	std::string Shader::getFragmentShaderFilename()
	{
		return m_FragmentShaderFilename;
	}
	unsigned int Shader::getVertexShaderHandle()
	{
		return m_VertexShaderHandle;
	}
	unsigned int Shader::getFragmentShaderHandle()
	{
		return m_FragmentShaderHandle;
	}
	unsigned int Shader::getShaderProgramHandle()
	{
		return m_ShaderProgramHandle;
	}
	bool Shader::getReadyToUse()
	{
		return m_ReadyToUse;
	}


	void Shader::setVertexShaderFilename(std::string aVertexShaderFilename, bool aLoadShader)
	{
		m_VertexShaderFilename = aVertexShaderFilename;
		if(aLoadShader == true)
		{
			loadShaderProgram(m_VertexShaderFilename,m_FragmentShaderFilename);
		}
	}
	void Shader::setFragmentShaderFilename(std::string aFragmentShaderFilename, bool aLoadShader)
	{
		m_FragmentShaderFilename = aFragmentShaderFilename;
		if(aLoadShader == true)
		{
			loadShaderProgram(m_VertexShaderFilename,m_FragmentShaderFilename);
		}
	}
	
	void Shader::release()
	{
		glDetachShader(m_ShaderProgramHandle,m_VertexShaderHandle);
		glDetachShader(m_ShaderProgramHandle,m_FragmentShaderHandle);

		glDeleteShader(m_VertexShaderHandle);
		glDeleteShader(m_FragmentShaderHandle);
		glDeleteProgram(m_ShaderProgramHandle);
	}

	unsigned int Shader::loadShader(unsigned int type, const char * source)
	{
		unsigned int handle = glCreateShader(type);

		glShaderSource(handle,1,&source,NULL);
		glCompileShader(handle);


		//check if the program compiled
		int compileStatus = 0;
		glGetShaderiv(handle,GL_COMPILE_STATUS,&compileStatus);


		//if it didnt
		if(compileStatus != GL_TRUE)
		{
			//get the log
			int logLength = 0;
			glGetShaderiv(handle,GL_INFO_LOG_LENGTH,&logLength);

			char * infoLog = new char[logLength];

			glGetShaderInfoLog(handle,logLength,0,infoLog);

            Debug::console->outputFormat(infoLog);
			
			delete[] infoLog;

		}
		return handle;
	}
}