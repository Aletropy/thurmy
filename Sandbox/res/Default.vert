#version 460

layout(location = 0) in vec4 a_Position;
layout(location = 1) in vec4 a_Color;

layout(location = 0) out vec4 v_Color;

uniform mat4 u_ViewProjMatrix;

void main()
{
	gl_Position = u_ViewProjMatrix * a_Position;
	v_Color = a_Color;
}