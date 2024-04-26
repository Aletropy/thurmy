#pragma once

#include "DefaultBuffer.h"
#include "VertexBufferLayout.h"
#include <memory>

namespace Thurmy
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Use() = 0;
		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vb, const VertexBufferLayout& layout) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ib) = 0;

		static std::shared_ptr<VertexArray> Create();
	protected:
		uint32_t m_Id;
	};
}