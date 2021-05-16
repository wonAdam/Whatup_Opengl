#include "SkyboxShader.h"

#include "glm/glm.hpp"

#include "GLMacro.h"
#include "Texture.h"
#include "Game.h"
#include "Camera.h"


SkyboxShader::SkyboxShader()
	: Shader(WO_SKYBOX_VSHADER, WO_SKYBOX_FSHADER)
{
}

SkyboxShader::~SkyboxShader()
{
}

void SkyboxShader::BindTexture(const std::vector<Texture>& textures) const
{
	use();
	glActiveTexture(GL_TEXTURE0);
	setInt("skybox", 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textures[0]._id);
}

void SkyboxShader::Use(const std::vector<Texture>& textures) const
{
	use();

	BindTexture(textures);

	setMat4(WO_UNIFORM_VIEW, glm::mat4(glm::mat3(Game::GameCamera->GetViewMatrix())));
	setMat4(WO_UNIFORM_PROJ, Game::GameCamera->GetProjMatrix());
}
