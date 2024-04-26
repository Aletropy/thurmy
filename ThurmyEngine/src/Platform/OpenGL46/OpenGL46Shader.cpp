#include "OpenGL46Shader.h"
#include "Core/Logger.h"

#include <glad/glad.h>

namespace Thurmy
{
	OpenGL46Shader::OpenGL46Shader(const std::string& vp, const std::string& fp)
	{
		uint32_t vs = CompileShader(ReadFile(vp).c_str(), GL_VERTEX_SHADER);
		uint32_t fs = CompileShader(ReadFile(fp).c_str(), GL_FRAGMENT_SHADER);

		m_Id = glCreateProgram();
		glAttachShader(m_Id, vs);
		glAttachShader(m_Id, fs);
		
		glLinkProgram(m_Id);

		int success;
		glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
		if (!success)
		{
			char msg[2048];
			glGetProgramInfoLog(m_Id, 2048, nullptr, msg);
			THURMY_LOG("Error: %s", msg);
		}

		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	OpenGL46Shader::~OpenGL46Shader()
	{
		glDeleteProgram(m_Id);
	}

	void OpenGL46Shader::Use()
	{
		glUseProgram(m_Id);
	}

	void OpenGL46Shader::SetMat4f(const std::string& name, float* values)
	{
		int location = glGetUniformLocation(m_Id, name.c_str());
		glUniformMatrix4fv(location, 1, false, values);
	}

	uint32_t OpenGL46Shader::CompileShader(const char* source, uint32_t type)
	{
		uint32_t id = glCreateShader(type);

		glShaderSource(id, 1, &source, nullptr);
		glCompileShader(id);

		int success;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char msg[2048];
			glGetShaderInfoLog(id, 2048, nullptr, msg);
			THURMY_LOG("Error: %s", msg);
			return 0;
		}

		return id;
	}
}