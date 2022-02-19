#include "PointLight.h"

PointLight::PointLight() : Light()
{
	position = glm::vec3(0, 0, 0);
	this->constant = 1.0f;
	this->linear = 0.0f;
	this->exponent = 0.0f;
}

PointLight::PointLight(
	GLfloat red, GLfloat green, GLfloat blue,
	GLfloat aIntensity, GLfloat dIntensity,
	GLfloat xPos, GLfloat yPos, GLfloat zPos,
	GLfloat constant, GLfloat linear, GLfloat exponent) : Light(red,green,blue,aIntensity,dIntensity)
{
	position = glm::vec3(xPos, yPos, zPos);
	this->constant = constant;
	this->linear = linear;
	this->exponent = exponent;
}

void PointLight::UseLight(
	GLuint ambientIntensityLocation, GLuint ambientColorLocation,
	GLuint diffuseIntensityLocation, GLuint positionLocation,
	GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation)
{
	Light::UseLight(ambientIntensityLocation, ambientColorLocation, diffuseIntensityLocation);

	glUniform3f(positionLocation, position.x, position.y, position.z);
	glUniform1f(constantLocation, constant);
	glUniform1f(linearLocation, linear);
	glUniform1f(exponentLocation, exponent);
}
