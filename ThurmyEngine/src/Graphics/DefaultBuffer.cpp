#include "DefaultBuffer.h"

// TODO: Switch renderer
#include "Platform/OpenGL46/OpenGL46Buffer.h" // Remove this later ! IMPORTANT !

namespace Thurmy
{
	std::shared_ptr<VertexBuffer> VertexBuffer::Create(void* data, uint32_t size)
	{
		return std::make_shared<OpenGL46VertexBuffer>(data, size);
	}

	std::shared_ptr<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		return std::make_shared<OpenGL46VertexBuffer>(size);
	}

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(void* data, uint32_t size)
	{
		return std::make_shared<OpenGL46IndexBuffer>(data, size);
	}

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t size)
	{
		return std::make_shared<OpenGL46IndexBuffer>(size);
	}
}