#pragma once
#include "Shader.h"
class SkyboxShader : public Shader
{
public:
	SkyboxShader();
	SkyboxShader(const SkyboxShader& rhs) = delete;
	SkyboxShader& operator=(const SkyboxShader& rhs) = delete;
	virtual ~SkyboxShader();

public:
	virtual void BindTexture(const std::vector<Texture>& textures) const override;
	virtual void Use(const std::vector<Texture>& textures) const override;

};

