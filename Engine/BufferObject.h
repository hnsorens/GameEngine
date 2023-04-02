#pragma once

#include <glad/glad.h>
#include <vector>


class BufferObject
{
public:

	BufferObject(std::vector<float>* vertices, std::vector<int>* indices, bool colorEnabled, bool textureEnabled);

	void SetBuffers(std::vector<float>* vertices, std::vector<int>* indices);

	void use();


	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

	bool colors = false;
	bool texture = false;

	int stride = 3;
	int offset = 0;
	int attribArray = 0;
};