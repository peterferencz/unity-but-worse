#include "graphics/materials/mSimpleColor.h"

mSimpleColor::mSimpleColor(glm::vec3 color)
: Material(
    new VertexShader("resources/shaders/vertexshader.glsl"),
    new FragmentShader("resources/shaders/simpleColor.glsl")
),
color(color) {

}

mSimpleColor::~mSimpleColor(){

}

void mSimpleColor::Draw(){
    setUniform("uColor", color);
}