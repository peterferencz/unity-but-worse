#include "graphics/materials/mSimpleTexture.h"

mSimpleTexture::mSimpleTexture(Texture* texture)
: Material(
    new VertexShader("resources/shaders/vertexshader.glsl"),
    new FragmentShader("resources/shaders/fSimpleTexture.glsl")
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