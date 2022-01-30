#include "Camera.h"

void Camera::update()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}

Camera::Camera()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	yaw = -90.0f;
	pitch = 0.0f;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

	movementSpeed = 5.0f;
	turnSpeed = 0.5f;
	update();
}

Camera::Camera(
	glm::vec3 startPosition, glm::vec3 startUp, 
	GLfloat startYaw, GLfloat startPitch, 
	GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

	movementSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;
	update();
}

void Camera::keyControl(bool* keys, GLfloat deltaTime)
{
	if (keys[GLFW_KEY_W]) {
		position += front * movementSpeed * deltaTime;
	}

	if (keys[GLFW_KEY_S]) {
		position -= front * movementSpeed * deltaTime;
	}

	if (keys[GLFW_KEY_D]) {
		position += right * movementSpeed * deltaTime;
	}

	if (keys[GLFW_KEY_A]) {
		position -= right * movementSpeed * deltaTime;
	}

	if (keys[GLFW_KEY_SPACE]) {
		position += worldUp * movementSpeed * deltaTime;
	}

	if (keys[GLFW_KEY_C]) {
		position -= worldUp * movementSpeed * deltaTime;
	}
}

void Camera::mouseControl(GLfloat xChange, GLfloat yChange)
{
	xChange *= turnSpeed;
	yChange *= turnSpeed;

	yaw += xChange;
	pitch += yChange;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	update();
}

glm::mat4 Camera::calculateViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}
