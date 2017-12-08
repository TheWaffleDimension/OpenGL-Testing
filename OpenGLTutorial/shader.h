#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

#include "transform.h"
#include "camera.h"

class Shader {
public:
	Shader(const std::string& fileName);
	~Shader();

	void bind();
	void update(Transform& transform, const Camera& camera);
protected:
private:
	enum {
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	static const unsigned int NUM_SHADERS = 2;

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];

	GLuint createShader(const std::string& text, GLenum shaderType);

	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

};

