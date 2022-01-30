#pragma once

#include <GL\glew.h>
#include <glm.hpp>

class Light
{
private:
	glm::vec3 color;
	GLfloat ambientIntensity;
	
	glm::vec3 direction;
	GLfloat diffuseIntensity;
public:
	Light();
	Light(
		GLfloat red, GLfloat green, GLfloat blue, 
		GLfloat aIntensity, 
		GLfloat xDir, GLfloat yDir, GLfloat zDir,
		GLfloat dIntensity);
	~Light();

	void UseLight(
		unsigned int amibuentIntensityLocation, unsigned int amibientColorLocation,
		unsigned int diffuseIntensityLocation, unsigned int directionLocation);
};

