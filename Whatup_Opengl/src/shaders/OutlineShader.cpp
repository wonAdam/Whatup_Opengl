#include "OutlineShader.h"

#include "Game.h"
#include "Camera.h"
#include "GLMacro.h"

OutlineShader::OutlineShader()
	: Shader(WO_OUTLINE_VERTEX_SHADER, WO_OUTLINE_FRAGMENT_SHADER)
{
}

OutlineShader::OutlineShader(const Transform* transform, float scale, glm::vec3 color)
	: _transform(transform), _scale(scale), _color(color), Shader(WO_OUTLINE_VERTEX_SHADER, WO_OUTLINE_FRAGMENT_SHADER) // TODO
{
}

OutlineShader::~OutlineShader()
{
}

void OutlineShader::Set(const Transform* transform, float scale, glm::vec3 color) 
{
	_transform = (transform); _scale = (scale); _color = (color);
}

void OutlineShader::Use(const std::vector<Texture>& textures) const
{
	use();

	setFloat("outlineScale", _scale);
	setVec3("outlineColor", _color);

	// Set MVP
	setMat4("model", _transform->GetModelMatrix());
	setMat4("view", Game::GameCamera->GetViewMatrix());
	setMat4("proj", Game::GameCamera->GetProjMatrix());
}
