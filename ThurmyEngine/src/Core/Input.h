#pragma once

#include "KeyCodes.h"
#include "functional"

namespace Thurmy
{
	class Input
	{
	public:
		Input() = delete;
		Input(const Input&&) = delete;

		static bool IsKeyDown(Keys key);
		static float GetMouseX();
		static float GetMouseY();
		static std::pair<float, float> GetMousePos();
	};
}