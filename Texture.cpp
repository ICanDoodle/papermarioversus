#include "Texture.h"

Texture::Texture(const char* image, GLenum textureType, GLenum slot)
{
	// duh
	type = textureType;

	// flips the image upon loading it because of differences between how uvs work in opengl vs stbi
	stbi_set_flip_vertically_on_load(true);

	// load the image
	bytes = stbi_load(image, &imgWidth, &imgHeight, &colorChannels, 0);

	// throw error if image fails to load
	if (!bytes) {
		cerr << "failed to load image: " << image << endl;
		subImage = nullptr;
		return;
	}

	// generate the textures, set the active texture, and bind the texture 

	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(textureType, ID);

	// generic texture parameters

	glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// actually create texture from image

	glTexImage2D(textureType, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);

	// duh

	glGenerateMipmap(textureType);

	// free data

	glBindTexture(textureType, 0);
}

void Texture::textureUint(Shader& shader, const char* uniform, GLuint uint)
{
	GLuint textureUniform = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
	glUniform1i(textureUniform, uint);
}

void Texture::Bind() {
	glBindTexture(type, ID);
}

void Texture::Unbind() {
	glBindTexture(type, 0);
}

void Texture::Delete() {
	glDeleteTextures(1, &ID);
	if (bytes) {
		stbi_image_free(bytes);
	}
}
