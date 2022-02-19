#pragma once
#include "Light.h"


class DirectionalLight :
    public Light
{
private:
	glm::vec3 direction;

public:
	DirectionalLight();
	DirectionalLight(
		GLfloat red, GLfloat green, GLfloat blue,
		GLfloat aIntensity, GLfloat dIntensity,
		GLfloat xDir, GLfloat yDir, GLfloat zDir);
	~DirectionalLight();

	void UseLight(
		GLfloat ambuentIntensityLocation, GLfloat ambientColorLocation,
		GLfloat diffuseIntensityLocation, GLfloat directionLocation);
};

