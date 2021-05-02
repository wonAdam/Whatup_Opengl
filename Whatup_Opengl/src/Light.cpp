#include "Light.h"
#include <algorithm>

#include <GL/glew.h>

#include "Shader.h"
#include "DirectionalLight.h"
#include "SpotLight.h"
#include "PointLight.h"

unsigned char Light::lightCnt[3] = { 0, 0, 0 };
std::vector<Light*> Light::lights;

void Light::SetLightUniformValues(Shader& shader)
{
	shader.SetInt("n_of_dir_lights", lightCnt[Light::DIRECTIONAL]);
	shader.SetInt("n_of_point_lights", lightCnt[Light::POINT]);
	shader.SetInt("n_of_spot_lights", lightCnt[Light::SPOT]);

	unsigned char cnt[3] = { 0,0,0 };
	for (Light* light : lights)
		if (dynamic_cast<DirectionalLight*>(light) != nullptr)
			light->SetLightUniformValues(cnt[Light::DIRECTIONAL]++, shader);
		else if (dynamic_cast<SpotLight*>(light) != nullptr)
			light->SetLightUniformValues(cnt[Light::SPOT]++, shader);
		else if (dynamic_cast<PointLight*>(light) != nullptr)
			light->SetLightUniformValues(cnt[Light::POINT]++, shader);
}

Light::Light(glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular)
	: _diffuse(diffuse), _ambient(ambient), _specular(specular)
{
	lights.push_back(this);

	if (dynamic_cast<DirectionalLight*>(this) != nullptr)
		lightCnt[Light::DIRECTIONAL]++;
	else if (dynamic_cast<SpotLight*>(this) != nullptr)
		lightCnt[Light::SPOT]++;
	else if (dynamic_cast<PointLight*>(this) != nullptr)
		lightCnt[Light::POINT]++;

}

Light::~Light()
{
	std::remove(lights.begin(), lights.end(), this);

	if (dynamic_cast<DirectionalLight*>(this) != nullptr)
		lightCnt[Light::DIRECTIONAL]--;
	else if (dynamic_cast<SpotLight*>(this) != nullptr)
		lightCnt[Light::SPOT]--;
	else if (dynamic_cast<PointLight*>(this) != nullptr)
		lightCnt[Light::POINT]--;
}

