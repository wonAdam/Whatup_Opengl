#pragma once

#include <string>

class Texture
{
public:
	unsigned int _id;
	std::string _type;

public:
	Texture(const char* path, const char* type);
	virtual ~Texture();

private:
	unsigned int generate_Texture(const char* path);
};

