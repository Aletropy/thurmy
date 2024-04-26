#include "Renderer.h"

// TODO: Switch renderer
#include "Platform/OpenGL46/OpenGL46Renderer.h" // Remove this later ! IMPORTANT !

namespace Thurmy
{
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
		OpenGL46Renderer::ClearColor(r, g, b, a);
	}
}