#include "Renderer.h"

// TODO: Switch renderer
#include "Platform/OpenGL46/OpenGL46Renderer.h" // Remove this later ! IMPORTANT !

namespace Thurmy
{
	static glm::vec4 s_ClearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	void Renderer::Initialize()
	{
		OpenGL46Renderer::Initialize();
	}

	void Renderer::DrawVA(const std::shared_ptr<VertexArray>& va, uint32_t indicesCount)
	{
		OpenGL46Renderer::DrawVA(va, indicesCount);
	}

	void Renderer::ClearColor(float r, float g, float b, float a)
	{
		s_ClearColor = { r, g, b, a };
	}

	void Renderer::ClearColor(const glm::vec4& color)
	{
		s_ClearColor = color;
	}

	void Renderer::Clear()
	{
		OpenGL46Renderer::ClearColor(s_ClearColor.r, s_ClearColor.g, s_ClearColor.b, s_ClearColor.a);
	}
}