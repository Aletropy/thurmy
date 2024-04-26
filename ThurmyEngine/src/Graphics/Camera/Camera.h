#pragma once

#include <glm/glm.hpp>

namespace Thurmy
{
	class Camera
	{
	public:
		virtual inline const glm::mat4 GetViewProjMatrix() const = 0;
	};
}