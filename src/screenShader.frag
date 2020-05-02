#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;

void main() {
    // vec2 uv;
    // uv.x = gl_FragCoord.x / 1280;
    // uv.y = gl_FragCoord.y / 720;
    // FragColor = texture(screenTexture, uv);
    FragColor = texture(screenTexture, TexCoords);
}