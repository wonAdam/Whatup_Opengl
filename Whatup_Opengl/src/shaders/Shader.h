#pragma once

#include <GL/glew.h>
#include <vector>
#include <string>

#include <glm/glm.hpp>

class Texture;
class DirectionalLight;
class Light;
class SpotLight;
class PointLight;
class Game;


class Shader
{
protected:
    unsigned int ID;

protected:
    virtual void Use(const std::vector<Texture>& textures) const = 0;
    friend class Mesh;
    friend class Skybox;

public:
    virtual ~Shader();

protected:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setMat4(const std::string& name, glm::mat4 value) const;
    void setVec3(const std::string& name, glm::vec3 value) const;
    virtual void BindTexture(const std::vector<Texture>& textures) const;

    friend class DirectionalLight;
    friend class Light;
    friend class SpotLight;
    friend class PointLight;
    friend class Game;

private:
    void checkCompileErrors(const unsigned int shader, const std::string type) const;
};

