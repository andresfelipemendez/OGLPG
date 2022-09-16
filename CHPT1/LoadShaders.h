#pragma once

#include <GL/glew.h>

struct ShaderInfo
{
	GLenum type;
	const char* filename;
	GLuint Shader;

};

GLuint LoadShaders(ShaderInfo*);