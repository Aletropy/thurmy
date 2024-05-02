#include "Window.h"

#include <GLFW/glfw3.h>
#include "Core/Logger.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "Core/Application.h"

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

		glfwSetKeyCallback(m_Handler, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS)
				{
					KeyPressEvent event(key);
					Application::Instance->OnEvent(event);
				}
				else if (action == GLFW_RELEASE)
				{
					KeyReleaseEvent event(key);
					Application::Instance->OnEvent(event);
				}
			});

		SetVSync(true);

		// Initialize ImGui
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

		ImGui_ImplGlfw_InitForOpenGL(m_Handler, true);
		ImGui_ImplOpenGL3_Init();
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Handler);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::SwapBuffers()
	{
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