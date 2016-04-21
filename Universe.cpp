#include "Body.h"

//Constructor
Universe::Universe(int numOfBodies, double initMass[100], double initXPos[100], double initYPos[100], double initXVel[100], double initYVel[100])
{
	
	
	int i = 0;

	//this is used because some of the universe functions use the masses
	for (i = 0; i < 100; i++)
	{
		Bodies[i].setMass(0.0);
	}

	i = 0;

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
	//if (i > 0)
	//	return this->Bodies[i - 1]; //Retrieves the appropriate body
	//else
	//	cout << "Please enter a number greater than 0." << endl;
	return this->Bodies[i];//now just returns the exact body
}//need to include an exception or make it so it returns something even if no value.



 //	//while moving, check body1 for:
 //	//1. if outside bounds (-10000, +10000), end, lose life
 //	//2. if hits moon, end, lose life
 //	//3. if time >= limit (120 s (2 minutes))
 //	//4. if touching body and V <= .001 (less than certain value)
 //	//5. if touching and V >= , rebound at 1/3 velocity (friciton)
 //	//6. if inside goal, end, win
 //	//7. if not visible: show arrow? (make it so they know its still there
 //
 //	//else: find new locations(run all)

//0->continue running, 1->in goal so end, 2-> out of bounds so end, 3->touching dead body so end, 4->maxtime so end , 5->touching nodead body so reverse, 
int Universe::runSim(sf::Clock *endClock)
{
	int a = 0; //remove this when done
	int end = 0;

	if (a) //if inside goal
	{
		end = 1;
	}
	else if (mXPos[0] > lim || mXPos[0] < -lim || mYPos[0] > lim || mYPos[0] < -lim) // checks if ball is out of bounds
	{
		end = 2;
		//end, display out of bounds
	}
	else if (a) //touching body
	{
		if (a)//close to const or close to dying body
		{
			end = 3; //end, display died
		}
		else if (a) //touching, and velociteis low
		{
			end = 5;
		}
		else
		{
			//change velocity direction and magnitude
			//iterate motion
			end = 0;
		}
	}
	else if (endClock->getElapsedTime().asSeconds() > maxTime_s) //if time > maxtime
	{
		//end, display time has hit limit
		end = 4;
	}
	else if (a)
	{

	}
	else
	{
		//iterate location 
		end = 0;
	}



	//if out of bounds
	if (mXPos[0] > 1000 || mXPos[0] < 0 || mYPos[0] > 720 || mYPos[0] < 0) //if out of view
	{
		//display direciton with arrow
		//possibly also show distance out
	}


	return end;
}

//Renews and resets the positions of all bodies from n to 99 (maximum of 100)
void Universe::renewPos(int n)
{
	for (n; n < 100; n++)
	{
		//check if it is moveable
		//typeid(&Bodies[n]).name()
		if (typeid(&Bodies[n]).name() == "nonstaticBody")//then nonstatic
		{
			//if nonstatic, update
			coordinateNonStatic(Bodies[n].getXPos(), Bodies[n].getYPos(), n);
		}
		else if (typeid(&Bodies[n]).name() == "constantBody") //constant
		{
			//else if constant, update
			coordinateConst(Bodies[n].getXPos(), Bodies[n].getYPos(), n);
		}
		//if static or Body, do nothing
		//To find body type, uses: http://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c
	
	}




	//update all positions (must be done afterwards, so they all renew at same moment)
	for (n; n < 100; n++)
	{
		//renew position
		mXPos[n] = Bodies[n].getXPos();
		mYPos[n] = Bodies[n].getYPos();
	}

}


void Universe::coordinateNonStatic(double x, double y, int n)
{
	double r = 0.0, theta = 0.0, accelY = 0.0, accelX = 0.0, a = 0.0;
	int i = 0;

	//find new veloc;
	for (i = 0; i < 100; i++)
	{
		if (i != n && Bodies[i].getMass() != 0)
		{
			r = sqrt(pow((Bodies[i].getXPos() - x), 2) + pow((Bodies[i].getYPos() - y), 2));
			theta = atan((Bodies[i].getYPos() - y) / (Bodies[i].getXPos() - x));
			a = (Bodies[i].getMass())*gravity/pow(r,2); //*gravity / pow(r, 2);
			//accelerations can be added together and accumulate
			accelX += a*cos(theta);
			accelY += a*sin(theta);

		}
	}

	//stores old velocities
	double prevXV = Bodies[n].getXVel();
	double prevYV = Bodies[n].getYVel();
	
	//sets new velocities
	Bodies[n].setXVel(Bodies[n].getXVel() + accelX / fps);
	Bodies[n].setYVel(Bodies[n].getYVel() + accelY / fps);

	//set new positions
	Bodies[n].setXPos(Bodies[n].getXPos() + (prevXV + Bodies[n].getXVel()) / (2 * fps));
	Bodies[n].setYPos(Bodies[n].getYPos() + (prevYV + Bodies[n].getYVel()) / (2 * fps));
}


void Universe::coordinateConst(double x, double y, int n)
{
	//only orbits one object, not affected by others' gravity (assumes itself is massless)
	//double orbitV = sqrt(gravity*Bodies[Bodies[n].getOrbittingBody()].getMass() / (Bodies[n].getRadius()));
	
	//((constantBody) *pB).getOrbittingBody()
	//int x =  ((constantBody) Bodies[n]).getOrbittingBody();

	//PROBLEM: CANNOT RETRIEVE ORBITTING BODY b/c cannot cast a Body as a constantBody
}