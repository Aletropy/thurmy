#include "OpenGL46Renderer.h"
#include "Core/Logger.h"

#include "glad/glad.h"

namespace Thurmy
{
	static bool s_Initialized = false;
	void OpenGL46Renderer::Initialize()
	{
		if (!s_Initialized)
		{

			THURMY_ASSERT(!gladLoadGL(), "Glad cannot be initialized.");

			THURMY_LOG("OpenGL Version: %s", glGetString(GL_VERSION));

			s_Initialized = true;
			return;
		}

		THURMY_LOG("OpenGL 4.6 is already initialized.");
	}

	void OpenGL46Renderer::DrawVA(const std::shared_ptr<VertexArray>& va, uint32_t indicesCount)
	{
		va->Use();
		glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
	}

	void OpenGL46Renderer::ClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}