#include <Thurmy.h>
#include <Core/EntryPoint.h>

#include "PlayerInput.h"

using namespace Thurmy;

class SandboxApp : public Application
{
public:
	SandboxApp()
		: Application("Sandbox Application"), m_Camera(800, 600, 5.0f)
	{
		Renderer::ClearColor(0.8f, 0.65f, 0.45f);
		QuadBatch::SetCamera(m_Camera);
	}

	void OnUpdate(float deltaTime) override
	{
		auto axis = PlayerInput::GetMoveAxis();

		auto move = (axis * deltaTime) * 5.0f;

		quadPos = quadPos += glm::vec3(move.x, move.y, 0.0f);

		QuadBatch::Begin();
		QuadBatch::Push(quadPos, glm::vec3(1.0f));
		QuadBatch::End();
	}

private:
	glm::vec3 quadPos = glm::vec3(0.0f);
	OrthographicCamera m_Camera;
};

Application* Thurmy::GetMainApp()
{
	return new SandboxApp;
}
