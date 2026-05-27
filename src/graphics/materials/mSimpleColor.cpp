#include "graphics/materials/mSimpleColor.h"

#include "graphics/shaders/ShaderCache.h"

mSimpleColor::mSimpleColor(glm::vec3 color)
: Material(
    ShaderCache::getVertexShader("resources/shaders/vertexshader.glsl"),
    ShaderCache::getFragmentShader("resources/shaders/simpleColor.glsl")
),
color(color) {

}

mSimpleColor::~mSimpleColor(){

}

void mSimpleColor::Draw() const{
    setUniform("uColor", color);
}