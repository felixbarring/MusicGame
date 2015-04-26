
//#include "model/level.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

GLFWwindow *window;

using namespace glm;

int main( void )
{
	// Initialise GLFW
	if( !glfwInit() ) {
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 16);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 800, 600, "Game", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	const double fps = 60;
	const double timePerFram = 1.0 / fps;
	const double mili = 0.001;
	std::chrono::milliseconds oneMilliSecond( 1 );

	//Level level;

	glClearColor(0.2f, 0.22f, 0.2f, 1.0f);

	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 ){

		double frameStartTime = glfwGetTime();

		glClear(GL_COLOR_BUFFER_BIT);

		//level.render( glfwGetKey(window, GLFW_KEY_SPACE ) == GLFW_PRESS);

		// Sleep the thread if we are running fast to save computer power.
		// If we are running too fast and there is more than 1 miliseconds left until
		//  next frame then the thread will sleep for the time that remains.
		// If there is less than 2 milliseconds left, we busy wait until it is time to proceed with the next frame.
		// The busy waiting is used to increase the timing accuracy, we do not want to start the next frame to late.
		double totalFrameTime = glfwGetTime() - frameStartTime;
		while(totalFrameTime < timePerFram){
			double timeRemainingInMilis = (timePerFram - totalFrameTime) / mili;
			if (timeRemainingInMilis > 2){
				std::this_thread::sleep_for( (timeRemainingInMilis-1) * oneMilliSecond );
			} else if(timeRemainingInMilis > 1){
				std::this_thread::sleep_for( oneMilliSecond );
			}
			totalFrameTime = glfwGetTime() - frameStartTime;
		}

		// Printing mouse location
		/*
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		std::cout << "XPOS: " << xpos << " YPOS: " << ypos;
		*/

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}




