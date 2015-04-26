#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <map>
#include <string.h>
#include <GL/glew.h>

class ShaderProgram {
public :

// ########################################################
// Constructor/Destructor #################################
// ########################################################

	 ShaderProgram(const char *vertexSource, const char *fragmentSource , std::map<std::string, int> *mapUniforms);
	~ShaderProgram();

// ########################################################
// Member Functions########################################
// ########################################################

private :
	GLuint createVertexShader(const char *vertexSource);
	GLuint createFragmentShader(const char *fragmentSource);
	GLuint createShader(GLenum shaderType, const char *source);

public :

	GLuint getID()
	{
		return programID;
	}

	void setUniform1f();
	void setUniformVec3f();
	void setUniformMatrix4f();

	void bind();
	void unbind();

// ########################################################
// Instance Variables #####################################
// ########################################################

private :
	GLuint programID;
	std::map<std::string, int> uniforms;

};

#endif
