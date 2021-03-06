#include "Body.h"

//Constructor
Body::Body(double initMass, double initxPos, double inityPos, double initxVel, double inityVel)
{
	this->mMass = initMass;
	this->mXPos = initxPos;
	this->mYPos = inityPos;
	this->mXVel = initxVel;
	this->mYVel = inityVel;
}
//Copy Constructor
Body::Body(Body *& newBody)
{
	this->mMass = newBody->mMass;
	this->mXPos = newBody->mXPos;
	this->mYPos = newBody->mYPos;
	this->mXVel = newBody->mXVel;
	this->mYVel = newBody->mYVel;
}
//Setters
void Body::setMass(double newMass)
{
	this->mMass = newMass;
}
void Body::setXPos(double newXPos)
{
	this->mXPos = newXPos;
}
void Body::setYPos(double newYPos)
{
	this->mYPos = newYPos;
}
void Body::setXVel(double newXVel)
{
	this->mXVel = newXVel;
}
void Body::setYVel(double newYVel)
{
	this->mYVel = newYVel;
}
//Getters
double Body::getMass() const
{
	return this->mMass;
}
double Body::getXPos() const
{
	return this->mXPos;
}
double Body::getYPos() const
{
	return this->mYPos;
}
double Body::getXVel()const
{
	return this->mXVel;
}
double Body::getYVel()const
{
	return this->mYVel;
}