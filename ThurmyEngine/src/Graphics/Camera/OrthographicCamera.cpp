#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Thurmy
{
	OrthographicCamera::OrthographicCamera(int width, int height, float zoom)
		: m_Width(width), m_Height(height), m_ZoomSize(zoom)
	{
		float aspectRatio = (float)width / (float)height;

		m_ViewMatrix = glm::mat4(1.0f);
		m_ProjectionMatrix = glm::ortho(-aspectRatio * zoom, aspectRatio * zoom, -zoom, zoom);
	}

	void OrthographicCamera::SetZoom(float newZoom)
	{
		m_ZoomSize = newZoom;
		RecalculateProjectionMatrix();
	}

	void OrthographicCamera::SetPosition(const glm::vec3& position)
	{
		m_Position = position;
		RecalculateViewMatrix();
	}

	void OrthographicCamera::SetViewport(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		RecalculateProjectionMatrix();
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position);
	}

	void OrthographicCamera::RecalculateProjectionMatrix()
	{
		float aspectRatio = (float)m_Width / (float)m_Height;
		float zoom = m_ZoomSize;
		
		m_ProjectionMatrix = glm::ortho(-aspectRatio * zoom, aspectRatio * zoom, -zoom, zoom);
	}
}
