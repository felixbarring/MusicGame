
#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include "player.h"

// ########################################################
// Constructor/Destructor #################################
// ########################################################

Player::Player(float xOffset, float yOffset, std::vector<Cube> *cubesA):
	xStart{xOffset},
	yStart{yOffset},
	xLocation{xOffset},
	yLocation{yOffset},
	width{1},
	height{1}
{

	cubes = cubesA;

	glm::mat4 m = glm::mat4(1.0);

	std::vector<float> vetexData{
		// Front
		0.0f, 0.0f, 0.2f, // 0
		1.0f, 0.0f, 0.2f, // 1
		1.0f, 1.0f, 0.2f, // 2
		0.0f, 1.0f, 0.2f, // 3

		///*
		// Back
		1.0f, 0.0f, 0.8f, // 0
		0.0f, 0.0f, 0.8f, // 1
		0.0f, 1.0f, 0.8f, // 2
		1.0f, 1.0f, 0.8f, // 3

		// Left
		0.0f, 0.0f, 0.8f, // 0
		0.0f, 0.0f, 0.2f, // 1
		0.0f, 1.0f, 0.2f, // 2
		0.0f, 1.0f, 0.8f, // 3

		// Right
		1.0f, 0.0f, 0.2f, // 0
		1.0f, 0.0f, 0.8f, // 1
		1.0f, 1.0f, 0.8f, // 2
		1.0f, 1.0f, 0.2f, // 3

		// Top
		0.0f, 1.0f, 0.2f, // 0
		1.0f, 1.0f, 0.2f, // 1
		1.0f, 1.0f, 0.8f, // 2
		0.0f, 1.0f, 0.8f, // 3

		// Bottom
		0.0f, 0.0f, 0.8f, // 0
		1.0f, 0.0f, 0.8f, // 1
		1.0f, 0.0f, 0.2f, // 2
		0.0f, 0.0f, 0.2f, // 3
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

Player::~Player()
{

}

// ########################################################
// Member Functions########################################
// ########################################################

glm::mat4& Player::getModelMatrix()
{
	return modelMatrix;
}

void Player::draw()
{
	mesh->render();
}

void Player::tick(float f)
{

	if (isDead) {
		ySpeed = 0;
		respawnCounter++;
		if (respawnCounter >= respawnTime) {
			isDead = false;
			respawnCounter = 0;
			xLocation = xStart;
			yLocation = yStart;

		}
	} else {

		xLocation += xSpeed;
		yLocation -= ySpeed;

		bool inter = false;
		for (Cube c : *cubes) {
			if (Player::intersect(c)) {
				inter = true;
			}
		}

		if (inter){
			yLocation += ySpeed+0.001;
			ySpeed = 0;
		} else {
			ySpeed += 0.02;
		}

		inter = false;
		for (Cube c : *cubes) {
			if (Player::intersect(c)) {
				inter = true;
			}
		}
		// Means that we collided with a cube in the horizontal axis
		if (inter) {
			std::cout<<"The Player Died :,(";
			isDead = true;
		}

		glm::mat4 m = glm::mat4(1.0);
		modelMatrix = glm::translate(m, glm::vec3(xLocation, yLocation, 0.0f));
	}
}


bool Player::intersect(Cube &c) {
	return (
			(xLocation > c.getxLocation() && xLocation < c.getxLocation() + c.getWidth()) ||
			(xLocation+width > c.getxLocation() && xLocation+width < c.getxLocation() + c.getWidth())
	)
	&&
	(
			(yLocation > c.getyLocation() && yLocation < c.getyLocation() + c.getHeight()) ||
			(yLocation+height > c.getyLocation() && yLocation+height < c.getyLocation() + c.getHeight())
	);
}

void Player::jump() {
	float dummy = yLocation;
	yLocation -= ySpeed;
	for (Cube c : *cubes) {
		if (Player::intersect(c)) {
			ySpeed = -0.3;
		}
	}
	yLocation = dummy;
}


