/*
Programmers: Courtney Snyder, Greg Wallace, Michael LaFountain
Last Updated: 4/18/16
Description: A game of gravity golf.
*/
#include "Body.h"

int main() 
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Gravity Golf");
	double fps = 60;
	sf::Clock clock;
	sf::Time currentTime;
	nonstaticBody ball;
	float x = 0, y = 0;
	int level = 0; //Indicates where the player is in the game (level 0 is the tutorial)
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) //If the user clicks the X
				window.close(); //Close the window
			sf::CircleShape goal;
			Universe map;
			goal.setRadius(20);
			goal.setFillColor(sf::Color::Green);
			goal.setPosition(600, 400);
			switch (level)
			{
			case 0: //Tutorial
				level = tutorial(level, window, map, goal);
			case 1: //Level 1
				break;
			default:
				break;
			}		}
	}
	return 0;
}
