#ifndef UI_CLASS_H
#define UI_CLASS_H

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Shader.h"
#include "Texture.h"

class UI
{
public:

	vector<Texture> textures;

	VAO VAO;
	VBO VBO;
	EBO EBO;

	UI();

	void drawUIElement();

};

#endif

