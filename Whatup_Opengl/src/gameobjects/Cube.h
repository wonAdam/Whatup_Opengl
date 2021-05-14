#pragma once
#include <memory>
#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"
#include "shaders/Shader.h"

class Cube : public GameObject
{
public:
	Cube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	Cube(const Cube& rhs) = delete;
	virtual ~Cube();

public:
	virtual void Update(float deltaTime) override;
    virtual void LateUpdate(float deltaTime) override;
    virtual void Render(float deltaTime) override;

protected:
    std::unique_ptr<Mesh> _mesh;
    std::unique_ptr<Shader> _shader;
    std::vector<Texture> _textures = {
        Texture("img/default_texture.jpg", Texture::Type::DIFFUSE),
        Texture("img/default_texture.jpg", Texture::Type::SPECULAR),
    };

    std::vector<Vertex> _vertices = {
        // Back face
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f), // Bottom-left
    Vertex( 0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 1.0f), // top-right
    Vertex( 0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 0.0f), // bottom-right         
    Vertex( 0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 1.0f), // top-right
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f), // bottom-left
    Vertex(-0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 1.0f), // top-left
    // Front face
    Vertex(-0.5f, -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f), // bottom-left
    Vertex( 0.5f, -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 0.0f), // bottom-right
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 1.0f), // top-right
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 1.0f), // top-right
    Vertex(-0.5f,  0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f), // top-left
    Vertex(-0.5f, -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f), // bottom-left
    // Left face
    Vertex(-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f), // top-right
    Vertex(-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f), // top-left
    Vertex(-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f), // bottom-left
    Vertex(-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f), // bottom-left
    Vertex(-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f), // bottom-right
    Vertex(-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f), // top-right
    // Right face
    Vertex( 0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f), // top-left
    Vertex( 0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 1.0f), // bottom-right
    Vertex( 0.5f,  0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 1.0f), // top-right         
    Vertex( 0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 1.0f), // bottom-right
    Vertex( 0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f), // top-left
    Vertex( 0.5f, -0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 0.0f), // bottom-left     
    // Bottom face
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 1.0f), // top-right
    Vertex( 0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 1.0f), // top-left
    Vertex( 0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f), // bottom-left
    Vertex( 0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f), // bottom-left
    Vertex(-0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 0.0f), // bottom-right
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 1.0f), // top-right
    // Top face
    Vertex(-0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 1.0f), // top-left
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f), // bottom-right
    Vertex( 0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 1.0f), // top-right     
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f), // bottom-right
    Vertex(-0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 1.0f), // top-left
    Vertex(-0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 0.0f)  // bottom-left
    };
};

