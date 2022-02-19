#pragma once

#include <GL\glew.h>
#include <glm.hpp>

class Light
{
protected:
	glm::vec3 color;
	GLfloat ambientIntensity;
	GLfloat diffuseIntensity;


	void UseLight(
		GLfloat ambientIntensityLocation,
		GLfloat ambientColorLocation,
		GLfloat diffuseIntensityLocation);
public:
	Light();
	Light(
		GLfloat red, GLfloat green, GLfloat blue, 
		GLfloat aIntensity, GLfloat dIntensity);
	~Light();


};

