#pragma once
#include "Shader.h"

#include "Transform.h"
#include "lights/Light.h"

class LightShader : public Shader
{
public:
	const Transform* _transform;
	Light::Type _type;

public:
	LightShader(const Transform* transform, Light::Type type);
	LightShader(const LightShader& rhs) = delete;
	LightShader& operator=(const LightShader& rhs) = delete;
	virtual ~LightShader();

protected:
	virtual void Use(const std::vector<Texture>& textures) const override;
	friend Mesh;



};

