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
	std::string _path;

public:
	Texture(const char* path, Texture::Type type);
	Texture(unsigned int id, const char* path, Texture::Type type);
	Texture(unsigned int id);
	virtual ~Texture();

	static unsigned int LoadTextureFromFile(const char* path, std::string& directory, bool gamma = false);

private:
	unsigned int generate_Texture(const char* path);
};

