#pragma once

#include <string>

struct GLFWwindow;

namespace Thurmy
{
	class Window
	{
	public:
		Window(int width, int height, const std::string& title);
		~Window();

		void PollEvents();
		void SwapBuffers();
		bool ShouldClose();

		void SetVSync(bool enable);

		inline void* GetNativeHandler() { return m_Handler; }

	private:
		GLFWwindow* m_Handler;
	};
}