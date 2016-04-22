#include "Levels.h"

int tutorial(int &level, sf::RenderWindow &window, nonstaticBody &ball, sf::CircleShape goal)
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