#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 Normal;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;
uniform float uTime;

void main() {
    TexCoords = aTexCoords;
    Normal = mat3(transpose(inverse(uModel))) * aNormal;

    vec3 modifiedPos = aPos;

    float speed = 5.0;
    float waveOffset = abs(aPos.x) * 2.0; 
    
    float wobble = sin(uTime * speed + waveOffset);

    modifiedPos.y += wobble * abs(aPos.x) * 0.3;

    gl_Position = uProjection * uView * uModel * vec4(modifiedPos, 1.0);
}