#pragma once

#include "graphics/shaders/VertexShader.h"
#include "graphics/shaders/FragmentShader.h"
#include "Math.h"

class Material {
private:
    unsigned int _gpuProg;
    VertexShader& _vertexShader;
    FragmentShader& _fragmentShader;

    
public:
    Material(VertexShader& vertexShader, FragmentShader& fragmentShader);
    virtual ~Material();
    void Use() const;

    void setUniform(const std::string& name, const int val) const;
    void setUniform(const std::string& name, const float val) const;
    void setUniform(const std::string& name, const Framework::Math::Mat4& mat) const;
    void setUniform(const std::string& name, const Framework::Math::Vec2& vec) const;
    void setUniform(const std::string& name, const Framework::Math::Vec3& vec) const;

    virtual void Draw() const;
};