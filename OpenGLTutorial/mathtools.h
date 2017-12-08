#pragma once

#include <glm/glm.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

struct Math {
	float toRadians(float deg) {
		return (deg * M_PI) / 180;
	}

	float toDegrees(float rad) {
		return (rad * 180) / M_PI;
	}

	glm::vec3& getForwardVectorFromAngle(glm::vec3 rot) {
		glm::vec3 forward = glm::vec3(0.0f, 0.0f, 0.0f);
		//rot.forward
	}
};