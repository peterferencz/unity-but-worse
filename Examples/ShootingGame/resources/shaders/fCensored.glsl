#version 330 core

in vec2 TexCoords;
in vec3 WorldPos;
out vec4 fragment;


uniform vec2 uResolution = vec2(1, 1);
uniform float uInterval = 0.33;

uniform float uTime = 0;

float random (vec2 st) {
    return fract(sin(dot(st.xy, vec2(12.9898,78.233))) * 43758.5453123);
}

void main() {
    vec2 st = 10*TexCoords.xy/uResolution.xy;

    vec2 ipos = floor(st);
    vec3 color = vec3(random( ipos * floor(uTime / uInterval) ));

    fragment = vec4(color, 1);
}