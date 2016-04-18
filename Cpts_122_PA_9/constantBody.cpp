#include "Body.h"

constantBody::constantBody(double initMass = 0, double initxPos = 0, double inityPos = 0, double initxVel = 0, double inityVel = 0):Body(initMass, initxPos, inityPos, initxVel, inityVel)
{
	//Invokes Body constructor
}
//Setters
void constantBody::setOrbittingBody(int newBody)
{
	this->mOrbittingBody = newBody;
}
void constantBody::setRadius(double newRadius)
{
	this->mRadius = newRadius;
}
void constantBody::setDirection(bool newDirection)
{
	this->mDirection = newDirection;
}
//Getters
int constantBody::getOrbittingBody()const
{
	return this->mOrbittingBody;
}
double constantBody::getRadius()const
{
	return this->mRadius;
}
bool constantBody::getDirection()const
{
	return this->mDirection;
}