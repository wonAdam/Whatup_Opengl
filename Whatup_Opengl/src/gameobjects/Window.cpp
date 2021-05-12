#include "Window.h"

Window::Window(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: Quad({ Texture("img/blending_transparent_window.png", Texture::Type::DIFFUSE) }, name, position, rotation, scale)
{
}

Window::~Window()
{
}

void Window::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
