#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"

class Triangle : public GameObject
{
public:
    Triangle(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    Triangle(const Triangle& rhs) = delete;
    virtual ~Triangle();

public:
    virtual void Update(float deltaTime) override;

private:
    std::shared_ptr<Mesh> _mesh;
    std::shared_ptr<Shader> _shader;
    std::vector<Vertex> vertices = {
        // positions         // normals             // tex coord
        Vertex(0.5f, -0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f, 0.0f),  // bottom right
        Vertex(-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f),  // bottom left
        Vertex(0.0f,  0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.5f, 1.0f)   // top 
    };
    std::vector<unsigned int> indices = { 0,1,2 };
    std::vector<Texture> textures = {
        Texture("img/container2.png", Texture::DIFFUSE),
        Texture("img/doge.png", Texture::DIFFUSE),
        Texture("img/container2_specular.png", Texture::SPECULAR),
    };



};

