#include "Mesh.h"

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "GLMacro.h"
#include "Shader.h"
#include "Texture.h"
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"
#include "Camera.h"

Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textureCoord)
    : _position(position), _normal(normal), _textureCoord(textureCoord)
{
}

Vertex::Vertex(float px, float py, float pz, float nx, float ny, float nz, float s, float t)
    : _position(glm::vec3(px, py, pz)), _normal(glm::vec3(nx, ny, nz)), _textureCoord(glm::vec2(s, t))
{
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
    : _vertices(vertices), _indices(indices), _textures(textures)
{
    initialization();
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<Texture> textures)
    : _vertices(vertices), _textures(textures)
{
    for(unsigned int i = 0 ; i < vertices.size(); i++)
        _indices.push_back(i);

    initialization();
}

Mesh::~Mesh()
{
}

void Mesh::Draw(const Shader& shader, const Transform& transform) const
{
    shader.BindTexture(_textures);

    // Set MVP
    shader.setMat4("model", transform.GetModelMatrix());
    shader.setMat4("view", Game::GameCamera->GetViewMatrix());
    shader.setMat4("proj", Game::GameCamera->GetProjMatrix());

    // Set Light
    Game::LoadLightUniform(shader);

    // draw mesh
    glBindVertexArray(_VAO);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}

void Mesh::initialization()
{
    GLCall(glGenVertexArrays(1, &_VAO));
    GLCall(glGenBuffers(1, &_VBO));
    GLCall(glGenBuffers(1, &_EBO));

    GLCall(glBindVertexArray(_VAO));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, _VBO));

    GLCall(glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW));

    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int),
        &_indices[0], GL_STATIC_DRAW));

    // vertex positions
    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, _position)));
    // vertex normals
    GLCall(glEnableVertexAttribArray(1));
    GLCall(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, _normal)));
    // vertex texture coords
    GLCall(glEnableVertexAttribArray(2));
    GLCall(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, _textureCoord)));

    GLCall(glBindVertexArray(0));
}
