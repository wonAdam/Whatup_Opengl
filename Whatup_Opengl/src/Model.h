#pragma once

#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Texture.h"
#include "Transform.h"

class Mesh;
class Shader;

class Model
{
private:
	std::vector<Mesh> _meshes;
	std::string _directory;
	std::vector<Texture> _loadedTextures;

public:
	Model(const char* path);
	Model(const Model& rhs) = delete;
	virtual ~Model();

public:
	void Draw(Shader& shader, const Transform& transform, bool outline = false);

private:
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, Texture::Type textureType);
};

