#pragma once

#include <string>
#include <vector>

class Shader;

class Texture
{
public:
	enum class Type { DIFFUSE = 0, SPECULAR = 1 };
	static std::string TypeName[2];
	unsigned int _id;
	std::string _type;

public:
	Texture(const char* path, Texture::Type type);
	virtual ~Texture();

private:
	unsigned int generate_Texture(const char* path);
};

