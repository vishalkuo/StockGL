#include "Shader_Loader.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace Core;
Shader_Loader::Shader_Loader(){}
Shader_Loader::~Shader_Loader() {}

std::string Shader_Loader::ReadShader(const std::string &filename) {
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in);

	if (!file.good())
	{
		std::cout << "Cannot read " << filename.c_str() << std::endl;
		std::terminate();
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();
	return shaderCode;
}	

GLuint Shader_Loader::CreateShader(GLenum shaderType, const std::string & source, const std::string & shaderName)
{
	int compileResult = 0;
	GLuint shader = glCreateShader(shaderType);
	const char *shaderCodePtr = source.c_str();
	const int shaderCodeSize = source.size();

	glShaderSource(shader, 1, &shaderCodePtr, &shaderCodeSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE) {
		std::cout << "ERROR COMPILING FOR " << source.c_str();
		return 0;
	}

	return shader;
}

GLuint Shader_Loader::CreateProgram(const std::string & vertexShaderFilename, const std::string & fragmentShaderFilename)
{
	std::string vertexShaderCode = ReadShader(vertexShaderFilename);
	std::string fragmentShaderCode = ReadShader(fragmentShaderFilename);
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, vertexShaderCode, "vertex shader");
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentShaderCode, "fragment shader");

	int linkResult = 0;

	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);

	if (linkResult == GL_FALSE)
	{
		std::cout << "Shader Loader: LINKER ERROR";
		return 0;
	}

	return program;
}