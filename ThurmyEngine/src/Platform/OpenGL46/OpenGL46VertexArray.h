#pragma once

#include "Graphics/VertexArray.h"

namespace Thurmy
{
	class OpenGL46VertexArray : public VertexArray
	{
	public:
		OpenGL46VertexArray();
		~OpenGL46VertexArray() override;

		void Use() override;
		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vb, const VertexBufferLayout& layout) override;
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ib) override;
	};
}