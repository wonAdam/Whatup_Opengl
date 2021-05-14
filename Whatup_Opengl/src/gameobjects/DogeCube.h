#pragma once
#include "Cube.h"
#include "IOutlineable.h"

class DogeCube : public Cube, public IOutlineable
{
public:
    DogeCube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    DogeCube(const DogeCube& rhs) = delete;
    virtual ~DogeCube();

public:
    virtual void Update(float deltaTime) override;
    virtual void LateUpdate(float deltaTime) override;
    virtual void Render(float deltaTime) override;

};

