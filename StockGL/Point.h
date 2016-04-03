#pragma once
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <math.h>

struct point
{
	GLfloat x;
	GLfloat y;
};

point* produceGraph()
{
	point graph[2000];
	for (int i = 0; i < 2000; i++) {
		float xValue = (i - 1000) / 100;
		graph[i].x = xValue;
		graph[i].y = sin(xValue);
	}
	return graph;
}