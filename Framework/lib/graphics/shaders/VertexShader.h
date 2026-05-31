#pragma once

#include "Shader.h"

class ShaderCache;    //FWDecl

class VertexShader : public Shader {
friend class ShaderCache;
private:

    VertexShader();
    static VertexShader* FromCode(const std::string& code);
    static VertexShader* FromCode(const std::string& code, std::string& message);

protected:

public:
    ~VertexShader();
};