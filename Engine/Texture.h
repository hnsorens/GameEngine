#pragma once

#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>

class Texture
{
public:

	Texture(const char* texturePath);

	void use();

private:

	unsigned int texture;
};