#include "VertexArray.h"

#include "Platform/OpenGL46/OpenGL46VertexArray.h"

namespace Thurmy
{
    std::shared_ptr<VertexArray> VertexArray::Create()
    {
        return std::make_shared<OpenGL46VertexArray>();
    }
}
