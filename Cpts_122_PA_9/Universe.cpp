#include "Body.h"

//Constructor
Universe::Universe(int numOfBodies, double initMass[100], double initXPos[100], double initYPos[100], double initXVel[100], double initYVel[100])
{
	int i = 0;
	this->maxSize = numOfBodies;
	while (i < numOfBodies)
	{
		//Body(initMass[i], initXPos[i], initYPos[i], initXVel[i], initYVel[i]); //Invoke the Body constructor
		Bodies[i].setMass(initMass[i]);
		Bodies[i].setXPos(initXPos[i]);
		Bodies[i].setXVel(initXVel[i]);
		Bodies[i].setYPos(initYPos[i]);
		Bodies[i].setYVel(initYVel[i]);
		i++;
	}
}
//Setters
void Universe::setMaxSize(int i)
{
	if (i <= 100)
		this->maxSize = i;
	else
		i %= 100; //Because we only have space for 100 bodies in the universe
		this->maxSize = i;
}
void Universe::setBody(int i, double newMass, double newXPos = 0, double newYPos = 0, double newXVel = 0, double newYVel = 0)
{

}
//Getters
int Universe::getMaxSize()const
{
	return this->maxSize;
}
Body Universe::getBody(int i)const //Choose which body you want to get (1, 2, 3, 4). How we number the bodies will be determined later
{
	if (i > 0)
		return this->Bodies[i - 1]; //Retrieves the appropriate body
	else
		cout << "Please enter a number greater than 0." << endl;
}