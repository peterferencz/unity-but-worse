#include "graphics/materials/mSimpleTexture.h"

#include "graphics/shaders/ShaderCache.h"

mSimpleTexture::mSimpleTexture(Texture* texture)
: Material(
    ShaderCache::getVertexShader("resources/shaders/vertexshader.glsl"),
    ShaderCache::getFragmentShader("resources/shaders/fSimpleTexture.glsl")
),
_texture(texture) {

}

mSimpleTexture::~mSimpleTexture(){
    delete _texture;
}

void mSimpleTexture::Draw() const {
    _texture->Bind();
    setUniform("uTexture", 0);
}