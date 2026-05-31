#include "graphics/shaders/FragmentShader.h"

#include "glad/gl.h"
#include "Logger.h"

FragmentShader::FragmentShader(){

}

FragmentShader* FragmentShader::FromCode(const std::string& code) {
    std::string msg;
    return FromCode(code, msg);
}

FragmentShader* FragmentShader::FromCode(const std::string& code, std::string& message){
    FragmentShader* vtx = new FragmentShader();
    
    if(!vtx->loadShader(GL_FRAGMENT_SHADER, code, message)){
        delete vtx;
        return nullptr;
    }

    return vtx;
}

FragmentShader::~FragmentShader(){
    glDeleteShader(_shaderId);
}