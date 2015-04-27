
#ifndef GAME_MODEL_LEVEL_H_
#define GAME_MODEL_LEVEL_H_

#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

#include "cube.h"
#include "player.h"
#include "shaderProgram.h"

class Level {
public:
// ########################################################
// Constructor/Destructor #################################
// ########################################################
	Level();
	virtual ~Level();

// ########################################################
// Member Functions########################################
// ########################################################
	void render(bool jump);

// ########################################################
// Instance Variables #####################################
// ########################################################

private:
	Player *player;
	std::vector<Cube> cubes;
	ShaderProgram* program;
	glm::mat4 Projection;
	glm::mat4 MVP;

};


#endif /* GAME_MODEL_LEVEL_H_ */
