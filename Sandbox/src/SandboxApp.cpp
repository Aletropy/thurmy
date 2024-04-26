#include "Thurmy.h"

using namespace Thurmy;

template <typename T>
using Ref = std::shared_ptr<T>;

int main()
{
    Window window(800, 600, "Sandbox Window");

    OrthographicCamera camera(800, 600, 5.0f);

    while (!window.ShouldClose())
    {
        Renderer::ClearColor(0.8f, 0.4f, 0.35f);

        QuadBatch::SetCamera(camera);

        QuadBatch::Begin();
        QuadBatch::Push(glm::vec3(0.0f), glm::vec3(1.0f));
        QuadBatch::End();

        window.Update();
    }

    return 0;
}