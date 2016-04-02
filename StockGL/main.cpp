#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include <iostream>
#include "Point.h"
using namespace std;

int main() {
	point graph[2000];
	for (int i = 0; i < 2000; i++) {
		float xValue = (i - 1000) / 100;
		graph[i].x = xValue;
		graph[i].y = sin(xValue);
	}

	GLuint vbo;
	
	//glGenBuffers(1, &vbo);
}