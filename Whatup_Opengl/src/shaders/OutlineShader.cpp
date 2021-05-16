#include "OutlineShader.h"

#include "Game.h"
#include "Camera.h"
#include "GLMacro.h"

OutlineShader::OutlineShader()
	: Shader(WO_OUTLINE_VSHADER, WO_OUTLINE_FSHADER)
{
}

OutlineShader::OutlineShader(const Transform* transform, float scale, glm::vec3 color)
	: _transform(transform), _scale(scale), _color(color), Shader(WO_OUTLINE_VSHADER, WO_OUTLINE_FSHADER) // TODO
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
	setMat4(WO_UNIFORM_MODEL, _transform->GetModelMatrix());
	setMat4(WO_UNIFORM_VIEW, Game::GameCamera->GetViewMatrix());
	setMat4(WO_UNIFORM_PROJ, Game::GameCamera->GetProjMatrix());
}
