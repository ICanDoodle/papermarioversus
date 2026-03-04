#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	camWidth = width;
	camHeight = height;
	Camera::position = position;

}

void Camera::setMatrix(Shader& shader, const char* uniform)
{
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::updateMatrix(float FOV, float, float)
{
	glm::mat4 view = glm::mat4(1.0f);

	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(position, position + orientation, height);

	projection = glm::perspective(glm::radians(FOV), (float)(camWidth / camHeight), 0.1f, 100.0f);

	cameraMatrix = projection * view;

}

void Camera::input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		position.x -= 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		position.x += 0.1f;
	}
}
