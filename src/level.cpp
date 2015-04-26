
#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include "level.h"

Level::Level()
{
	const char *vert =
			"#version 330 core \n"

			"layout(location = 0) in vec3 vertex; \n"
			"layout(location = 1) in vec3 normals; \n"

			"out vec3 fragmentColor; \n"
			"out vec3 faceNormal; \n"

			"uniform mat4 MVP; \n"

			"void main(){ \n"
			"	faceNormal = normals; \n"
			"	fragmentColor = vec3(0.6, 0.5, 0.9); \n"
			"	gl_Position =  MVP * vec4(vertex,1); \n"
			"} \n";

		const char *frag =
			"#version 330 core \n"
			"in vec3 fragmentColor; \n"
			"in vec3 faceNormal; \n"

			"out vec4 color; \n"

			"uniform vec3 lightDirection;"
			"uniform vec3 diffuseLight = vec3(0.5, 0.5, 0.5); \n "
			"uniform vec3 materialDiffuse; \n "

			"vec3 calculateAmbient(vec3 ambientLight, vec3 materialAmbient) \n"
			"{ \n"
			"  return ambientLight * materialAmbient; "
			"} \n"

			"vec3 calculateDiffuse() \n "
			"{ \n "
			"  return diffuseLight * materialDiffuse * max(0, dot(faceNormal, normalize(lightDirection))); \n "
			"} \n "

			"void main(){ \n"
			"  vec3 difuse = calculateDiffuse(); \n "
			"  color = vec4((difuse + fragmentColor), 1); \n"
			"} \n";

		program = new ShaderProgram( vert, frag, nullptr );

		glClearColor(0.2, 0.22, 0.2, 0.0);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		//glEnable(GL_CULL_FACE);

		uniformMatrix = glGetUniformLocation(program->getID(), "MVP");
		uniformLightDirection = glGetUniformLocation(program->getID(), "lightDirection");
		uniformDifuse = glGetUniformLocation(program->getID(), "materialDiffuse");
		float aspectRatio =  800/600;
		Projection = glm::perspective(80.0f, aspectRatio, 0.1f, 100.0f);

		Cube cube1{0, 0};
		Cube cube2{1, 0};
		Cube cube3{2, 0};
		Cube cube4{3, 0};
		Cube cube5{4, 0};
		Cube cube6{5, -1};
		Cube cube7{6, -2};
		Cube cube8{7, -3};
		Cube cube9{8, -3};

		Cube cube10{9, -2};
		Cube cube11{10, -2};
		Cube cube12{11, -3};
		Cube cube13{12, -2};
		Cube cube14{13, -1};
		Cube cube15{14, -1};
		Cube cube16{15, -1};
		Cube cube17{16, -1};
		Cube cube18{17, -1};
		Cube cube19{18, -1};

		Cube cube20{19, -1};
		Cube cube21{20, -2};
		Cube cube22{21, -3};
		Cube cube23{22, -2};
		Cube cube24{23, -1};
		Cube cube25{24, -1};
		Cube cube26{25, -1};
		Cube cube27{26, -1};
		Cube cube28{27, -1};
		Cube cube29{28, -1};

		Cube cube30{29, -1};
		Cube cube31{29, -2};
		Cube cube32{29, -3};
		Cube cube33{29, -4};
		Cube cube34{30, -4};
		Cube cube35{31, -4};
		Cube cube36{32, -4};
		Cube cube37{33, -4};
		Cube cube38{34, -4};
		Cube cube39{34, -3};

		Cube cube40{34, -2};
		Cube cube41{34, -1};
		Cube cube42{34, -1};
		Cube cube43{34, -1};
		Cube cube44{34, -1};
		Cube cube45{35, 0};
		Cube cube46{36, 0};
		Cube cube47{37, 1};
		Cube cube48{38, 1};
		Cube cube49{39, 0};

		Cube cube50{40, 0};
		Cube cube51{41, 0};
		Cube cube52{42, -1};
		Cube cube53{43, -1};
		Cube cube54{44, -2};
		Cube cube55{45, -1};
		Cube cube56{46, 0};
		Cube cube57{47, 0};
		Cube cube58{48, 1};
		Cube cube59{49, 0};

		cubes.push_back(cube1);
		cubes.push_back(cube2);
		cubes.push_back(cube3);
		cubes.push_back(cube4);
		cubes.push_back(cube5);
		cubes.push_back(cube6);
		cubes.push_back(cube7);
		cubes.push_back(cube8);
		cubes.push_back(cube9);

		cubes.push_back(cube10);
		cubes.push_back(cube11);
		cubes.push_back(cube12);
		cubes.push_back(cube13);
		cubes.push_back(cube14);
		cubes.push_back(cube15);
		cubes.push_back(cube16);
		cubes.push_back(cube17);
		cubes.push_back(cube18);
		cubes.push_back(cube19);

		cubes.push_back(cube20);
		cubes.push_back(cube21);
		cubes.push_back(cube22);
		cubes.push_back(cube23);
		cubes.push_back(cube24);
		cubes.push_back(cube25);
		cubes.push_back(cube26);
		cubes.push_back(cube27);
		cubes.push_back(cube28);
		cubes.push_back(cube29);

		cubes.push_back(cube30);
		cubes.push_back(cube31);
		cubes.push_back(cube32);
		cubes.push_back(cube33);
		cubes.push_back(cube34);
		cubes.push_back(cube35);
		cubes.push_back(cube36);
		cubes.push_back(cube37);
		cubes.push_back(cube38);
		cubes.push_back(cube39);

		cubes.push_back(cube40);
		cubes.push_back(cube41);
		cubes.push_back(cube42);
		cubes.push_back(cube43);
		cubes.push_back(cube44);
		cubes.push_back(cube45);
		cubes.push_back(cube46);
		cubes.push_back(cube47);
		cubes.push_back(cube48);
		cubes.push_back(cube49);

		cubes.push_back(cube50);
		cubes.push_back(cube51);
		cubes.push_back(cube52);
		cubes.push_back(cube53);
		cubes.push_back(cube54);
		cubes.push_back(cube55);
		cubes.push_back(cube56);
		cubes.push_back(cube57);
		cubes.push_back(cube58);
		cubes.push_back(cube59);

		player = new Player(0,2, &cubes);

}

