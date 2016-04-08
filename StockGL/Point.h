#pragma once
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <math.h>
#include <vector>

struct point
{
	GLfloat x;
	GLfloat y;
	point(int xVal, int yVal) {
		x = xVal;
		y = yVal;
	}
	point() {}
};

std::vector<point> produceGraph()
{
	std::vector<point> graph;
	for (int i = 0; i < 2000; i++) {
		float xValue = (i - 1000) / 100;
		point p;
		p = point(xValue, sin(xValue));
		graph.push_back(p);
	}
	return graph;
}