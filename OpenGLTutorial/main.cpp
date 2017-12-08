#include <iostream>
#include <GL/glew.h>

#include "display.h"
#include "shader.h"
#include "transform.h"
#include "cube.h"
#include "mesh.h"
#include "texture.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char ** argv) {
	Display display(WIDTH, HEIGHT, "Eye see you...");

	Shader shader("./res/basicShader");

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5,-0.5,0), glm::vec2(0.0, 1.0)),
		Vertex(glm::vec3(0,0.5,0), glm::vec2(0.5, 0.0)),
		Vertex(glm::vec3(0.5,-0.5,0), glm::vec2(1.0, 1.0))
	};

	unsigned int indices[] = { 0, 1, 2 };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh mesh2("./res/monkey3.obj");
	Cube cube(1, 1, 1);
	Texture texture("./res/bricks.jpg");

	Transform transform;
	transform.getScale() = glm::vec3(0.5, 0.5, 0.5);

	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);

	float counter = 0.0f;

	while (!display.isClosed()) {
		display.clear(0.0f, 1.0f, 1.0f, 1.0f);

		//transform.getPos().y = ((1.0f + sinf(counter)) * 0.5f) - 0.5f;
		transform.getRot().x = (counter*1);
		transform.getRot().y = (counter*0.8);
		transform.getRot().z = -(counter*1);

		transform.getPos().x = sinf(counter*1);
		transform.getPos().z = cosf(counter*1);
		//transform.getScale().x = ((1.0f + sinf(counter * 5)) * 0.5) + 0.5;
		//transform.getPos().x = sinf(counter * 0.001);

		shader.bind();

		texture.bind(0);
		shader.update(transform, camera);
		//mesh2.draw();
		cube.draw();

		display.update();
		counter += 0.01f;
	}

	return 0;
}