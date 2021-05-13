#include "ScreenShader.h"
#include "Texture.h"
#include "GLMacro.h"
ScreenShader::ScreenShader(const char* vertexPath, const char* fragmentPath)
	: Shader(vertexPath, fragmentPath)
{
}

ScreenShader::~ScreenShader()
{
}

void ScreenShader::BindTexture(const std::vector<Texture>& textures) const
{
	use();

	glBindTexture(GL_TEXTURE_2D, textures[0]._id);
	glActiveTexture(GL_TEXTURE0);
	setInt("screenTexture", 0);
}

void ScreenShader::Use(const std::vector<Texture>& textures) const
{
	BindTexture(textures);
}
