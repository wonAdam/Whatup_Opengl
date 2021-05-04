#pragma once
#include <memory>
#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"

class Cube : public GameObject
{
public:
	Cube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	Cube(const Cube& rhs) = delete;
	virtual ~Cube();

public:
	virtual void Update(float deltaTime) override;

protected:
    std::shared_ptr<Mesh> _mesh;
    std::shared_ptr<Shader> _shader;
    std::vector<Texture> _textures = {
        Texture("img/default_texture.jpg", Texture::Type::DIFFUSE),
        Texture("img/default_texture.jpg", Texture::Type::SPECULAR),
    };
    std::vector<Vertex> _vertices = {
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f),
    Vertex( 0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 0.0f),
    Vertex( 0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 1.0f),
    Vertex( 0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 1.0f),
    Vertex(-0.5f,  0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 1.0f),
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f),
    
    Vertex(-0.5f, -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  0.0f, 0.0f),
    Vertex( 0.5f, -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  1.0f, 0.0f),
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f),
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f),
    Vertex(-0.5f,  0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  0.0f, 1.0f),
    Vertex(-0.5f, -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  0.0f, 0.0f),
    
    Vertex(-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
    Vertex(-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f),
    Vertex(-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
    Vertex(-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
    Vertex(-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f),
    Vertex(-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
   
    Vertex( 0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
    Vertex( 0.5f,  0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 1.0f),
    Vertex( 0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
    Vertex( 0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
    Vertex( 0.5f, -0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 0.0f),
    Vertex( 0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
    
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 1.0f),
    Vertex( 0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 1.0f),
    Vertex( 0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f),
    Vertex( 0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f),
    Vertex(-0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 0.0f),
    Vertex(-0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 1.0f),
    
    Vertex(-0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 1.0f),
    Vertex( 0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 1.0f),
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f),
    Vertex( 0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f),
    Vertex(-0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 0.0f),
    Vertex(-0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 1.0f)
    };
};

