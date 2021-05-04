#pragma once

#include <GL/glew.h>
#include <vector>
#include <string>

#include <glm/glm.hpp>

class Texture;

class Shader
{
public:
    unsigned int ID;
    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setMat4(const std::string& name, glm::mat4 value) const;
    void setVec3(const std::string& name, glm::vec3 value) const;

    void BindTexture(const std::vector<Texture>& textures) const;

private:
    void checkCompileErrors(const unsigned int shader, const std::string type) const;
};

