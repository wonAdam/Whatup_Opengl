#pragma once
#include "Shader.h"

#include "Transform.h"

class DefaultShader : public Shader
{
public:
	const Transform* _transform;

public:
	DefaultShader(const Transform* transform);
	DefaultShader(const DefaultShader& rhs) = delete;
	DefaultShader& operator=(const DefaultShader& rhs) = delete;
	virtual ~DefaultShader();

public:
	virtual void Use(const std::vector<Texture>& textures) const override;

};

