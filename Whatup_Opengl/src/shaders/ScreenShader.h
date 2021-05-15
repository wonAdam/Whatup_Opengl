#pragma once
#include "Shader.h"
#include "GLMacro.h"
class Mesh;
class Framebuffer;

class ScreenShader : public Shader
{
public: 
	ScreenShader(
		const char* vertexPath = WO_SCREEN_DEFAULT_FSHADER, 
		const char* fragmentPath = WO_SCREEN_DEFAULT_FSHADER);
	ScreenShader(const ScreenShader& rhs) = delete;
	ScreenShader& operator=(const ScreenShader& rhs) = delete;
	virtual ~ScreenShader();

protected:
	virtual void BindTexture(const std::vector<Texture>& textures) const override;
	virtual void Use(const std::vector<Texture>& textures) const override;
	friend class Mesh;
	friend class Framebuffer;

};

