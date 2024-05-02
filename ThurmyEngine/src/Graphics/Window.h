#pragma once

#include <string>

struct GLFWwindow;

namespace Thurmy
{
	struct WindowProps
	{
	public:
		float Width = 800;
		float Height = 600;
		bool AllowResize = true;
	};

	class Window
	{
	public:
		Window(int width, int height, const std::string& title);
		~Window();

		void PollEvents();
		void SwapBuffers();
		bool ShouldClose();

		void SetVSync(bool enable);

		inline void* GetNativeHandler() const { return m_Handler; }

	private:
		GLFWwindow* m_Handler;
	};
}