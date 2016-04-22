#include "Body.h"

constantBody::constantBody(double initMass, double initRadius, double initxPos, double inityPos, double initxVel, double inityVel):nonstaticBody(initMass, initRadius, initxPos, inityPos, initxVel, inityVel)
{
	//Invokes nonstaticBody constructor (which invokes the Body constructor)
}
//Setters
void constantBody::setOrbittingBody(int newBody)
{
	this->mOrbittingBody = newBody;
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
bool constantBody::getDirection()const
{
	return this->mDirection;
}
constantBody* constantBody::getBody(int i, Universe &map)
{
	Body* returnBody = new constantBody;
	returnBody = map.getBody(i);
	return dynamic_cast<constantBody*>(returnBody);
}