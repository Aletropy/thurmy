#include "Input.h"
#include "Core/Application.h"
#include <GLFW/glfw3.h>

namespace Thurmy
{
	bool Input::IsKeyDown(Keys key)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Instance->GetWindow().GetNativeHandler();
		return glfwGetKey(window, (int)key) == GLFW_PRESS ? true : false;
	}

	float Input::GetMouseX()
	{
		auto [x, y] = GetMousePos();
		return x;
	}

	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePos();
		return y;
	}

	std::pair<float, float> Input::GetMousePos()
	{
		GLFWwindow* window = (GLFWwindow*)Application::Instance->GetWindow().GetNativeHandler();
		double mouseX;
		double mouseY;

		glfwGetCursorPos(window, &mouseX, &mouseY);

		return std::make_pair((float)mouseX, (float)mouseY);
	}
}