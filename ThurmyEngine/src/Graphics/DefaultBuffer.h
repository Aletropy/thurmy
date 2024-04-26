#pragma once

#include <stdint.h>
#include <memory>

namespace Thurmy
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void SetData(void* data, uint32_t size) = 0;

		static std::shared_ptr<VertexBuffer> Create(void* data, uint32_t size);
		static std::shared_ptr<VertexBuffer> Create(uint32_t size);

	protected:
		uint32_t m_Id;
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;
		virtual void SetData(void* data, uint32_t size) = 0;

		static std::shared_ptr<IndexBuffer> Create(void* data, uint32_t size);
		static std::shared_ptr<IndexBuffer> Create(uint32_t size);

	protected:
		uint32_t m_Id;
	};
}