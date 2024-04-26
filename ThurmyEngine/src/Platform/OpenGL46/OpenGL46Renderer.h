#pragma once
#include "Graphics/Renderer.h"

namespace Thurmy
{
	class OpenGL46Renderer
	{
	public:
		OpenGL46Renderer() = delete;
		OpenGL46Renderer(const OpenGL46Renderer&) = delete;

		static void Initialize();
		static void DrawVA(const std::shared_ptr<VertexArray>& va, uint32_t indicesCount);
		static void ClearColor(float r, float g, float b, float a = 1.0f);
	};
}