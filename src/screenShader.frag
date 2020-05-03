#version 330 core
out vec4 FragColor;

uniform sampler2D screenTexture;
uniform vec2 uv;

void main() {
    vec2 uvTex = uv.xy * gl_FragCoord.xy;
    FragColor = texture(screenTexture, uvTex);
}