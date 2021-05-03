//#pragma once
//
//#include <vector>
//#include <string>
//
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>
//
//class Mesh;
//class Shader;
//class Texture;
//
//class Model
//{
//private:
//	std::vector<Mesh> _meshes;
//	std::string _directory;
//
//public:
//	Model(const char* path);
//	Model(const Model& rhs) = delete;
//	virtual ~Model();
//
//public:
//	void Draw(Shader& shader, const Transform& transform);
//
//private:
//	void loadModel(std::string path);
//	void processNode(aiNode* node, const aiScene* scene);
//	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
//	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
//};
//
