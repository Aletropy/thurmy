#include "QuadBatch.h"

#include "Graphics/VertexArray.h"
#include "Graphics/Shader.h"
#include "Graphics/Renderer.h"

#include <stdint.h>
#include <glm/gtc/matrix_transform.hpp>

template <typename T>
using Ref = std::shared_ptr<T>;

namespace Thurmy
{
	static glm::vec4 QuadVertexPositions[] =
	{
		{ -1.0f, -1.0f, 0.0f, 1.0f },
		{  1.0f, -1.0f, 0.0f, 1.0f },
		{  1.0f,  1.0f, 0.0f, 1.0f },
		{ -1.0f,  1.0f, 0.0f, 1.0f }
	};

	struct Vertex
	{
		glm::vec4 Position;
		glm::vec4 Color;
	};

	struct BatchData
	{
		static const uint32_t MaxQuads = 1000;
		static const uint32_t MaxVertices = MaxQuads * 4;
		static const uint32_t MaxIndices = MaxQuads * 6;

		Vertex* BaseVertexPointer;
		Vertex* CurrentVertexPointer;

		Ref<VertexArray> Va;
		Ref<VertexBuffer> Vb;
		Ref<IndexBuffer> Ib;

		Ref<Shader> Shader;

		uint32_t NumOfIndices = 0;
	};

	static BatchData s_Data;
	void QuadBatch::Initialize()
	{
		s_Data.BaseVertexPointer = new Vertex[BatchData::MaxVertices];
		s_Data.CurrentVertexPointer = s_Data.BaseVertexPointer;

		s_Data.Va = VertexArray::Create();

		s_Data.Vb = VertexBuffer::Create(BatchData::MaxVertices * sizeof(Vertex));
		VertexBufferLayout layout;
		layout.Push<float>(4);
		layout.Push<float>(4);

		uint32_t* indices = new uint32_t[s_Data.MaxIndices];
		uint32_t offset = 0;
		for (uint32_t i = 0; i < BatchData::MaxIndices; i += 6)
		{
			indices[0 + i] = offset + 0;
			indices[1 + i] = offset + 1;
			indices[2 + i] = offset + 2;

			indices[3 + i] = offset + 2;
			indices[4 + i] = offset + 3;
			indices[5 + i] = offset + 0;

			offset += 4;
		}

		s_Data.Ib = IndexBuffer::Create(indices, BatchData::MaxIndices * sizeof(uint32_t));
		s_Data.Va->SetIndexBuffer(s_Data.Ib);

		s_Data.Va->AddVertexBuffer(s_Data.Vb, layout);

		s_Data.Shader = Shader::Create("res/Default.vert", "res/Default.frag");
	}

	void QuadBatch::Begin()
	{
		s_Data.CurrentVertexPointer = s_Data.BaseVertexPointer;
		s_Data.NumOfIndices = 0;
	}

	void QuadBatch::Push(const glm::vec3& pos, const glm::vec3& size, const glm::vec4& color)
	{
		glm::mat4 transform = glm::translate(glm::mat4(), pos);

		if (s_Data.NumOfIndices >= BatchData::MaxIndices)
		{
			NextBatch();
		}

		for (uint32_t i = 0; i < 4; i++)
		{
			s_Data.CurrentVertexPointer->Position = transform * QuadVertexPositions[i];
			s_Data.CurrentVertexPointer->Color = color;

			s_Data.CurrentVertexPointer++;
		}

		s_Data.NumOfIndices += 6;
	}

	void QuadBatch::End()
	{
		Flush();
	}

	void QuadBatch::Flush()
	{
		uint32_t size = (uint32_t)((uint8_t*)s_Data.CurrentVertexPointer - (uint8_t*)s_Data.BaseVertexPointer);

		s_Data.Vb->SetData(s_Data.BaseVertexPointer, size);
		s_Data.Shader->Use();

		Renderer::DrawVA(s_Data.Va, s_Data.NumOfIndices);
	}

	void QuadBatch::NextBatch()
	{
		Flush();
		Begin();
	}
}