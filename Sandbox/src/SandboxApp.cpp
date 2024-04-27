#include "Thurmy.h"

#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

using namespace Thurmy;

template <typename T>
using Ref = std::shared_ptr<T>;

int main()
{
    Window window(1280, 720, "Sandbox Window");

    OrthographicCamera camera(1280, 720, 15.0f);

    while (!window.ShouldClose())
    {
        window.PollEvents();
        Renderer::ClearColor(0.8f, 0.4f, 0.35f);

        QuadBatch::SetCamera(camera);

        window.SwapBuffers();
    }

    return 0;
}