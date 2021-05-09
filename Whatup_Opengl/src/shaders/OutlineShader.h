#pragma once
#include "Shader.h"

#include "Transform.h"

class OutlineShader : public Shader
{
public:
	const Transform* _transform;
	float _scale;
	glm::vec3 _color;

public:
	OutlineShader();
	OutlineShader(const Transform* transform, float scale, glm::vec3 color);
	OutlineShader& operator=(const OutlineShader& rhs) = delete;
	virtual ~OutlineShader();

public:
	void Set(const Transform* transform, float scale, glm::vec3 color);
	virtual void Use(const std::vector<Texture>& textures) const override;

};

