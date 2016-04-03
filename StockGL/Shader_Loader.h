#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include<iostream>
namespace Core {
	class Shader_Loader
	{
	private:
		std::string ReadShader(const std::string &filename);
		GLuint CreateShader(GLenum shaderType, const std::string &source, const std::string &shaderName);

	public:
		Shader_Loader();
		~Shader_Loader();
		GLuint CreateProgram(const std::string & vertexShaderFilename, const std::string &fragmentShaderFilename);
	};
}



