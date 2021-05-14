#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"
#include "shaders/Shader.h"

class Triangle : public GameObject
{
public:
    Triangle(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    Triangle(std::vector<Texture> textures, std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    Triangle(const Triangle& rhs) = delete;
    virtual ~Triangle();

public:
    virtual void Update(float deltaTime) override;
    virtual void LateUpdate(float deltaTime) override;
    virtual void Render(float deltaTime) override;

protected:
    std::unique_ptr<Mesh> _mesh;
    std::unique_ptr<Shader> _shader;
    std::vector<Vertex> _vertices = {
        // positions         // normals             // tex coord
        Vertex(0.5f, -0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f, 0.0f),  // bottom right
        Vertex(-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f),  // bottom left
        Vertex(0.0f,  0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.5f, 1.0f)   // top 
    };
    std::vector<unsigned int> _indices = { 0,1,2 };
    std::vector<Texture> _textures = {
        Texture("img/container2.png", Texture::Type::DIFFUSE),
        Texture("img/doge.png", Texture::Type::DIFFUSE),
        Texture("img/container2_specular.png", Texture::Type::SPECULAR),
    };



};

