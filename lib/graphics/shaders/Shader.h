#pragma once

#include <string>

class ShaderCache;  //FWDecl

class Shader {
friend class ShaderCache;
private:
    std::string readFile(std::string path);

protected:
    std::string _fileContent;
    
public:

    struct ConstructorToken { 
    private: 
        friend class ShaderCache;
        ConstructorToken() = default;
    };
    
    Shader(std::string path, ConstructorToken);
    virtual ~Shader();
    virtual unsigned int getGlShaderId() = 0;
};