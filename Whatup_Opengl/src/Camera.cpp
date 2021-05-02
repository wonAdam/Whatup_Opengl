#include "Camera.h"

#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Game.h"

Camera::Camera(glm::vec3 position, glm::vec3 rotation)
    : GameObject(position, rotation, glm::vec3(1.0f))
{
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(
        glm::vec3(0.0f, 0.0f, 5.0f), 
        glm::vec3(0.0f, 0.0f, 5.0f) + Game::Instance->_gameObjects[0]->_position,
        glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::GetProjMatrix()
{
    return glm::perspective(glm::radians(Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        _position += GetForward() * velocity;
    if (direction == BACKWARD)
        _position -= GetForward() * velocity;
    if (direction == LEFT)
        _position -= GetRight() * velocity;
    if (direction == RIGHT)
        _position += GetRight() * velocity;
    if (direction == DOWN)
        _position -= GetUp() * velocity;
    if (direction == UP)
        _position += GetUp() * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    _rotation.y += xoffset;
    _rotation.x += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (_rotation.x > 89.0f)
            _rotation.x = 89.0f;
        if (_rotation.x < -89.0f)
            _rotation.x = -89.0f;
    }
}

void Camera::Update(float deltaTime)
{
}
