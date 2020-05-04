#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "Model.h"
#include "Shader.h"
#include "Camera.h"

#include <iostream>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

GLFWwindow* setupWindow();
void processInput(GLFWwindow *window, Camera &camera);
void processPortalPerspective(GLFWwindow *window, Camera &portalCamera);

struct MVP {
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 mvp = glm::mat4(1.0f);
};

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

float deltaTime = 0.0f; // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

float lastX = SCR_WIDTH / 2, lastY = SCR_HEIGHT / 2;

Camera camera;
Camera *portalCamera = new Camera();

int main() {

    // Setup window
    GLFWwindow* window;
    window = setupWindow();

    // setup shaders and vars
    Shader playerShader("../../src/playerShader.vert", "../../src/playerShader.frag");
    Shader portalShader("../../src/portalShader.vert", "../../src/portalShader.frag");
    Model model("../../models/house/house_obj.obj");
    glm::vec2 uv = glm::vec2(1.0f / (float)SCR_WIDTH, 1.0f / (float)SCR_HEIGHT);
    MVP mvp;

    // framebuffer
    // ----------------------------------------------------------
    GLuint fbo;
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    // texture
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // attach texture to framebuffer
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);    

    // render buffer
    GLuint rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);


    // Quad that will be used as the portal
    float quadVertices[] = {
        -1.78f,  1.0f, 0.0f,
        -1.78f, -1.0f, 0.0f,
         1.78f, -1.0f, 0.0f,

        -1.78f,  1.0f, 0.0f,
         1.78f, -1.0f, 0.0f,
         1.78f,  1.0f, 0.0f
    };

    GLuint quadVAO, VBO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    glBindVertexArray(quadVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Shader configuration
    portalShader.use();
    portalShader.setInt("portalTexture", 0);
    portalShader.setVec2("uv", uv);

    playerShader.use();
    playerShader.setInt("texture1", 0);
    // -----------------------------------------------------------

    // Callbacks
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(window, lastX, lastY);    

    glEnable(GL_DEPTH_TEST);

    // Render Loop
    while (!glfwWindowShouldClose(window)) {

        // callbacks
        glfwSetCursorPosCallback(window, mouse_callback);
        glfwSetScrollCallback(window, scroll_callback);

        // calculate deltatime
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Render the "portal's" view first
        //--------------------------------------------------------------------------------
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        processPortalPerspective(window, *portalCamera);
        portalCamera->pos = camera.pos;
        portalCamera->fov = camera.fov;

        // scale and translate model
        mvp.model = glm::mat4(1.0f);
        mvp.model = glm::scale(mvp.model, glm::vec3(0.01f));
        mvp.model = glm::translate(mvp.model, glm::vec3(0.0f, -300.0f, -800.0f));
        mvp.projection = glm::perspective(glm::radians(portalCamera->fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        mvp.view = portalCamera->getCameraView();

        playerShader.use();
        mvp.mvp = mvp.projection * mvp.view * mvp.model;
        playerShader.setMat4("mvp", mvp.mvp);
        model.Draw(playerShader);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        
        // Render the player's perspective
        //--------------------------------------------------------------------------------

        // Process input
        processInput(window, camera);

        glDisable(GL_DEPTH_TEST);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        portalShader.use();
        mvp.model = glm::mat4(1.0f);
        mvp.projection = glm::perspective(glm::radians((camera.fov)), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        mvp.view = camera.getCameraView();
        mvp.mvp = mvp.projection * mvp.view * mvp.model;
        portalShader.use();
        portalShader.setMat4("mvp", mvp.mvp);

        // Render the portal in the player's view
        glBindVertexArray(quadVAO);
        glBindTexture(GL_TEXTURE_2D, texture);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void frame_buffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    float xoffset = xpos - lastX;
    float yoffset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;

    const float sensitivity = 0.05f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera.modifyYaw(xoffset);
    camera.modifyPitch(yoffset);
    portalCamera->modifyYaw(xoffset);
    portalCamera->modifyPitch(yoffset);

    glm::vec3 direction;
    direction.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    direction.y = sin(glm::radians(-camera.pitch));
    direction.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.front = glm::normalize(direction);
    portalCamera->front = glm::normalize(direction);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.modifyFov(yoffset);
}

GLFWwindow* setupWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Final", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }
    return window;
}

void processInput(GLFWwindow *window, Camera &camera) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    const float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.moveForward(cameraSpeed);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.moveBackward(cameraSpeed);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.moveLeft(cameraSpeed);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.moveRight(cameraSpeed);
}

void processPortalPerspective(GLFWwindow *window, Camera &portalCamera) {
    const float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        portalCamera.moveForward(cameraSpeed);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        portalCamera.moveBackward(cameraSpeed);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        portalCamera.moveLeft(cameraSpeed);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        portalCamera.moveRight(cameraSpeed);
}
