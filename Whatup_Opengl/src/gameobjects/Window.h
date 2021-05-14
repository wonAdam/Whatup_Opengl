#pragma once
#include "Quad.h"
#include "ITransparent.h"

class Window : public Quad, public ITransparent
{
public:
	Window(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	virtual ~Window();

public:
	virtual void Update(float deltaTime) override;
	virtual void LateUpdate(float deltaTime) override;
	virtual void Render(float deltaTime) override;

};

