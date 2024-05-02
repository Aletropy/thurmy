#pragma once

#include "Time.h"
#include "Graphics/Window.h"
#include "Events/Event.h"

namespace Thurmy
{
	class Application
	{
	public:
		static Application* Instance;
	public:
		Application(const std::string& applicationName, const WindowProps& props = {});
		~Application();

		void Run();
		virtual void OnUpdate(float deltaTime) { }
		virtual void OnEvent(Event& event) { }

		const Window& GetWindow() const { return m_Window; }

	private:
		Window m_Window;
	};

	Application* GetMainApp();
}