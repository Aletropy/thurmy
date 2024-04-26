#pragma once

#include "Graphics/Shader.h"

namespace Thurmy
{
	class OpenGL46Shader : public Shader
	{
	public:
		OpenGL46Shader(const std::string& vertexPath, const std::string& fragmentPath);
		~OpenGL46Shader();

		void Use() override;

	private:
		uint32_t CompileShader(const char* source, uint32_t type);
	};
}