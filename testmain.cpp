#include <SFML/Graphics.hpp>
#include "Body.h"

int level(Universe &map, int goalXCoord, int goalYCoord)
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Gravity Golf");
	double fps = 60;
	float i = 0;
	sf::Clock clock;
	sf::Time currentTime;
	sf::Texture ballTexture; //Initialize the golf ball texture
	if (!ballTexture.loadFromFile("golf_ball.jpg")) //If the ball texture is not loaded
		cout << "Could not load the texture." << endl;
	nonstaticBody ball;
	sf::CircleShape goal;
	goal.setFillColor(sf::Color::Green);
	goal.setPosition(goalXCoord, goalYCoord);
	goal.setRadius(20);
	currentTime = clock.getElapsedTime();
	ball.mShape.setTexture(&ballTexture);
	ball.mShape.setOutlineThickness(0.01);
	ball.mShape.setRadius(20);
	ball.mShape.setPosition(0, 0);
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: //If the user clicks the X
				window.close();
				break; //Close the window
			case sf::Event::MouseButtonPressed:
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Left: //If the user clicks to shoot
					ball.shoot(0, map, window);
					break;
				}
				break;
			}
			window.clear();
			for (i = 0; i < map.getMaxSize(); i++)
			{
				window.draw(map.getBody(i)->mShape);
			}
			window.draw(ball.mShape);
			window.draw(goal);
			window.display();
		}
	}
	cout << "(" << ball.mShape.getPosition().x;
	cout << ball.mShape.getPosition().y << ")" << endl;
	return 0;
}