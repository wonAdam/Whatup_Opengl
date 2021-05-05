#include "SurvivorBackpack.h"

#include "Model.h"

SurvivorBackpack::SurvivorBackpack(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: _model(model), _shader(shader), GameObject(name, position, rotation, scale)
{
}

SurvivorBackpack::~SurvivorBackpack()
{
}

void SurvivorBackpack::Update(float deltaTime)
{
	_model->Draw(*_shader, _transform);
}