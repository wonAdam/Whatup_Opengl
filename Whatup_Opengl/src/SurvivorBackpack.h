#pragma once

#include <memory>

#include "GameObject.h"
#include "Model.h"

class Shader;

class SurvivorBackpack : public GameObject
{
public:
	std::shared_ptr<Model> _model;
	std::shared_ptr<Shader> _shader;

public:
	SurvivorBackpack(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	SurvivorBackpack(const SurvivorBackpack& rhs) = delete;
	virtual ~SurvivorBackpack();

public:
	virtual void Update(float deltaTime) override;

};

