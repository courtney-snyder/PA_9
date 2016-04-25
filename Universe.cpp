#include "Body.h"

//Constructor
Universe::Universe(int numOfBodies, double initMass[100], double initXPos[100], double initYPos[100], double initXVel[100], double initYVel[100])
{

	int i = 1;
	this->maxSize = numOfBodies;
	Bodies[0] = new nonstaticBody; //Bodies[0] will always be the ball
	Bodies[0]->mShape.setRadius(20);
	Bodies[0]->mShape.setOrigin(0, 0);
	Bodies[0]->setXVel(1); //So shoot and moving work
	Bodies[0]->setYVel(1); //So shoot and moving work
	while (i < numOfBodies)
	{
		Bodies[i]->setMass(initMass[i]);
		Bodies[i]->setXPos(initXPos[i]);
		Bodies[i]->setXVel(initXVel[i]);
		Bodies[i]->setYPos(initYPos[i]);
		Bodies[i]->setYVel(initYVel[i]);
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
Body * Universe::getBody(int i)const //Choose which body you want to get (1, 2, 3, 4). How we number the bodies will be determined later
{
	//if (i >= 0)
	//	return this->Bodies[i]; //Retrieves the appropriate body
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


//causes the ball to move or the game to end
//returns: 0->continue running, 1->in goal so end, 2-> out of bounds so end, 3->touching dead body so end, 4->maxtime so end , 5->now stopped
int Universe::runSim(sf::Clock *endClock)
{
	int a = 0; //remove this when done
	int end = 0;
	int t = isTouching();

	if (a) //if inside goal
	{
		end = 1;
	}
	else if (mXPos[0] > lim || mXPos[0] < -lim || mYPos[0] > lim || mYPos[0] < -lim) // checks if ball is out of bounds
	{
		end = 2;
		//end, display out of bounds
	}
	else if (t) //touching body
	{
		double v = sqrt(pow(Bodies[0]->getXVel(), 2) + pow(Bodies[0]->getYVel(), 2));
		
		if (a)//close to const or close to dying body
		{
			end = 3; //end, display died
		}
		else if (v < vlim) //touching, and velociteis low
		{
			
			end = 5;//touching, can stop now
		}
		else
		{
			int n = 0;//body number it is touching
			rebound(n);//the body of the 
			renewPos(1);//iterate all except the ball
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
	else
	{
		//iterate location 
		renewPos(0);//renews all posiitons starting at 0
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
			coordinateNonStatic(Bodies[n]->getXPos(), Bodies[n]->getYPos(), n);
		}
		else if (typeid(&Bodies[n]).name() == "constantBody") //constant
		{
			//else if constant, update
			coordinateConst(Bodies[n]->getXPos(), Bodies[n]->getYPos(), n);
		}
		//if static or Body, do nothing
		//To find body type, uses: http://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c
	
	}




	//update all positions to Universe (must be done afterwards, so they all renew at same moment)
	for (n; n < 100; n++)
	{
		//renew position
		mXPos[n] = Bodies[n]->getXPos();
		mYPos[n] = Bodies[n]->getYPos();
		//mXVel[n] = Bodies[n].getXVel();
		//mYVel[n] = Bodies[n].getYVel();
	}

}

//sets the new positions/velocity of a nonStatic Body
void Universe::coordinateNonStatic(double x, double y, int n)
{
	double r = 0.0, theta = 0.0, accelY = 0.0, accelX = 0.0, a = 0.0;
	int i = 0;

	//find new veloc;
	for (i = 0; i < 100; i++)
	{
		if (i != n && Bodies[i]->getMass() != 0)
		{
			r = sqrt(pow((Bodies[i]->getXPos() - x), 2) + pow((Bodies[i]->getYPos() - y), 2));
			theta = atan((Bodies[i]->getYPos() - y) / (Bodies[i]->getXPos() - x));
			a = (Bodies[i]->getMass())*gravity/pow(r,2); //*gravity / pow(r, 2);
			//accelerations can be added together and accumulate
			accelX += a*cos(theta);
			accelY += a*sin(theta);

		}
	}

	//stores old velocities
	double prevXV = Bodies[n]->getXVel();
	double prevYV = Bodies[n]->getYVel();
	
	//sets new velocities
	Bodies[n]->setXVel(Bodies[n]->getXVel() + accelX / fps);
	Bodies[n]->setYVel(Bodies[n]->getYVel() + accelY / fps);

	//set new positions
	Bodies[n]->setXPos(Bodies[n]->getXPos() + (prevXV + Bodies[n]->getXVel()) / (2 * fps));
	Bodies[n]->setYPos(Bodies[n]->getYPos() + (prevYV + Bodies[n]->getYVel()) / (2 * fps));
}

//sets the new position/velocity
void Universe::coordinateConst(double x, double y, int n)
{
	//only orbits one object, not affected by others' gravity (assumes itself is massless)
	//double orbitV = sqrt(gravity*Bodies[Bodies[n].getOrbittingBody()].getMass() / (Bodies[n].getRadius()));
	
	//((constantBody) *pB).getOrbittingBody()
	//int x =  ((constantBody) Bodies[n]).getOrbittingBody();

	//PROBLEM: CANNOT RETRIEVE ORBITTING BODY b/c cannot cast a Body as a constantBody
}

//makes the ball "bounce" off of an object
void Universe::rebound(int n)
{
	double v = sqrt(pow(Bodies[0]->getXVel(),2) + pow(Bodies[0]->getYVel(),2));//the velocity scaler
	double vXUnit = Bodies[0]->getXVel() / v;
	double vYUnit = Bodies[0]->getYVel() / v;
	double theta = atan((Bodies[0]->getYPos() - Bodies[n]->getYPos()) / (Bodies[0]->getXPos() - Bodies[n]->getXPos()));
	double nXUnit = cos(theta);
	double nYUnit = sin(theta);

	double vXNew = Bodies[0]->getXVel() - 2 * ((Bodies[0]->getXVel()*nXUnit + (Bodies[0]->getYVel()*nYUnit) / (nXUnit*nXUnit + nYUnit*nYUnit))*nXUnit);
	double vYNew = Bodies[0]->getYVel() - 2 * ((Bodies[0]->getXVel()*nXUnit + (Bodies[0]->getYVel()*nYUnit) / (nXUnit*nXUnit + nYUnit*nYUnit))*nYUnit);

	Bodies[0]->setXVel(vXNew * friction);
	Bodies[0]->setYVel(vYNew * friction);

	Bodies[0]->setXPos(Bodies[0]->getXPos() + vXNew / fps); //technically should be the new velocity divided by two times the time, but we want to make sure it escapes the body by next round, else it will get stuck inside it
	Bodies[0]->setYPos(Bodies[0]->getYPos() + vYNew / fps);
	
}

//checks if a body is within the radius of another body plus its radius combined
int Universe::isTouching()
{
	int n = 1;
	double r = 0;
	for (n = 1; n < 100; n++)
	{
		
		r = sqrt(pow((Bodies[n]->getXPos() - Bodies[0]->getXPos()), 2) + pow((Bodies[n]->getYPos() - Bodies[0]->getYPos()), 2));
		if (r <= (Bodies[n]->getRadius()+ Bodies[0]->getRadius()))
		{
			return n;
		}
	}
	return 0;
}

int Universe::isOpen(sf::RenderWindow &window, double x, double y)
{
	printf("(%lf,%lf)\n", x, y);
	if (y > 460)
		return 1;
	else if (x > 620)
		return 2;
	else if (y < 20)
		return 3;
	else if (x < 20)
		return 4;
	else
		return 0;
}
int tutorial(int level, sf::RenderWindow &window, Universe &map, sf::CircleShape goal)
{
	int x = 0, y = 0;
	Body* ball = new nonstaticBody;
	ball = map.getBody(0);
	ball->setXVel(1);
	ball->setYVel(1);
	window.draw(map.getBody(0)->mShape); //Draw the ball in the initial position
	sf::Vector2i localPosition = sf::Mouse::getPosition(window); //Gets the place in the window that the user clicked (X & Y coords)
																 //x = localPosition.x; //Gets the x coordinate of localPosition (mouse click)
																 //y = localPosition.y; //Gets the y coordinate of localPosition (mouse click)
	dynamic_cast<nonstaticBody*>(ball)->shoot(200000, map, window); //Get the time length of the click with clock and currentTime
	if (ball->mShape.getPosition() != goal.getPosition())
		level++;
	window.clear(); //Clear the previous position of the ball
	window.draw(map.getBody(0)->mShape); //Draw the ball in the new position
	window.draw(goal);
	window.display(); //Display the updated window
	return level;
}
int level1(int level, sf::RenderWindow &window, Universe &map, sf::CircleShape goal)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If the user clicks the left button
	{
		int x = 0, y = 0;
		sf::Vector2i localPosition = sf::Mouse::getPosition(window); //Gets the place in the window that the user clicked (X & Y coords)
		x = localPosition.x; //Gets the x coordinate of localPosition
		y = localPosition.y; //Gets the y coordinate of localPosition
							 //Get the time length of the click with clock and currentTime
							 //Add all the math in and manipulate x and y
		Body* ball = new nonstaticBody;
		ball = map.getBody(0);
		dynamic_cast<nonstaticBody*>(ball)->mShape.setPosition((float)x, (float)y); //Draw the ball in the final position
		if (dynamic_cast<nonstaticBody*>(ball)->mShape.getPosition() == goal.getPosition())
			level++;
		window.clear(); //Clear the previous position of the ball
		window.draw(dynamic_cast<nonstaticBody*>(ball)->mShape); //Draw the ball in the new position
		window.draw(goal);
		window.display(); //Display the updated window
	}
	return level;
}

//int MainMenu(sf::RenderWindow &window)
//{
//	int ans = 0;
//	window.clear();
//	sf::Image welcome;
//	if (!welcome.loadFromFile("w.jpg"))
//	{
//		cout << "error, cannot display file" << endl;
//	}
//	
//
//	system("pause");
//	return ans;
//}