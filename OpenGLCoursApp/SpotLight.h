#pragma once
#include "PointLight.h"
class SpotLight :
    public PointLight
{
private:
    glm::vec3 direction;
    GLfloat edge, procEdge;

public:
    SpotLight();
    SpotLight(
        GLfloat red, GLfloat green, GLfloat blue,
        GLfloat aIntensity, GLfloat dIntensity,
        GLfloat xPos, GLfloat yPos, GLfloat zPos,
        GLfloat xDir, GLfloat yDir, GLfloat zDir,
        GLfloat constant, GLfloat linear, GLfloat exponent,
        GLfloat edge);

    void UseLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
        GLuint diffuseIntensityLocation, GLuint positionLocation,
        GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation,
        GLuint directionLocation, GLuint edgeLocation);
};