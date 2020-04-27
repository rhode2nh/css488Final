#include "Camera.h"

Camera::Camera() {
    pos     = vec3(0.0f, 0.0f, 3.0f);
    front   = vec3(0.0f, 0.0f, -1.0f);
    up      = vec3(0.0f, 1.0f, 0.0f);
    fov     = 40.0f;
}

Camera::Camera(vec3 pos, vec3 front, vec3 up, GLfloat fov) {
    this->pos   = pos;
    this->front = front;
    this->up    = up;
    this->fov   = fov;
}

glm::mat4 Camera::getCameraView() {
    return glm::lookAt(pos, pos + front, up);
}

void Camera::modifyFov(GLfloat amount) {
    if (fov > MIN_FOV && fov < MAX_FOV)
        fov += amount;
    else if (fov <= MIN_FOV)
        fov = MIN_FOV;
    else if (fov >= MAX_FOV)
        fov = MAX_FOV;
}

void Camera::modifyPitch(GLfloat amount) {
    if (pitch > MIN_PITCH && pitch < MAX_PITCH)
        pitch += amount;
    else if (pitch <= MIN_PITCH)
        pitch = MIN_PITCH;
    else if (pitch >= MAX_PITCH)
        pitch = MAX_PITCH;
}

void Camera::modifyYaw(GLfloat amount) {
    if (yaw > MIN_YAW && yaw < MAX_YAW)
        yaw += amount;
    else if (yaw <= MIN_YAW || yaw >= MAX_YAW)
        yaw = 0.0f;
}

void Camera::moveForward(float amount) {
    pos += amount * front;
}

void Camera::moveBackward(float amount) {
    pos -= amount * front;
}

void Camera::moveLeft(float amount) {
    pos -= glm::normalize(glm::cross(front, up)) * amount;
}

void Camera::moveRight(float amount) {
    pos += glm::normalize(glm::cross(front, up)) * amount;
}