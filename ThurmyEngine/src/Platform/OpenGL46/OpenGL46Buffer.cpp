#include "OpenGL46Buffer.h"

#include <glad/glad.h>

namespace Thurmy
{
	OpenGL46VertexBuffer::OpenGL46VertexBuffer(void* data, uint32_t size)
	{
		glCreateBuffers(1, &m_Id);
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	OpenGL46VertexBuffer::OpenGL46VertexBuffer(uint32_t size)
	{
		glCreateBuffers(1, &m_Id);
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}

	OpenGL46VertexBuffer::~OpenGL46VertexBuffer()
	{
		glDeleteBuffers(1, &m_Id);
	}

	void OpenGL46VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
	}

	void OpenGL46VertexBuffer::SetData(void* data, uint32_t size)
	{
		Bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	/////////////////////////////////////////////////////
	/////////////////    INDEX BUFFER	/////////////////
	/////////////////////////////////////////////////////


	OpenGL46IndexBuffer::OpenGL46IndexBuffer(void* data, uint32_t size)
	{
		glCreateBuffers(1, &m_Id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	OpenGL46IndexBuffer::OpenGL46IndexBuffer(uint32_t size)
	{
		glCreateBuffers(1, &m_Id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}

	OpenGL46IndexBuffer::~OpenGL46IndexBuffer()
	{
		glDeleteBuffers(1, &m_Id);
	}

	void OpenGL46IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
	}

	void OpenGL46IndexBuffer::SetData(void* data, uint32_t size)
	{
		Bind();
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, data);
	}

}