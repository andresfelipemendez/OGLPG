#include "LoadShaders.h"

GLuint LoadShaders(ShaderInfo* shaders) {
	if (shaders == nullptr) {
		return 0;
	}

	GLuint program = glCreateProgram();

	return program;
}