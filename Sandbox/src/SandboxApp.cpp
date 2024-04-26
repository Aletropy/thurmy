#include "Thurmy.h"

using namespace Thurmy;

template <typename T>
using Ref = std::shared_ptr<T>;

int main()
{
    Window window(800, 600, "Sandbox Window");

    Renderer::Initialize();
    QuadBatch::Initialize();

    while (!window.ShouldClose())
    {
        Renderer::ClearColor(0.8f, 0.4f, 0.35f);

        QuadBatch::Begin();
        QuadBatch::Push({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f });
        QuadBatch::End();

        window.Update();
    }

    return 0;
}