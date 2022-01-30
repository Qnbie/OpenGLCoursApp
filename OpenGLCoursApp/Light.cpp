#include "Light.h"

Light::Light()
{
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;

	direction = glm::vec3(0.0f, -1.0f, 0.0f);
	diffuseIntensity = 1.0f;
}

Light::Light(
	GLfloat red, GLfloat green, GLfloat blue, 
	GLfloat aIntensity,
	GLfloat xDir, GLfloat yDir, GLfloat zDir,
	GLfloat dIntensity)
{
	color = glm::vec3(red, green, blue);
	ambientIntensity = aIntensity;

	direction = glm::vec3(xDir, yDir, zDir);
	diffuseIntensity = dIntensity;
}

Light::~Light()
{}

void Light::UseLight(
	unsigned int amibientIntensityLocation, unsigned int amibientColorLocation,
	unsigned int diffuseIntensityLocation, unsigned int directionLocation)
{
	glUniform3f(amibientColorLocation, color.x, color.y, color.z);
	glUniform1f(amibientIntensityLocation, ambientIntensity);

	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
}
