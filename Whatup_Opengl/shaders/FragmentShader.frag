#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

struct Material
{
    sampler2D diffuse0;
    sampler2D diffuse1;
    sampler2D diffuse2;
};

uniform Material material;

void main()
{
    FragColor = (texture(material.diffuse0, TexCoord) + texture(material.diffuse0, TexCoord) + texture(material.diffuse0, TexCoord)) / 3;
}