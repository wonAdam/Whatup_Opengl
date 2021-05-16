#include "LightShader.h"

#include "Game.h"
#include "Camera.h"
#include "lights/Light.h"
#include "GLMacro.h"

LightShader::LightShader(const Transform* transform, Light::Type type)
    : _transform(transform), _type(type), Shader(WO_DEFAULT_VSHADER, WO_LIGHT_FSHADER)
{
}

LightShader::~LightShader()
{
}

void LightShader::Use(const std::vector<Texture>& textures) const
{
	use();

    setVec3("L_direction", _transform->GetForward());

    BindTexture(textures);

    setInt("L_type", static_cast<int>(_type));

    // Set MVP
    setMat4(WO_UNIFORM_MODEL, _transform->GetModelMatrix());
    setMat4(WO_UNIFORM_VIEW, Game::GameCamera->GetViewMatrix());
    setMat4(WO_UNIFORM_PROJ, Game::GameCamera->GetProjMatrix());
}


