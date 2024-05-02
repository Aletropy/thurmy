#include "Time.h"

#include <chrono>
#include <GLFW/glfw3.h>

namespace Thurmy
{
    static double s_DeltaTime = 0.0f;
    static double s_LastTime = 0.0f;

    inline float Time::GetDeltaTime()
    {
        (float)s_DeltaTime;
    }

    float Time::CalculateDeltaTime()
    {
        double now = glfwGetTime();
        double deltaTime = now - s_LastTime;
        s_LastTime = now;

        s_DeltaTime = deltaTime;

        return (float)deltaTime;
    }
}
