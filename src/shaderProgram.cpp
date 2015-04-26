
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <map>
#include "shaderProgram.h"


// ########################################################
// Constructor/Destructor #################################
// ########################################################

ShaderProgram::ShaderProgram(const char *vertexSource, const char *fragmentSource , std::map<std::string, int> *mapUniforms)
{
	// Create the shaders
	GLuint vertexID = createVertexShader(vertexSource);
	GLuint fragmentID = createFragmentShader(fragmentSource);
	
	// Creat the program and comipile it with the shaders
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexID);
	glAttachShader(program, fragmentID);
	glLinkProgram(program);

	// Program error Check
	GLint result = GL_FALSE;
	int logLength;
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	if ( logLength > 0 ){
		std::vector<char> ProgramErrorMessage(logLength+1);
		glGetProgramInfoLog(program, logLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);

	programID = program;

	std::cout<<programID;
}

ShaderProgram::~ShaderProgram()
{

}

// ########################################################
// Member Functions #######################################
// ########################################################


GLuint ShaderProgram::createVertexShader(const char *source)
{
	return createShader(GL_VERTEX_SHADER, source);
}

GLuint ShaderProgram::createFragmentShader(const char *source)
{
	return createShader(GL_FRAGMENT_SHADER, source);
}

GLuint ShaderProgram::createShader(GLenum shaderType, const char *source)
{
	GLuint shaderID = glCreateShader(shaderType);

	std::string shaderSource(source);
	char const *shaderSourcePointer = shaderSource.c_str();
	glShaderSource(shaderID, 1, &shaderSourcePointer, NULL);
	glCompileShader(shaderID);

	// Error Check
	GLint result = GL_FALSE;
	int logLength;

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
	if ( logLength > 0 ){
		std::vector<char> errorMessage(logLength+1);
		glGetShaderInfoLog(shaderID, logLength, NULL, &errorMessage[0]);
		printf("%s\n", &errorMessage[0]);
	}
	return shaderID;
}

void ShaderProgram::setUniform1f()
{
}

void ShaderProgram::setUniformVec3f()
{
}

void ShaderProgram::setUniformMatrix4f()
{
}

void ShaderProgram::bind()
{
	glUseProgram(programID);
}

void ShaderProgram::unbind()
{
	glUseProgram(0);
}





