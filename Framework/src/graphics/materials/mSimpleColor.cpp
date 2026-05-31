#include "graphics/materials/mSimpleColor.h"

#include "graphics/shaders/ShaderCache.h"

mSimpleColor::mSimpleColor(Framework::Math::Vec3 color)
: Material(
    ShaderCache::getVertexShader("baked:vertex"),
    ShaderCache::getFragmentShader("baked:color")
),
color(color) {

}

mSimpleColor::~mSimpleColor(){

}

void mSimpleColor::Draw() const{
    setUniform("uColor", color);
}