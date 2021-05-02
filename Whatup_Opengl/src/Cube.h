#pragma once

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "GameObject.h"

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

class Cube : public GameObject
{
public:
	std::shared_ptr<Mesh> _mesh;
	std::shared_ptr<Shader> _shader;

public:
	Cube(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Shader* shader);
	Cube(const Cube& rhs) = delete;
	virtual ~Cube();
	virtual void Update(float deltaTime) override;


private:
    std::vector<Texture> _textures = {
        Texture("img/container2.png", "diffuse"),
        Texture("img/doge.png", "diffuse"),
        Texture("img/container2_specular.png", "specular")
    };
    std::vector<Vertex> _vertices = {
        // positions          // normals           // texture coords
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f),  glm::vec2(0.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f),  glm::vec2(0.0f,  0.0f)),
        
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f),  glm::vec2(0.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f),  glm::vec2(0.0f,  0.0f)),
        
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f),  glm::vec2(0.0f,  0.0f)),
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        
        Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f),  glm::vec2(0.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f),  glm::vec2(0.0f,  0.0f)),
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f),  glm::vec2(0.0f,  1.0f)),
        
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  1.0f,  0.0f),  glm::vec2(0.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  1.0f,  0.0f),  glm::vec2(1.0f,  1.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  1.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  1.0f,  0.0f),  glm::vec2(1.0f,  0.0f)),
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  1.0f,  0.0f),  glm::vec2(0.0f,  0.0f)),
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  1.0f,  0.0f),  glm::vec2(0.0f,  1.0f))
    };
};

