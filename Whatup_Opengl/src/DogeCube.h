#pragma once
#include "Cube.h"
class DogeCube : public Cube
{
public:
    DogeCube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    DogeCube(const DogeCube& rhs) = delete;
    virtual ~DogeCube();

public:
    virtual void Update(float deltaTime) override;

};

