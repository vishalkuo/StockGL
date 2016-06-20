#pragma once
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "CSVParser.h"

struct point
{
	GLfloat x;
	GLfloat y;
	point(float xVal, float yVal) {
		x = xVal;
		y = yVal;
	}
};


std::ostream &operator << (std::ostream &os, point &t) {
	os << "POINT: " << t.x << " " << t.y << std::endl;
	return os;
}
std::vector<point> produceGraph()
{
	stock_util::CSVRow csv_row;
	std::ifstream in("Stocks/BRK-B.csv");
	csv_row.read_next_row(in);

	std::vector<point> graph;
	for (int i = 0; i < 2000; i++) {
		float x = (i - 1000.0) / 100.0;
		//float y = cos(x * 10.0) / (1.0 + x * x);
		float y = x;
		point p = point(x, y);
		graph.push_back(p);
	}
	return graph;
}