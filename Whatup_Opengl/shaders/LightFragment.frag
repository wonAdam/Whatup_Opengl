#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

struct Material {
    // diffuse;
    sampler2D diffuse0;
    sampler2D diffuse1;
    sampler2D diffuse2;

    sampler2D specular0;
    sampler2D specular1;
    float shininess;
}; 
uniform Material material;

int DIR_LIGHT = 0;
int POINT_LIGHT = 1;
int SPOT_LIGHT = 2;
uniform int L_type;
uniform vec3 L_direction;

void main()
{
    vec3 mix_diffuse = vec3(texture(material.diffuse0, TexCoord) + 
                            texture(material.diffuse1, TexCoord) + 
                            texture(material.diffuse2, TexCoord)) / 3; 

    vec3 mix_specular = vec3(texture(material.specular0, TexCoord) + 
                            texture(material.specular1, TexCoord)) / 2; 

    if(L_type == POINT_LIGHT)
    {
        FragColor = vec4(mix_diffuse + mix_specular, 0.0);
    }
    else{
        float theta = dot(Normal, normalize(L_direction));
        if(theta > 0.9)
        {
            FragColor = vec4(mix_diffuse + mix_specular, 0.0);
        }
        else
        {
            FragColor = vec4(0.0);
        }
    }

} 
