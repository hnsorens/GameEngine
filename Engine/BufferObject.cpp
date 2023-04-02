#include "BufferObject.h"

BufferObject::BufferObject(std::vector<float>* vertices, std::vector<int>* indices, bool colorEnabled, bool textureEnabled)
{
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);

	colors = colorEnabled;
	texture = textureEnabled;

	if (colorEnabled) stride += 3;
	if (textureEnabled) stride += 2;

	SetBuffers(vertices, indices);

}

void BufferObject::SetBuffers(std::vector<float>* vertices, std::vector<int>* indices)
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(float), vertices->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(int), indices->data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	offset += 3;

	if (colors)
	{
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
		glEnableVertexAttribArray(1);
		offset += 3;
	}

	if (texture)
	{
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
		glEnableVertexAttribArray(2);
		offset += 2;
	}
}

void BufferObject::use()
{
	glBindVertexArray(VAO);
}