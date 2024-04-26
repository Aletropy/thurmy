#pragma once

#include <glm/glm.hpp>

namespace Thurmy
{
	class QuadBatch
	{
	public:
		QuadBatch() = delete;
		QuadBatch(const QuadBatch&) = delete;

		static void Initialize();
		static void Begin();
		static void Push(const glm::vec3& pos, const glm::vec3& size, const glm::vec4& color = glm::vec4(1.0f));
		static void End();

	private:
		static void Flush();
		static void NextBatch();
	};
}