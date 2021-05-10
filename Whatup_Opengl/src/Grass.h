#pragma once
#include "GameObject.h"
class Grass : public GameObject
{
public:
	Grass(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	Grass(const Grass& rhs) = delete;
	Grass& operator=(const Grass& rhs) = delete;
	virtual ~Grass();

public:
	virtual void Update(float deltaTime) override;
};

