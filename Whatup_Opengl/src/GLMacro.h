#pragma once

#include <iostream>
#include <GL/glew.h>

#ifdef TEXTURE_CPP
#define SHADER_VARIABLE_TEXTURE_DIFFUSE "diffuse"
#define SHADER_VARIABLE_TEXTURE_SPECULAR "specular"
#endif //  TEXTURE_CPP

#define WO_DEFAULT_VERTEX_SHADER "shaders/VertexShader.vert"
#define WO_DEFAULT_FRAGMENT_SHADER "shaders/DepthTesting.frag"

inline static void GLClearError() { while (glGetError() != GL_NO_ERROR); }

static bool GLLogCall(const char* function, const char* file, const int line)
{
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR)
    {
        std::cout << reinterpret_cast<const char*>(glewGetErrorString(error)) << std::endl;
        return false;
    }
    return true;
}

#define GLCall(x) GLClearError();\
                  x;\
                  GLLogCall(#x, __FILE__, __LINE__)