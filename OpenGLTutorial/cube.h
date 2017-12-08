#pragma once

#include "mesh.h"
#include <vector>

class Cube {
public:
	Cube(float width, float height, float depth);
	~Cube();

	Vertex* getVertices() {
		return &m_vertices[0];
	}

	unsigned int* getIndices() {
		return &m_indices[0];
	}

private:
	glm::vec3 dimensions;
	std::vector<Vertex> m_vertices;
	std::vector<unsigned int> m_indices;
	void generateVertices(float width, float height, float depth) {
		Vertex vertices[24] = {
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
				Vertex(glm::vec3(-width / 2, height / 2, depth / 2), glm::vec2(0.0f, depth), glm::vec3(0.0f, 1.0f, 1.0f)),
				Vertex(glm::vec3(width / 2, height / 2, -depth / 2), glm::vec2(width, 0.0f), glm::vec3(0.0f, 1.0f, 1.0)),
				Vertex(glm::vec3(width / 2, height / 2, depth / 2), glm::vec2(width, depth), glm::vec3(0.0f, 1.0f, 1.0f)),

				// Bottom face
				Vertex(glm::vec3(-width / 2, -height / 2, -depth / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 1.0f)),
				Vertex(glm::vec3(-width / 2, -height / 2, depth / 2), glm::vec2(0.0f, depth), glm::vec3(0.0f, -1.0f, 1.0f)),
				Vertex(glm::vec3(width / 2, -height / 2, -depth / 2), glm::vec2(width, 0.0f), glm::vec3(0.0f, -1.0f, 1.0)),
				Vertex(glm::vec3(width / 2, -height / 2, depth / 2), glm::vec2(width, depth), glm::vec3(0.0f, -1.0f, 1.0f))
		};

		m_vertices = { std::begin(vertices), std::end(vertices) };
	}
};

// +Z = Towards Screen; +X = Right; +Y = Up;

Cube::Cube(float width, float height, float depth) {
	dimensions = glm::vec3(width, height, depth);

	generateVertices(width, height, depth);

	unsigned int indices[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };

	m_indices = { std::begin(indices), std::end(indices) };
}

Cube::~Cube() {

}