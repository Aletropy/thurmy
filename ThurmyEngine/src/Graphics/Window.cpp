#include "Window.h"
#include <GLFW/glfw3.h>
#include "Core/Logger.h"

namespace Thurmy
{
	static bool s_glfwInitialized = false;

	Window::Window(int width, int height, const std::string& title)
	{
		if (!s_glfwInitialized)
		{
			THURMY_ASSERT(!glfwInit(), "Glfw could not be initialized!");
			s_glfwInitialized = true;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Handler = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Handler);
		
		SetVSync(true);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Handler);
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Handler);
	}

	void Window::SetVSync(bool enable)
	{
		glfwSwapInterval(enable ? 1 : 0);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_Handler);
	}

}