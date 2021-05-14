#include "SurvivorBackpack.h"

#include "Model.h"
#include "shaders/DefaultShader.h"
#include "GLMacro.h"

SurvivorBackpack::SurvivorBackpack(std::shared_ptr<Model> model, std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: _model(model), 
	_shader(new DefaultShader(&_transform)), 
	GameObject(name, position, rotation, scale)
{
}

SurvivorBackpack::~SurvivorBackpack()
{
}

void SurvivorBackpack::Update(float deltaTime)
{
}

void SurvivorBackpack::LateUpdate(float deltaTime)
{
}

void SurvivorBackpack::Render(float deltaTime)
{
	_model->Draw(*_shader, _transform, _outline);
}
