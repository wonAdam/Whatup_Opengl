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

private:
    std::shared_ptr<Mesh> _mesh;
    std::shared_ptr<Shader> _shader;
    std::vector<Texture> textures = {
        Texture("img/container2.png", Texture::DIFFUSE),
        Texture("img/doge.png", Texture::DIFFUSE),
        Texture("img/container2_specular.png", Texture::SPECULAR),
    };
    std::vector<Vertex> vertices = {
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

