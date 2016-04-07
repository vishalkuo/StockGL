#include <iostream>
#include "Shader_Loader.h"
#include "ShaderModels.h"

using namespace Core;

GLuint program;
GLint attribute_coord2d;
GLint uniform_offset_x;
GLint uniform_scale_x;
GLint uniform_sprite;
GLuint texture_id;
GLint uniform_mytexture;
float offset_x = 0.0;
float scale_x = 1.0;
int mode = 0;

Models::ShaderModels *models;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.3, 1.0);

	glBindVertexArray(models->getModel("basicModel"));
	glUseProgram(program);

	glDrawArrays(GL_LINE_STRIP, 0, 2000);

	glutSwapBuffers();
}

void exitCallback()
{
	std::cout << "GLUT FINISHED" << std::endl;
	glutLeaveMainLoop();
}

void Init()
{

	glEnable(GL_DEPTH_TEST);

	//load and compile shaders
	Core::Shader_Loader shaderLoader;
	program = shaderLoader.CreateProgram("VShader.glsl",
		"FShader.glsl");
	models = new Models::ShaderModels();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	attribute_coord2d = glGetAttribLocation(program, "coord2d"	);
	models->createLineModel("basicModel", attribute_coord2d);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("StockGL");
	glewInit();

	Init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutCloseFunc(exitCallback);
	glutMainLoop();
	glDeleteProgram(program);
	return 0;

}