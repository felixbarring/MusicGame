#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include "cube.h"

// ########################################################
// Constructor/Destructor #################################
// ########################################################

Cube::Cube(float xOffset, float yOffset):
	xLocation{xOffset},
	yLocation{yOffset},
	width{1},
	height{1}
{

	glm::mat4 m = glm::mat4(1.0);
	modelMatrix = glm::translate(m, glm::vec3(xOffset, yOffset, 0.0f));

	std::vector<float> vetexData{
		// Front
		0.0f, 0.0f, 0.0f, // 0
		1.0f, 0.0f, 0.0f, // 1
		1.0f, 1.0f, 0.0f, // 2
		0.0f, 1.0f, 0.0f, // 3

		///*
		// Back
		1.0f, 0.0f, 1.0f, // 0
		0.0f, 0.0f, 1.0f, // 1
		0.0f, 1.0f, 1.0f, // 2
		1.0f, 1.0f, 1.0f, // 3

		// Left
		0.0f, 0.0f, 1.0f, // 0
		0.0f, 0.0f, 0.0f, // 1
		0.0f, 1.0f, 0.0f, // 2
		0.0f, 1.0f, 1.0f, // 3

		// Right
		1.0f, 0.0f, 0.0f, // 0
		1.0f, 0.0f, 1.0f, // 1
		1.0f, 1.0f, 1.0f, // 2
		1.0f, 1.0f, 0.0f, // 3

		// Top
		0.0f, 1.0f, 0.0f, // 0
		1.0f, 1.0f, 0.0f, // 1
		1.0f, 1.0f, 1.0f, // 2
		0.0f, 1.0f, 1.0f, // 3

		// Bottom
		0.0f, 0.0f, 1.0f, // 0
		1.0f, 0.0f, 1.0f, // 1
		1.0f, 0.0f, 0.0f, // 2
		0.0f, 0.0f, 0.0f, // 3
		//*/

		// Normals
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
	};


	std::vector<short> elementData{
		0, 1, 2, 0, 2, 3,
		0+4, 1+4, 2+4, 0+4, 2+4, 3+4,
		0+8, 1+8, 2+8, 0+8, 2+8, 3+8,
		0+12, 1+12, 2+12, 0+12, 2+12, 3+12,
		0+16, 1+16, 2+16, 0+16, 2+16, 3+16,
		0+20, 1+20, 2+20, 0+20, 2+20, 3+20,
	};

	mesh = new Mesh(vetexData, elementData);
}

Cube::~Cube()
{
	// TODO Auto-generated destructor stub
}

// ########################################################
// Member Functions########################################
// ########################################################

glm::mat4& Cube::getModelMatrix()
{
	return modelMatrix;
}

void Cube::draw()
{
	mesh->render();
}
