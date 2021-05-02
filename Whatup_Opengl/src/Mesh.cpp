#include "Mesh.h"

#include <GL/glew.h>

#include "GLMacro.h"
#include "Shader.h"
#include "Texture.h"

Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textureCoord)
	: _position(position), _normal(normal), _textureCoord(textureCoord)
{
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
	: _vertices(vertices), _indices(indices), _textures(textures)
{
	initialization();
}

Mesh::~Mesh()
{
}

void Mesh::Draw(Shader& shader)
{
    unsigned int diffuseNr = 0;
    unsigned int specularNr = 0;
    for (unsigned int i = 0; i < _textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding
        // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = _textures[i]._type;
        if (name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if (name == "texture_specular")
            number = std::to_string(specularNr++);

        shader.SetInt(("material." + name + number).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, _textures[i]._id);
    }
    glActiveTexture(GL_TEXTURE0);

    // draw mesh
    shader.Use();
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
