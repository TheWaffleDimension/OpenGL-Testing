#version 120

varying vec2 texCoord0;
varying vec3 normal0;
varying out vec4 out_Color;

uniform sampler2D diffuse;

void main() {
	out_Color = texture2D(diffuse, texCoord0)
		* clamp(dot(-vec3(0, 0, 1), normal0), 0.5, 1.0);
}