#pragma once

#include <string>
#include <memory>
#include <stdint.h>

namespace Thurmy
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Use() = 0;

		static std::shared_ptr<Shader> Create(const std::string& vertexPath, const std::string& fragmentPath);

	protected:

		static std::string ReadFile(const std::string& filepath);

	protected:
		uint32_t m_Id;
	};
}