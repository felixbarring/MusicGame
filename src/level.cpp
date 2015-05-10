
#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include "level.h"
#include "entities/player.h"

#include <iostream>
#include <fstream>
#include <vector>

Level::Level()
{
    const char *vert =
            "#version 330 core \n"

            "in vec3 positionIn; \n"
            "in vec3 normalIn; \n"

            "out vec3 fragmentColor; \n"
            "out vec3 faceNormal; \n"

            "uniform mat4 MVP; \n"

            "void main(){ \n"
            "	faceNormal = normalIn; \n"
            "	fragmentColor = vec3(0.6, 0.5, 0.9); \n"
            "	gl_Position =  MVP * vec4(positionIn,1); \n"
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
            //"  color = vec4(materialDiffuse, 1); \n"
            "} \n";

    program = new ShaderProgram(vert, frag, nullptr);

    glClearColor(0.2, 0.22, 0.2, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    //glEnable(GL_CULL_FACE);

    float aspectRatio = 800 / 600;
    Projection = glm::perspective(80.0f, aspectRatio, 0.1f, 100.0f);

    std::vector<std::string> list;
    std::ifstream in_stream;
    std::string line;
    in_stream.open("levels/level.lvl");

    // Add all lines to the vector
    std::cout << "Hejsan" << "\n";
    for (std::string line; getline(in_stream, line);) {
        list.push_back(line);
    }
    in_stream.close();

    // Print all the lines in vector
    int y = 0;
    for (auto row : list) {
        std::cout << row << "\n";
        int x = 0;
        for (char c : row) {
            if (c == 'x') {
                Cube cube{x, -y};
                cubes.push_back(cube);
            }
            x++;
        }
        y++;
    }

    player = new Player(0, 2, &cubes);

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

    b = (float) (b + bDirection * 0.01);
    if (b > 1.0 || b < 0) {
        bDirection = -bDirection;
    }

    program->setUniform3f("lightDirection", 0.7f, 0.5f, 0.1f);
    //glUniform3f(uniformDifuse, r, g, b);
    program->setUniform3f("materialDiffuse", r, g, b);

    // Camera matrix
    glm::mat4 View = glm::lookAt(
            glm::vec3(player->getXLocation() + 0.5f, 3, 7), // Camera location
            glm::vec3(player->getXLocation() + 0.5f, 0, 0), // Look at
            glm::vec3(0, 0, 1) // Head is up
            );

    for (Cube cube : cubes) {
        glm::mat4 blool1 = Projection * View * cube.getModelMatrix();
        program->setUniformMatrix4f("MVP", blool1);

        cube.draw();
    }

    if (jump) {
        player->jump();
    }
    player->tick(1.0);

    glm::mat4 blool1 = Projection * View * player->getModelMatrix();
    program->setUniformMatrix4f("MVP", blool1);
    //glUniformMatrix4fv(uniformMatrix, 1, GL_FALSE, &blool1[0][0]);
    player->draw();

    program->unbind();
}


