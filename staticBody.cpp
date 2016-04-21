#include "Body.h"
//Constructor
staticBody::staticBody(double initMass, double initRadius, double initxPos, double inityPos) :Body(initMass, initRadius, initxPos, inityPos, 0, 0)
 {
	//Invokes the Body constructor, using 0 for X & Y velocities because it's a STATIC body
}

//Setter
void staticBody::setDie(bool newDeath)
{
	this->mDie = newDeath;
}
//Getter
bool staticBody::getDie()const
{
	return this->mDie;
}