#include "Mesh.h"

Mesh::Mesh(vector <Vertex>& vertices, vector <GLuint>& indices) {

	Mesh::vertices = vertices;
	Mesh::indices = indices;

	Mesh::VAO.Bind();

	VBO VBO(vertices);
	EBO EBO(indices);

	VAO.linkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.linkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.linkAttrib(VBO, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
	VAO.linkAttrib(VBO, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();

}

void Mesh::draw(Shader& shader, Camera& camera, glm::vec3 position, glm::vec3 scale)
{

	shader.Activate();

	camera.setMatrix(shader, "cameraMatrix");

	VAO.Bind();

	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);

	glUniform1i(glGetUniformLocation(shader.ID, "useTexture"), false);

	// gets the position of the camera
	glUniform3f(glGetUniformLocation(shader.ID, "cameraPosition"), camera.position.x, camera.position.y, camera.position.z);

	// gets the actual model 
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// draw
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

}
