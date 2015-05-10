/*
 * player.h
 *
 *  Created on: Apr 20, 2015
 *      Author: felix
 */

#ifndef GAME_MODEL_ENTITIES_PLAYER_H_
#define GAME_MODEL_ENTITIES_PLAYER_H_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "../cube.h"
#include "../mesh.h"

class Player {
public:
// ########################################################
// Constructor/Destructor #################################
// ########################################################
	Player(float xOffset, float yOffset, std::vector<Cube> *cubesA);
	virtual ~Player();

// ########################################################
// Member Functions########################################
// ########################################################
	void draw();
	glm::mat4& getModelMatrix();
	void tick(float f);
	float getXLocation(){ return xLocation; }
	bool intersect(Cube &c);
	void jump();

// ########################################################
// Instance Variables #####################################
// ########################################################


private:
	std::vector<Cube> *cubes;
	Mesh *mesh;
	glm::mat4 modelMatrix;

	float xStart;
	float yStart;

	float xLocation;
	float yLocation;
	float width;
	float height;

	float xSpeed = 0.13;
	float ySpeed = 0;

	bool isDead = false;
	float respawnTime = 100;
	float respawnCounter = 0;

};

#endif /* GAME_MODEL_ENTITIES_PLAYER_H_ */
