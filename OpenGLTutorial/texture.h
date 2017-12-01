#pragma once

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <cassert>

class Texture {
public:
	Texture(const std::string& fileName);

	void bind(unsigned int unit);

	virtual ~Texture();

protected:

private:
	GLuint m_texture;
};

