#pragma once

#include "VertexArray.h"

namespace Thurmy
{
	class Renderer
	{
	public:
		Renderer() = delete;
		Renderer(const Renderer&) = delete;

		static void Initialize();

		static void DrawVA(const std::shared_ptr<VertexArray>& va, uint32_t indicesCount);
		static void ClearColor(float r, float g, float b, float a = 1.0f);
	};
}