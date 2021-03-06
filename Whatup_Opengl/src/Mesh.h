#pragma once

#include <vector>

#include <glm/glm.hpp>
#include "shaders/OutlineShader.h"

struct Transform;
class Texture;
class Shader;
class ScreenShader;

struct Vertex
{
	glm::vec3 _position;
	glm::vec3 _normal;
	glm::vec2 _textureCoord;
	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textureCoord);
	Vertex(float px, float py, float pz, float nx, float ny, float nz, float u, float v);
};

class Mesh
{
public:
	std::vector<Vertex> _vertices;
	std::vector<unsigned int> _indices;
	std::vector<Texture> _textures;
	OutlineShader _olShader;

public:
	unsigned int _VAO, _VBO, _EBO;

public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	Mesh(std::vector<Vertex> vertices, std::vector<Texture> textures);
	virtual ~Mesh();

	void Draw(const Shader& shader, const Transform& transform, bool outline = false);
	void Draw(const ScreenShader& shader);

private:
	void initialization();
};

