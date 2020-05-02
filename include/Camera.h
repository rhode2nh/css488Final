#ifndef Camera_h
#define Camera_h

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define MIN_FOV 1.0f
#define MAX_FOV 200.0f

#define MIN_PITCH -89.0f
#define MAX_PITCH 89.0f

#define MIN_YAW -360.0f
#define MAX_YAW 360.0f

using namespace glm;

class Camera {
 public:
    vec3 pos;
    vec3 front;
    vec3 up;

    GLfloat fov;

    GLfloat yaw = -90.0f;
    GLfloat pitch = 0.0f;

    /**
     * Default constructor for the camera.
     */
    Camera();

    /**
     * Constructor for the camera.
     * \param pos the position of the camera in worldspace
     * \param front the vector that defines the front direction
     * \param up the vector that defines the up direction
     */
    Camera(vec3 pos, vec3 front, vec3 up, GLfloat fov);

    /**
     * Returns the camera's POV
     * \return the POV
     */
    glm::mat4 getCameraView();

    /**
     * Modify the fov with the given amount.
     * \param amount the amount to modify the fov by.
     */
    void modifyFov(GLfloat amount);

    /**
     * Modify the pitch.
     * \param amount The amount to modify the pitch.
     */
    void modifyPitch(GLfloat amount);

    /**
     * Modify the yaw.
     * \param amount The amount to modify the yaw.
     */
    void modifyYaw(GLfloat amount);

    /**
     * Move the camera forward.
     * \param amount The amount to move camera forward.
     */
    void moveForward(float amount);

    /**
     * Move the camera backward.
     * \param amount The amount to move camera backward.
     */
    void moveBackward(float amount);
    
    /**
     * Move the camera left.
     * \param amount The amount to move camera left.
     */    
    void moveLeft(float amount);
    
    /**
     * Move the camera right.
     * \param amount The amount to move camera right.
     */
    void moveRight(float amount);
};

#endif