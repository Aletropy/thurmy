#include "PlayerInput.h"

using namespace Thurmy;

glm::vec2 PlayerInput::GetMoveAxis()
{
    auto w = Input::IsKeyDown(Keys::KEY_W);
    auto a = Input::IsKeyDown(Keys::KEY_A);
    auto s = Input::IsKeyDown(Keys::KEY_S);
    auto d = Input::IsKeyDown(Keys::KEY_D);

    glm::vec2 axis = glm::vec2(0.0f);

    if (w && s)
        axis.y = 0.0f;
    else if (w)
        axis.y = 1.0f;
    else if (s)
        axis.y = -1.0f;

    if (d && a)
        axis.x = 0.0f;
    else if (d)
        axis.x = 1.0f;
    else if (a)
        axis.x = -1.0f;

    if (axis == glm::vec2(0.0f))
    {
        return axis;
    }
    else return glm::normalize(axis);
}