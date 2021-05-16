#pragma once

#include <iostream>
#include <GL/glew.h>

#ifdef TEXTURE_CPP
#define SHADER_VARIABLE_TEXTURE_DIFFUSE "diffuse"
#define SHADER_VARIABLE_TEXTURE_SPECULAR "specular"
#endif //  TEXTURE_CPP

#define WO_DEFAULT_VSHADER "shaders/Default.vert"
#define WO_DEFAULT_FSHADER "shaders/Default.frag"
#define WO_LIGHT_FSHADER "shaders/Light.frag"
#define WO_DEPTH_TESTING_FSHADER "shaders/DepthTesting.frag"
#define WO_OUTLINE_VSHADER "shaders/Outline.vert"
#define WO_OUTLINE_FSHADER "shaders/Outline.frag"
#define WO_SCREEN_DEFAULT_VSHADER "shaders/ScreenDefault.vert"
#define WO_SCREEN_DEFAULT_FSHADER "shaders/ScreenDefault.frag"
#define WO_SCREEN_INVERSE_FSHADER "shaders/ScreenInverse.frag"
#define WO_SCREEN_GRAYSCALE_FSHADER "shaders/ScreenGrayscale.frag"
#define WO_SCREEN_KERNEL_FSHADER "shaders/ScreenKernelEffect.frag"
#define WO_SKYBOX_VSHADER "shaders/Skybox.vert"
#define WO_SKYBOX_FSHADER "shaders/Skybox.frag"

#define WO_UNIFORM_MODEL "model"
#define WO_UNIFORM_VIEW "view"
#define WO_UNIFORM_PROJ "proj"

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