#pragma once

#include <Thurmy.h>

class PlayerInput
{
public:
	PlayerInput() = delete;
	PlayerInput(const PlayerInput&&) = delete;

	static glm::vec2 GetMoveAxis();
};