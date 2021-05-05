#include "Model.h"

#include <iostream>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Transform.h"
#include "GLMacro.h"

Model::Model(const char* path)
{
	loadModel(path);
}

Model::~Model()
{
}

void Model::Draw(Shader& shader, const Transform& transform)
{
	for (Mesh& mesh : _meshes)
		mesh.Draw(shader, transform);
}

void Model::loadModel(std::string path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}

	_directory = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		_meshes.push_back(processMesh(mesh, scene));
	}
	for(unsigned int i = 0 ; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	// process vertices
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		// positions
		float px = mesh->mVertices[i].x;
		float py = mesh->mVertices[i].y;
		float pz = mesh->mVertices[i].z;
		// normals
		float nx = mesh->mNormals[i].x;
		float ny = mesh->mNormals[i].y;
		float nz = mesh->mNormals[i].z;
		// texture coordinates
		float u = 0.0f;
		float v = 0.0f;
		if (mesh->mTextureCoords[0])
		{
			u = mesh->mTextureCoords[0][i].x;
			v = mesh->mTextureCoords[0][i].y;
		}

		Vertex vertex(px, py, pz, nx, ny, nz, u, v);

		vertices.push_back(vertex);
	}


	// process indices
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}


	// process material
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		// diffuse
		std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, Texture::Type::DIFFUSE);
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

		// specular
		std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, Texture::Type::SPECULAR);
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}

	return Mesh(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, Texture::Type textureType)
{
	std::vector<Texture> textures;

	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);

		// check if it is a already loaded texture
		bool loaded = false;
		for (auto& t : _loadedTextures)
		{
			if (std::strcmp(t._path.data(), str.C_Str()) == 0)
			{
				textures.push_back(t);
				loaded = true;
				break;
			}
		}
		
		// if not generate the texture and load it
		if (!loaded)
		{
			unsigned int textureId = Texture::LoadTextureFromFile(str.C_Str(), _directory);
			Texture texture(textureId, str.C_Str(), textureType);
			textures.push_back(texture);

			_loadedTextures.push_back(texture);
		}
	}

	return textures;
}
