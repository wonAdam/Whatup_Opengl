#pragma once
#include "Quad.h"
#include "ITransparent.h"

class Window : public Quad, public ITransparent
{
public:
	Window(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	virtual ~Window();

	virtual void Update(float deltaTime) override;
};

