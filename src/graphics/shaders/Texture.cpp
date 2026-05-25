// This is the Stb image implementation, it should be above the stb_image.h include
#define STB_IMAGE_IMPLEMENTATION
#include "graphics/shaders/Texture.h"


Texture::Texture(std::string const& path)
: _path(path) {
    glGenTextures(1, &_textureId);

    // Stbi - Opengl compatibility
    stbi_set_flip_vertically_on_load(true);
    
    int width, height, channels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

    if(!data){
        Logger::Error("Failed to load texture: " + path);
        stbi_image_free(data);
        return;
    }

    GLenum format = GL_RGB;
    if      (channels == 1) { format = GL_RED;  }
    else if (channels == 3) { format = GL_RGB;  }
    else if (channels == 4) { format = GL_RGBA; }

    glBindTexture(GL_TEXTURE_2D, _textureId);
            
    // Upload pixel data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    // glGenerateMipmap(GL_TEXTURE_2D);

    // Set texture wrapping and filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
}

Texture::~Texture(){
    glDeleteTextures(1, &_textureId);
}

void Texture::Bind() const {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _textureId);
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}