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
Body* Universe::getBody(int i)const //Choose which body you want to get (1, 2, 3, 4). How we number the bodies will be determined later
{
	if (i >= 0)
		return this->Bodies[i]; //Retrieves the appropriate body
}
//Others
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
		dynamic_cast<nonstaticBody*>(ball)->mShape.setPosition(x, y); //Draw the ball in the final position
		if (dynamic_cast<nonstaticBody*>(ball)->mShape.getPosition() == goal.getPosition())
			level++;
		window.clear(); //Clear the previous position of the ball
		window.draw(dynamic_cast<nonstaticBody*>(ball)->mShape); //Draw the ball in the new position
		window.draw(goal);
		window.display(); //Display the updated window
	}
	return level;
}