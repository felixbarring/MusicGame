
#ifndef GAME_MODEL_ENTITIES_CUBE_H_
#define GAME_MODEL_ENTITIES_CUBE_H_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "mesh.h"

class Cube {
public:
// ########################################################
// Constructor/Destructor #################################
// ########################################################
	Cube(float xOffset, float yOffset);
	virtual ~Cube();

// ########################################################
// Member Functions########################################
// ########################################################
	void draw();
	glm::mat4& getModelMatrix();
	float getxLocation() { return xLocation; }
	float getyLocation() { return yLocation; }
	float getWidth() { return width; }
	float getHeight() { return height; }

// ########################################################
// Instance Variables #####################################
// ########################################################


private:
	Mesh *mesh;
	glm::mat4 modelMatrix;
	float xLocation;
	float yLocation;
	float width;
	float height;
};

#endif /* GAME_MODEL_ENTITIES_CUBE_H_ */
