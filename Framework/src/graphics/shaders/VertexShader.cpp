#include "graphics/shaders/VertexShader.h"

#include "glad/gl.h"
#include "Logger.h"

VertexShader::VertexShader() {
    
}

VertexShader* VertexShader::FromCode(const std::string& code) {
    std::string msg;
    return FromCode(code, msg);
}

VertexShader* VertexShader::FromCode(const std::string& code, std::string& message){
    VertexShader* vtx = new VertexShader();
    
    if(!vtx->loadShader(GL_VERTEX_SHADER, code, message)){
        delete vtx;
        return nullptr;
    }

    return vtx;
}


VertexShader::~VertexShader() {
    glDeleteShader(_shaderId);
}
