#include "OutlineShader.h"

#include "GLMacro.h"

OutlineShader::OutlineShader(Transform& transform, float scale, glm::vec3 color)
	: _transform(transform), _scale(scale), _color(color), Shader(WO_DEFAULT_VERTEX_SHADER, WO_DEFAULT_FRAGMENT_SHADER) // TODO
{
}

OutlineShader::~OutlineShader()
{
}

void OutlineShader::Use(const std::vector<Texture>& textures) const
{

}
