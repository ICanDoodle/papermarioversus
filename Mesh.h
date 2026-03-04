#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <string>

#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "Texture.h"

enum Primitives {
	CUBE,
	PLANE,
	PYRAMID,

};

class Mesh
{
public:

	vector <Vertex> vertices;
	vector <GLuint> indices;
	vector <Texture> texture;

	VAO VAO;

	glm::mat4 model = glm::mat4(1.0f);

	Mesh(vector <Vertex>& vertices, vector <GLuint>& indices);

	void setTexture(Texture texture);

	void draw(Shader& shader, Camera& camera, glm::vec3 position, glm::vec3 scale);
};

#endif
