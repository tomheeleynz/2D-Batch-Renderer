#shader vertex
#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 fragColor;

uniform mat4 modelMatrix;

void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   fragColor = aColor;
}

#shader fragment
#version 450 core

in vec3 fragColor;
out vec4 Color;

void main()
{
	Color = vec4(fragColor, 1.0);
}