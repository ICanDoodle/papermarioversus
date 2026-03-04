
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VAO.h"
#include "Camera.h"
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"

#include <iostream>

using namespace std;



void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Paper Mario Versus", NULL, NULL);

	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	gladLoadGL();

	if (!gladLoadGL) {
		cerr << "failed to initialize GLAD" << endl;
	}

	// test stuff

	Shader shaderProgram("default.vert", "default.frag");

	Camera camera(640, 480, glm::vec3(0.0f, 0.0f, 3.0f));

	float width = 0.1f;
	float height = 0.1f;
	float length = 0.1f;

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	Vertex planevertices[] = {
		Vertex{glm::vec3(-width, height,  length), glm::vec3(r, g, b), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(width, height,  length), glm::vec3(r, g, b), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(width, -height, length), glm::vec3(r, g, b), glm::vec2(1.0f, 0.0f)},
		Vertex{glm::vec3(-width, -height,  length), glm::vec3(r, g, b), glm::vec2(0.0f, 0.0f)}
	};

	GLuint planeindices[] = {
		0, 1, 2,
		2, 3, 0
	};

	vector <Vertex> planeVertices(planevertices, planevertices + sizeof(planevertices) / sizeof(Vertex));
	vector <GLuint> planeIndices(planeindices, planeindices + sizeof(planeindices) / sizeof(GLuint));

	Mesh testMesh(planeVertices, planeIndices);


	while (!glfwWindowShouldClose(window)) {

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		testMesh.draw(shaderProgram, camera, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f));

		glfwSwapBuffers(window);
		glfwPollEvents();



	};

	glfwDestroyWindow(window);

	glfwTerminate();


	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

}