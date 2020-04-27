#include <glad/glad.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include "Shader.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    GLuint id;
    std::string type;
    std::string path;
};

using namespace std;

class Mesh {
 public:
    /* Mesh Data */
    vector<Vertex> vertices;
    vector<GLuint> indices;
    vector<Texture> textures;

    /* Functions */
    Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
    void Draw(Shader shader);
 private:
    /* Render Data */
    GLuint VAO, VBO, EBO;
    /* Functions */
    void setupMesh();
};