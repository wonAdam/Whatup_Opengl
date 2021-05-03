#include "Triangle.h"

#include <glm/gtc/matrix_transform.hpp>

Triangle::Triangle(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(position, rotation, scale)
{
	_shader = std::shared_ptr<Shader>(new Shader("shaders/VertexShader.vert", "shaders/FragmentShader.frag"));
	_mesh = std::shared_ptr<Mesh>(new Mesh(vertices, indices, textures));
}

Triangle::~Triangle()
{

}

void Triangle::Update(float deltaTime)
{
	_shader->setMat4("model", GetModelMatrix());

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, 10.0f));
	_shader->setMat4("view", view);

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	_shader->setMat4("proj", projection);

	_mesh->Draw(*_shader);
}
