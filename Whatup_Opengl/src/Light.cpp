#include "Light.h"

Light::Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: _ambient(ambient), _diffuse(diffuse), _specular(specular)
{
}

Light::~Light()
{
}
