#include <iostream>
#include <GL/glew.h>

#include "display.h"
#include "shader.h"
#include "transform.h"
#include "mesh.h"
#include "texture.h"

int main(int argc, char ** argv) {
	Display display(800, 600, "Eye see you...");

	Shader shader("./res/basicShader");

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5,-0.5,0), glm::vec2(0.0, 1.0)),
		Vertex(glm::vec3(0,0.5,0), glm::vec2(0.5, 0.0)),
		Vertex(glm::vec3(0.5,-0.5,0), glm::vec2(1.0, 1.0))
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Texture texture("./res/illuminati.jpg");

	Transform transform;

	float counter = 0.0f;

	while (!display.isClosed()) {
		display.clear(0.0f, 1.0f, 1.0f, 1.0f);

		transform.getPos().y = ((1.0f + sinf(counter)) * 0.5f) - 0.5f;
		transform.getRot().y = counter;

		shader.bind();

		texture.bind(0);
		shader.update(transform);
		mesh.draw();

		display.update();
		counter += 0.01f;
	}

	return 0;
}