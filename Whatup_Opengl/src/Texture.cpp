#include "Texture.h"
#include <iostream>

#include <GL/glew.h>
#include <stb_image.h>

#include "GLMacro.h"
#include "Shader.h"

std::string Texture::TypeName[2] = { "diffuse", "specular" };

Texture::Texture(const char* path, Texture::Type type)
{
    _id = generate_Texture(path);
    _type = TypeName[static_cast<unsigned int>(type)];
}

Texture::~Texture()
{
}

unsigned int Texture::generate_Texture(const char* path)
{
    unsigned int texture;
    GLCall(glGenTextures(1, &texture));
    GLCall(glBindTexture(GL_TEXTURE_2D, texture));

    // set the texture wrapping/filtering options (on the currently bound texture object)
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    // load and generate the texture
    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        GLint internalFormat = nrChannels == 3 ? GL_RGB : GL_RGBA;
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, GL_UNSIGNED_BYTE, data));
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    return texture;
}
