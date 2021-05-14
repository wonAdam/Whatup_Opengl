#pragma once

#include <memory>
#include "Mesh.h"
#include "gameobjects/Quad.h"
#include "shaders/ScreenShader.h"

class Framebuffer
{
private:
	unsigned int _FBO;
	unsigned int _RBO;
	unsigned int _texColorBuffer;
	unsigned int _quadVAO;
	unsigned int _quadVBO;
	std::shared_ptr<ScreenShader> _shader;

public:
	Framebuffer(std::shared_ptr<ScreenShader>& shader);
	Framebuffer(const Framebuffer& rhs) = delete;
	Framebuffer& operator=(const Framebuffer& rhs) = delete;
	virtual ~Framebuffer();

public:
	void Bind(bool self = true);
	void Draw();

private:
	float _vertices[24] = {
		// positions // tex coord
		1.0f, -1.0f, 1.0f, 0.0f,  // bottom right
		-1.0f,  1.0f, 0.0f, 1.0f,   // top left
		-1.0f, -1.0f, 0.0f, 0.0f,  // bottom left
		-1.0f,  1.0f, 0.0f, 1.0f,   // top left
		1.0f, -1.0f, 1.0f, 0.0f,  // bottom right
		1.0f,  1.0f, 1.0f, 1.0f   // top right
	};
};

