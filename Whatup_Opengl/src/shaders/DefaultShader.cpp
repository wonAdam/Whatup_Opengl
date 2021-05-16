#include "DefaultShader.h"

#include "GLMacro.h"
#include "Game.h"
#include "Camera.h"

DefaultShader::DefaultShader(const Transform* transform)
	: _transform(transform), Shader(WO_DEFAULT_VSHADER, WO_DEFAULT_FSHADER)
{
}

DefaultShader::~DefaultShader()
{
}

void DefaultShader::Use(const std::vector<Texture>& textures) const
{
    BindTexture(textures);

    // Set MVP
    setMat4(WO_UNIFORM_MODEL, _transform->GetModelMatrix());
    setMat4(WO_UNIFORM_VIEW, Game::GameCamera->GetViewMatrix());
    setMat4(WO_UNIFORM_PROJ, Game::GameCamera->GetProjMatrix());

    // Set Light
    Game::LoadLightUniform(*this);
}
