#pragma once

#include "glad/glad.h"
#include"GLFW/glfw3.h"
#include "miniaudio.h"

struct EngineContext {

	GLFWwindow *window;

	ma_engine* audio;

};