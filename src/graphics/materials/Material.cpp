#include "glad/gl.h"

#include "graphics/materials/Material.h"

#include "graphics/shaders/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

Material::Material(VertexShader& vertexShader, FragmentShader& fragmentShader)
: _vertexShader(vertexShader),
_fragmentShader(fragmentShader) {
    _gpuProg = glCreateProgram();
    glAttachShader(_gpuProg, vertexShader.getGlShaderId());
    glAttachShader(_gpuProg, fragmentShader.getGlShaderId());
    glLinkProgram(_gpuProg);
}

Material::~Material(){
    
}

void Material::Use() const {
    glUseProgram(_gpuProg);
}

void Material::Draw() const {
    
}

void Material::setUniform(const std::string& name, int value) const {
    unsigned int location = glGetUniformLocation(_gpuProg, name.c_str());
    glUniform1i(location, value);
}

void Material::setUniform(const std::string& name, float value) const {
    unsigned int location = glGetUniformLocation(_gpuProg, name.c_str());
    glUniform1f(location, value);
}

void Material::setUniform(const std::string& name, const glm::mat4& mat)  const {
    unsigned int location = glGetUniformLocation(_gpuProg, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Material::setUniform(const std::string& name, const glm::vec2& vec) const {
    unsigned int location = glGetUniformLocation(_gpuProg, name.c_str());
    glUniform2fv(location, 1, &vec.x);
}

void Material::setUniform(const std::string& name, const glm::vec3& vec) const {
    unsigned int location = glGetUniformLocation(_gpuProg, name.c_str());
    glUniform3fv(location, 1, &vec.x);
}
