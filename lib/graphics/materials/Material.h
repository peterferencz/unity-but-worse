#pragma once

#include "graphics/shaders/VertexShader.h"
#include "graphics/shaders/FragmentShader.h"
#include "graphics/shaders/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

class Material {
private:
    unsigned int _gpuProg;
    VertexShader* _vertexShader;
    FragmentShader* _fragmentShader;

    
public:
    Material(VertexShader* vertexShader, FragmentShader* fragmentShader);
    virtual ~Material();
    void Use();

    void setUniform(const std::string& name, const int val);
    void setUniform(const std::string& name, const float val);
    void setUniform(const std::string& name, const glm::mat4& mat);
    void setUniform(const std::string& name, const glm::vec2& vec);
    void setUniform(const std::string& name, const glm::vec3& vec);

    virtual void Draw();
};