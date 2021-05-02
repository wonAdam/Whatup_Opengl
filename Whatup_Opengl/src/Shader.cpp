#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <GL/glew.h>

#include <glm/gtc/type_ptr.hpp>

#include "GLMacro.h"

Shader::Shader(const char* vShaderPath, const char* fShaderPath)
{
    std::string vSource, fSource;
    read_shader(vShaderPath, vSource);
    read_shader(fShaderPath, fSource);

    unsigned int vShader, fShader;
    compile_shader(vSource.c_str(), vShader);
    compile_shader(fSource.c_str(), fShader);

    create_program(vShader, fShader);
}

Shader::~Shader()
{
    GLCall(glDeleteProgram(_id));
}

void Shader::Use() const
{
    GLCall(glUseProgram(_id));
}

void Shader::SetBool(const std::string& name, bool value) const
{
    Use();
    GLCall(int location = glGetUniformLocation(_id, name.c_str()));
    GLCall(glUniform1i(location, value));
}

void Shader::SetInt(const std::string& name, int value) const
{
    Use();
    GLCall(int location = glGetUniformLocation(_id, name.c_str()));
    GLCall(glUniform1i(location, value));
}

void Shader::SetFloat(const std::string& name, float value) const
{
    Use();
    GLCall(int location = glGetUniformLocation(_id, name.c_str()));
    GLCall(glUniform1i(location, value));
}

void Shader::SetVec3(const std::string& name, glm::vec3 value) const
{
    Use();
    GLCall(int location = glGetUniformLocation(_id, name.c_str()));
    GLCall(glUniform3f(location, value.x, value.y, value.z));
}

void Shader::SetMat4(const std::string& name, glm::mat4 value) const
{
    Use();
    GLCall(int location = glGetUniformLocation(_id, name.c_str()));
    GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value)));
}

void Shader::SetSampler2D(const std::string& name, unsigned int value)
{
    Use();
    GLCall(int location = glGetUniformLocation(_id, name.c_str()));
    GLCall(glUniform1i(location, value));
}

void Shader::read_shader(const char* path, std::string& result)
{
    std::string code;
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        shaderFile.open(path);
        std::stringstream shaderStream, fShaderStream;
        // read file's buffer contents into streams
        shaderStream << shaderFile.rdbuf();
        // close file handlers
        shaderFile.close();
        // convert stream into string
        result = shaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
}

void Shader::compile_shader(const char* source, unsigned int& result)
{
    int success;

    // vertex Shader
    GLCall(result = glCreateShader(GL_VERTEX_SHADER));
    GLCall(glShaderSource(result, 1, &source, NULL));
    GLCall(glCompileShader(result));
    // print compile errors if any
    GLCall(glGetShaderiv(result, GL_COMPILE_STATUS, &success));
    if (!success)
    {
        char infoLog[512];
        GLCall(glGetShaderInfoLog(result, 512, NULL, infoLog));
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
}

void Shader::create_program(unsigned int& vShader, unsigned int& fShader)
{
    int success;

    GLCall(_id = glCreateProgram());
    GLCall(glAttachShader(_id, vShader));
    GLCall(glAttachShader(_id, fShader));
    GLCall(glLinkProgram(_id));
    // print linking errors if any
    GLCall(glGetProgramiv(_id, GL_LINK_STATUS, &success));
    if (!success)
    {
        char infoLog[512];
        GLCall(glGetProgramInfoLog(_id, 512, NULL, infoLog));
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    GLCall(glDeleteShader(vShader));
    GLCall(glDeleteShader(fShader));
}
