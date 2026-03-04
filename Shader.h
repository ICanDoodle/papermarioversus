#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>
using namespace std;

string get_file_contents(const char* filename);

class Shader
{
public:

	GLuint ID;

	Shader(const char* vert, const char* frag);

	void Activate();
	void Delete();
	void compileErrors(unsigned int shader, const char* type);


};

#endif

