
#ifndef GAME_MODEL_MESH_H_
#define GAME_MODEL_MESH_H_

#include <GL/glew.h>
#include <vector>

class Mesh {
public:

// ########################################################
// Constructor/Destructor #################################
// ########################################################
	Mesh(std::vector<float> &bufferData, std::vector<short> &elementData);
	virtual ~Mesh();

// ########################################################
// Member Functions########################################
// ########################################################
	void render();

// ########################################################
// Instance Variables #####################################
// ########################################################

private:
	GLuint vao;
	int numberOfElements;
};

#endif /* GAME_MODEL_MESH_H_ */
