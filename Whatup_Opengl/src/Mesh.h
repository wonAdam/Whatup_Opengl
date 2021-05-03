#pragma once

#include <vector>

#include <glm/glm.hpp>


struct Transform;
class Texture;
class Shader;


struct Vertex
{
	glm::vec3 _position;
	glm::vec3 _normal;
	glm::vec2 _textureCoord;
	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textureCoord);
	Vertex(float px, float py, float pz, float nx, float ny, float nz, float s, float t);
};

class Mesh
{
public:
	std::vector<Vertex> _vertices;
	std::vector<unsigned int> _indices;
	std::vector<Texture> _textures;

private:
	unsigned int _VAO, _VBO, _EBO;

public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	virtual ~Mesh();

	void Draw(Shader& shader, const Transform& transform);

private:
	void initialization();
};

