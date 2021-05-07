#pragma once
#include "Shader.h"

#include "Transform.h"

class OutlineShader : public Shader
{
public:
	Transform& _transform;
	float _scale;
	glm::vec3 _color;

public:
	OutlineShader(Transform& transform, float scale, glm::vec3 color);
	OutlineShader(const OutlineShader& rhs) = delete;
	OutlineShader& operator=(const OutlineShader& rhs) = delete;
	virtual ~OutlineShader();

public:
	virtual void Use(const std::vector<Texture>& textures) const override;

};

