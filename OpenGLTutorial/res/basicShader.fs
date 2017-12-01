#version 120

varying vec2 texCoord0;
varying out vec4 out_Color;

uniform sampler2D diffuse;

void main() {
	out_Color = texture2D(diffuse, texCoord0);
}