#include "OpenGL46VertexArray.h"

#include <glad/glad.h>

namespace Thurmy
{
	OpenGL46VertexArray::OpenGL46VertexArray()
	{
		glCreateVertexArrays(1, &m_Id);
		glBindVertexArray(m_Id);
	}

	OpenGL46VertexArray::~OpenGL46VertexArray()
	{
		glDeleteVertexArrays(1, &m_Id);
	}

	void OpenGL46VertexArray::Use()
	{
		glBindVertexArray(m_Id);
	}

	void OpenGL46VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vb, const VertexBufferLayout& layout)
	{
		vb->Bind();

		auto& elements = layout.GetElements();

		for (uint32_t i = 0; i < elements.size(); i++)
		{
			auto& element = elements[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, element.Count, element.Type, element.Normalized, layout.GetStride(), (void*)element.Offset);
		}
	}

	void OpenGL46VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ib)
	{
		Use();
		ib->Bind();
	}
}