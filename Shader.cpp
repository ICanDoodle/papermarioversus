#include "Shader.h"
#include "VBO.h"

Shader::Shader(const char* vert, const char* frag)
{
	string vertexCode = get_file_contents(vert);
	string fragmentCode = get_file_contents(frag);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &vertexSource, NULL);
	glCompileShader(vertexshader);
	compileErrors(vertexshader, "VERTEX");

	GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentshader);
	compileErrors(fragmentshader, "FRAGMENT");

	ID = glCreateProgram();

	glAttachShader(ID, vertexshader);
	glAttachShader(ID, fragmentshader);

	glLinkProgram(ID);
	compileErrors(ID, "PROGRAM");

	if (vertexCode.empty() || fragmentCode.empty()) {
		cerr << "shader source code is empty." << endl;
		exit(EXIT_FAILURE);
	}

	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const char* type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			cerr << "SHADER_COMPILATION_ERROR for:" << type << "\n" << endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			cerr << "SHADER_LINKING_ERROR for:" << type << "\n" << endl;
		}
	}
}

string get_file_contents(const char* filename)
{
	ifstream in(filename, ios::binary);
	if (in) {
		string contents;
		in.seekg(0, ios::end);
		contents.resize(in.tellg());
		in.seekg(0, ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);

	}
	else {
		cerr << "could not open file: " << filename << endl;
	}
}



