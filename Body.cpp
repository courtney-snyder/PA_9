#include "Body.h"

//Constructor
Body::Body(double initMass, double initRadius, double initxPos, double inityPos, double initxVel, double inityVel)
{
	this->mMass = initMass;
	setRadius(initRadius); // Sets this->mRadius to initRadius AND sets mShape.setRadius to initRadius so mShape can be drawn
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
void Body::setRadius(double newRadius)
{
	this->mRadius = newRadius;
	this->mShape.setRadius((float) mRadius); //So the graphic is the correct size
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
double Body::getRadius()const
{
	return this->mRadius;
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
Body* Body::getBody(int i)
{
	//Virtual function
	return this;
}