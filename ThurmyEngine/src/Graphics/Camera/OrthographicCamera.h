#pragma once

#include "Camera.h"

#include <functional>

namespace Thurmy
{
	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(int width, int height, float zoom);

		void SetZoom(float newZoom);
		void SetPosition(const glm::vec3& position);
		void SetViewport(int width, int height);

		inline const glm::mat4 GetViewProjMatrix() const override { return m_ProjectionMatrix * m_ViewMatrix; }
		inline const glm::vec3& GetPosition() { return m_Position; }
		inline int GetWidth() { return m_Width; }
		inline int GetHeight() { return m_Width; }
		inline std::pair<int, int> GetViewportSize() { return std::make_pair(m_Width, m_Height); }

	private:
		void RecalculateViewMatrix();
		void RecalculateProjectionMatrix();
			
	private:
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;
		glm::vec3 m_Position;

		int m_Width, m_Height;
		float m_ZoomSize;
	};
}