#version 330 core

uniform sampler2D uTexture;

in vec2 TexCoords;

out vec4 fragment;

void main() {
    fragment = texture(uTexture, TexCoords);
}