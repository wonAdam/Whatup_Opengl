#include "Light.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

Light::Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, Type type)
	: _ambient(ambient), _diffuse(diffuse), _specular(specular), _type(type)
{

}

Light::~Light()
{
}
