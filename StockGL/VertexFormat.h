#pragma once
#include "glm\glm.hpp"
struct VertexFormat
{
	glm::vec3 position;
	VertexFormat(const glm::vec3 &pos)
	{
		position = pos;
	}
};

