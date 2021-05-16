#include "Skybox.h"

#include "shaders/SkyboxShader.h"
#include "GLMacro.h"

Skybox::Skybox(std::vector<std::string> faces)
	: _texture(Texture::LoadSkyboxTexture(faces)), _shader(std::make_unique<SkyboxShader>())
{
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);

	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);

	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(float), &_vertices[0], GL_STATIC_DRAW);

	// vertex positions
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
}

Skybox::~Skybox()
{
}

void Skybox::Render()
{
	GLCall(glDepthMask(GL_FALSE));
	GLCall(glBindVertexArray(_VAO));
	_shader->Use({ _texture });
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
	GLCall(glDepthMask(GL_TRUE));
	glBindVertexArray(0);
}
