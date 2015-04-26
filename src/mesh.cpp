
#include <vector>
#include <GL/glew.h>
#include <iostream>
#include "mesh.h"

Mesh::Mesh(std::vector<float> &bufferData, std::vector<short> &elementData)
{
	numberOfElements = elementData.size();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	const int FLOAT_SIZE = (sizeof(float));

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, bufferData.size()*FLOAT_SIZE, &bufferData[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)((bufferData.size() / 2) * FLOAT_SIZE)); //

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementData.size()*2, &elementData[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
}

Mesh::~Mesh() {
	// TODO Auto-generated destructor stub
}

void Mesh::render()
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, numberOfElements, GL_UNSIGNED_SHORT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindVertexArray(0);
}

