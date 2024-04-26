#pragma once

#include "Graphics/DefaultBuffer.h"

namespace Thurmy
{
	class OpenGL46VertexBuffer : public VertexBuffer
	{
	public:
		OpenGL46VertexBuffer(void* data, uint32_t size);
		OpenGL46VertexBuffer(uint32_t size);

		~OpenGL46VertexBuffer() override;

		void Bind() override;
		void SetData(void* data, uint32_t size) override;
	};

	class OpenGL46IndexBuffer : public IndexBuffer
	{
	public:
		OpenGL46IndexBuffer(void* data, uint32_t size);
		OpenGL46IndexBuffer(uint32_t size);

		~OpenGL46IndexBuffer() override;

		void Bind() override;
		void SetData(void* data, uint32_t size) override;
	};
}