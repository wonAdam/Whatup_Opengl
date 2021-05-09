#include "DefaultShader.h"

#include "GLMacro.h"
#include "Game.h"
#include "Camera.h"

DefaultShader::DefaultShader(const Transform* transform)
	: _transform(transform), Shader(WO_DEFAULT_VERTEX_SHADER, WO_DEFAULT_FRAGMENT_SHADER)
{
}

DefaultShader::~DefaultShader()
{
}

void DefaultShader::Use(const std::vector<Texture>& textures) const
{
    BindTexture(textures);

    // Set MVP
    setMat4("model", _transform->GetModelMatrix());
    setMat4("view", Game::GameCamera->GetViewMatrix());
    setMat4("proj", Game::GameCamera->GetProjMatrix());

    // Set Light
    Game::LoadLightUniform(*this);
}
