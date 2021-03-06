#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 ourColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 mvp;

void main() {
    gl_Position = mvp * vec4(aPos, 1.0);
    ourColor = vec3(0.2, 0.2, 0.2);
    TexCoord = aTexCoord;
}