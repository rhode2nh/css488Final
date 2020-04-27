#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Mesh.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Model {
public:
    /* functions */
    Model(string const &path) {
        loadModel(path);
    }

    void Draw(Shader shader);
private:
    /* Model data */
    vector<Mesh> meshes;
    vector<Texture> textures_loaded;
    string directory;
    /* Functions */
    void loadModel(string const &path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};