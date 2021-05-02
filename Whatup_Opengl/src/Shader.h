#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <string>

class Shader
{
public:
	unsigned int _id;

public:
	Shader(const char* vShader, const char* fShader);
	Shader(const Shader& rhs) = delete;
	virtual ~Shader();
	void Use() const;
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetVec3(const std::string& name, glm::vec3 value) const;
	void SetMat4(const std::string& name, glm::mat4 value) const;
	void SetSampler2D(const std::string& name, unsigned int value);

private:
	void read_shader(const char* path, std::string& result);
	void compile_shader(const char* source, unsigned int& result, GLenum type);
	void create_program(unsigned int& vShader, unsigned int& fShader);
};

