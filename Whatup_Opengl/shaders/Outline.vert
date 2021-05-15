#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform float outlineScale;

void main()
{
    mat4 scaleMat = mat4(outlineScale, 0.0, 0.0, 0.0,
                        0.0, outlineScale, 0.0, 0.0,
                        0.0, 0.0, outlineScale, 0.0,
                        0.0, 0.0, 0.0, 1.0);

    gl_Position = proj * view * model * scaleMat * vec4(aPos, 1.0);
}