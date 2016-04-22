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
int tutorial(int &level, sf::RenderWindow &window, Universe map, nonstaticBody &ball, sf::CircleShape goal)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If the user clicks the left button
	{
		int x = 0, y = 0;
		sf::Vector2i localPosition = sf::Mouse::getPosition(window); //Gets the place in the window that the user clicked (X & Y coords)
		x = localPosition.x; //Gets the x coordinate of localPosition
		y = localPosition.y; //Gets the y coordinate of localPosition
		ball.shoot(0, map, window); //Get the time length of the click with clock and currentTime
											 //Add all the math in and manipulate x and y
		ball.mShape.setPosition(x, y); //Draw the ball in the final position
		if (ball.mShape.getPosition() == goal.getPosition())
			level++;
		window.clear(); //Clear the previous position of the ball
		window.draw(ball.mShape); //Draw the ball in the new position
		window.draw(goal);
		window.display(); //Display the updated window
	}
	return level;
}
int level1(int &level, sf::RenderWindow &window, nonstaticBody &ball, staticBody &planet, sf::CircleShape goal)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If the user clicks the left button
	{
		int x = 0, y = 0;
		sf::Vector2i localPosition = sf::Mouse::getPosition(window); //Gets the place in the window that the user clicked (X & Y coords)
		x = localPosition.x; //Gets the x coordinate of localPosition
		y = localPosition.y; //Gets the y coordinate of localPosition
							 //Get the time length of the click with clock and currentTime
							 //Add all the math in and manipulate x and y
		ball.mShape.setPosition(x, y); //Draw the ball in the final position
		if (ball.mShape.getPosition() == goal.getPosition())
			level++;
		window.clear(); //Clear the previous position of the ball
		window.draw(ball.mShape); //Draw the ball in the new position
		window.draw(goal);
		window.display(); //Display the updated window
	}
	return level;
}