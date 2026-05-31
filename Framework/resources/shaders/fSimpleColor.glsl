#version 330 core

uniform vec3 uColor = vec3(0.949, 0.145, 1);
out vec4 fragment;

void main() {
    fragment = vec4(uColor, 1.0);
}