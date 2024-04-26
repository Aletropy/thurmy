#version 460

layout(location = 0) in vec4 a_Position;
layout(location = 1) in vec4 a_Color;

layout(location = 0) out vec4 v_Color;

void main()
{
	gl_Position = a_Position;
	v_Color = vec4(1.0);
}