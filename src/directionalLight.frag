#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform float u_time;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;
  
void main()
{
    vec3 lightDir = normalize(-light.direction);
    // ambient light
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

    // diffuse light
    vec3 norm = normalize(Normal);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

    // specular light
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 16);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

    FragColor = vec4(ambient + diffuse + specular, 1.0);
}