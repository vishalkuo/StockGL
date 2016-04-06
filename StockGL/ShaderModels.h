#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "VertexFormat.h"
#include <vector>
#include <map>

namespace Models
{
	struct Model
	{
		unsigned int vao;
		std::vector<unsigned int> vbos;
		Model(){
		}
	};

	class ShaderModels
	{
	public:
		ShaderModels();
		~ShaderModels();
		void createBasicModel(const std::string &modelName);
		void deleteModel(const std::string &modelName);
		unsigned int getModel(const std::string &modelName);
	private:
		std::map<std::string, Model> ModelMap;
	};
}


