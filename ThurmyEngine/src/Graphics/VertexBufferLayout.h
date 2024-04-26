#pragma once
#include "Core/Logger.h"

#include <vector>
#include <stdint.h>

namespace Thurmy
{
	struct VertexBufferElement
	{
	public:
		uint32_t Count;
		uint32_t Type;
		bool Normalized;
		uint32_t Offset;
	};

	class VertexBufferLayout
	{
	public:
		
		template<typename T>
		void Push(uint32_t count)
		{
			THURMY_ASSERT(true, "Push not support this type.")
		}
		
		template<>
		void Push<float>(uint32_t count)
		{
			m_Elements.push_back({count, 0x1406, false, m_Stride});

			m_Stride += count * sizeof(float);
		}

		inline uint32_t	GetStride() const { return m_Stride; }
		inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }

	private:
		std::vector<VertexBufferElement> m_Elements;
		uint32_t m_Stride = 0;
	};
}