Level::~Level()
{
	// TODO Auto-generated destructor stub
}


float r = 0.7f;
int rDirection = 1;
float g = 0.0f;
int gDirection = 1;
float b = 0.0f;
int bDirection = 1;


void Level::render(bool jump)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program->bind();

	r = (float) (r + rDirection * 0.01);
	if (r > 1.0 || r < 0) {
		rDirection = -rDirection;
	}

	g = (float) (g + gDirection * 0.01);
	if (g > 1.0 || g < 0) {
		gDirection = -gDirection;
	}

	b = (float) (b +bDirection * 0.01);
	if (b > 1.0 || b < 0) {
		bDirection = -bDirection;
	}



	glUniform3f(uniformLightDirection, 0.7, 0.5f, 0.1f);
	glUniform3f(uniformDifuse, r, g, b);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(player->getXLocation() + 0.5f, 3, 7),   // Camera location
		glm::vec3(player->getXLocation() + 0.5f, 0, 0),    // Look at
		glm::vec3(0,1,0)     // Head is up
	);

	for (Cube cube : cubes){
		glm::mat4 blool1 = Projection * View * cube.getModelMatrix();
		glUniformMatrix4fv(uniformMatrix, 1, GL_FALSE, &blool1[0][0]);
		cube.draw();
	}

	if (jump) {
		player->jump();
	}
	player->tick();

	glm::mat4 blool1 = Projection * View * player->getModelMatrix();
	glUniformMatrix4fv(uniformMatrix, 1, GL_FALSE, &blool1[0][0]);
	player->draw();


	program->unbind();
}


