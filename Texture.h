

#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include "glad/glad.h"
#include <stb/stb_image.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class Texture
{
public:
	// the actual id and texture type 
	GLuint ID;
	GLenum type;

	// image width and height, rgba channels
	int imgWidth, imgHeight;
	int colorChannels = 4;

	// actual pixel data
	unsigned char* bytes;
	// sub image for sprite sheets
	unsigned char* subImage = nullptr;

	Texture(const char* image, GLenum textureType, GLenum slot);

	void textureUint(Shader& shader, const char* uniform, GLuint uint);

	void Bind();
	void Unbind();
	void Delete();
};

#endif

