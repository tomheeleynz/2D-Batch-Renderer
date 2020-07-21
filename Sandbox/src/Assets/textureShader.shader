#shader vertex
#version 450 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoords;

out vec3 fragColor;
out vec2 fragTexCoord;

uniform mat4 modelMatrix;

void main()
{
	gl_Position = modelMatrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	fragColor = aColor;
	fragTexCoord = aTexCoords;
}

#shader fragment
#version 450 core

in vec3 fragColor;
in vec2 fragTexCoord;

uniform sampler2D tex1;

out vec4 Color;

void main()
{
	Color = vec4(fragColor, 1.0);
}