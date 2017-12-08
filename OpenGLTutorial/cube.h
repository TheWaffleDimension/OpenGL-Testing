#pragma once

#include "mesh.h"

class Cube {
public:
	Cube(float width, float height, float depth);
	~Cube();

	void draw() {
		m_mesh:draw();
	}

private:
	glm::vec3 dimensions;
	Vertex m_vertices[24];
	unsigned int m_indices[24];
	Mesh m_mesh;
};

// +Z = Towards Screen; +X = Right; +Y = Up;

Cube::Cube(float width, float height, float depth) : m_vertices{
	// Front face
	Vertex(glm::vec3(-width / 2, -height / 2, depth / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
	Vertex(glm::vec3(width / 2, -height / 2, depth / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
	Vertex(glm::vec3(-width / 2, height / 2, depth / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
	Vertex(glm::vec3(width / 2, height / 2, depth / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),

	// Back face
	Vertex(glm::vec3(-width / 2, -height / 2, -depth / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
	Vertex(glm::vec3(width / 2, -height / 2, -depth / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
	Vertex(glm::vec3(-width / 2, height / 2, -depth / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0)),
	Vertex(glm::vec3(width / 2, height / 2, -depth / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)),

	// Right face
	Vertex(glm::vec3(width / 2, -height / 2, -depth / 2), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
	Vertex(glm::vec3(width / 2, -height / 2, depth / 2), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
	Vertex(glm::vec3(width / 2, height / 2, -depth / 2), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
	Vertex(glm::vec3(width / 2, height / 2, depth / 2), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),

	// Left face
	Vertex(glm::vec3(-width / 2, -height / 2, -depth / 2), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
	Vertex(glm::vec3(-width / 2, -height / 2, depth / 2), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
	Vertex(glm::vec3(-width / 2, height / 2, -depth / 2), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
	Vertex(glm::vec3(-width / 2, height / 2, depth / 2), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),

	// Top face
	Vertex(glm::vec3(-width / 2, height / 2, -depth / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f)),
	Vertex(glm::vec3(-width / 2, height / 2, depth / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f)),
	Vertex(glm::vec3(width / 2, height / 2, -depth / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0)),
	Vertex(glm::vec3(width / 2, height / 2, depth / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f)),

	// Bottom face
	Vertex(glm::vec3(-width / 2, -height / 2, -depth / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 1.0f)),
	Vertex(glm::vec3(-width / 2, -height / 2, depth / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 1.0f)),
	Vertex(glm::vec3(width / 2, -height / 2, -depth / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 1.0)),
	Vertex(glm::vec3(width / 2, -height / 2, depth / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 1.0f))
},
	m_indices{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 },
	dimensions(glm::vec3(width, height, depth)),
	m_mesh(Mesh(m_vertices, 24, m_indices, 24))
												{}

Cube::~Cube() {

}