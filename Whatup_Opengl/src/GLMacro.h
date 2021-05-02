#pragma once

#include <iostream>
#include <GL/glew.h>
inline static void GLClearError() { while (glGetError() != GL_NO_ERROR); }

static bool GLLogCall(const char* function, const char* file, const int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << reinterpret_cast<const char*>(glewGetErrorString(error)) << std::endl;
        return false;
    }
    return true;
}

#define GLCall(x) GLClearError();\
                  x;\
                  GLLogCall(#x, __FILE__, __LINE__)