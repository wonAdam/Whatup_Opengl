#include "Framebuffer.h"

#include <iostream>

#include <GL/glew.h>

#include "Texture.h"
#include "Game.h"
#include "GLMacro.h"

Framebuffer::Framebuffer(std::shared_ptr<ScreenShader>& shader)
	: _shader(shader)
{
	// Framebuffer
	GLCall(glGenFramebuffers(1, &_FBO));
	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, _FBO));

	// color buffer
	GLCall(glGenTextures(1, &_texColorBuffer));
	GLCall(glBindTexture(GL_TEXTURE_2D, _texColorBuffer));
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Game::winWidth, Game::winHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texColorBuffer, 0));

	// depth & stencil buffer
	GLCall(glGenRenderbuffers(1, &_RBO));
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, _RBO));
	GLCall(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, Game::winWidth, Game::winHeight));
	GLCall(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _RBO));

	GLCall(GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER));
	if(status != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));

	// VAO & VBO
	GLCall(glGenVertexArrays(1, &_quadVAO));
	GLCall(glGenBuffers(1, &_quadVBO));
	GLCall(glBindVertexArray(_quadVAO));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _quadVBO));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), &_vertices[0], GL_STATIC_DRAW));
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0));
	GLCall(glEnableVertexAttribArray(1));
	GLCall(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float))));
}

Framebuffer::~Framebuffer()
{
}

void Framebuffer::Bind(bool self)
{
	glBindFramebuffer(GL_FRAMEBUFFER, self ? _FBO : 0);
	if (self) {
		GLCall(glEnable(GL_DEPTH_TEST));
		GLCall(glClearColor(0.1f, 0.1f, 0.1f, 1.0f));
	}
	else {
		GLCall(glDisable(GL_DEPTH_TEST));
		GLCall(glClearColor(0.9f, 0.9f, 0.9f, 1.0f));
	}

	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
}


void Framebuffer::Draw()
{
	_shader->use();
	GLCall(glBindVertexArray(_quadVAO));
	GLCall(glBindTexture(GL_TEXTURE_2D, _texColorBuffer));	// use the color attachment texture as the texture of the quad plane
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
}
