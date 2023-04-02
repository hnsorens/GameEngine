#version 460 core

out vec4 FragColor;

in vec3 color;
in vec2 uvs;

uniform sampler2D outTexture;

void main()
{
	FragColor = vec4(color, 1.0) * texture(outTexture, uvs);
}