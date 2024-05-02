#include "Core/Logger.h"

#include "Application.h"
#include "Graphics/Renderer.h"
#include "Graphics/QuadBatch.h"

namespace Thurmy
{
	Application* Application::Instance = nullptr;
	Application::Application(const std::string& applicationName, const WindowProps& props)
		: m_Window((int)props.Width, (int)props.Height, applicationName)
	{
		THURMY_ASSERT(Instance != nullptr, "Application instance already exists. Overriding it.");
		Instance = this;

		Renderer::Initialize();
		QuadBatch::Initialize();
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (!m_Window.ShouldClose())
		{
			m_Window.PollEvents();

			float deltaTime = Time::CalculateDeltaTime();

			Renderer::Clear();
			this->OnUpdate(deltaTime);

			m_Window.SwapBuffers();
		}
	}
}