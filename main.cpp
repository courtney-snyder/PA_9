// This code expands on the tutorial code provided at:
// http://www.sfml-dev.org/tutorials/2.3/start-vc.php

#include <SFML/Graphics.hpp>

#include "Body.h"
#include "functions.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Gravity Golf");
	double fps = 60;
	float i = 0;
	sf::Clock clock;
	sf::Time currentTime;
	Universe map;

	sf::Texture ballTexture; //Initialize the golf ball texture
	if (!ballTexture.loadFromFile("golf_ball.jpg")) //If the ball texture is not loaded
		cout << "Could not load the texture." << endl;
	sf::Sprite testSprite(ballTexture); //Create the sprite and set the texture

	nonstaticBody ball;
	currentTime = clock.getElapsedTime();
	/*if (currentTime.asSeconds() >= 1.0f / fps)
	{
	ball.mShape.setFillColor(sf::Color::White); //Ball is WHITE
	ball.mShape.setRadius(20);
	window.draw(ball.mShape);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If the user clicks the left button
	{
	//Get the time length of the click
	//Depending on how long the click is, shoot the ball
	ball.mShape.move(10, 10);
	}
	clock.restart();
	}*/
	//ball.mShape.setFillColor(sf::Color::White); //Ball is WHITE
	ball.mShape.setTexture(&ballTexture);
	ball.mShape.setRadius(20);
	ball.mShape.setPosition(0, 400);

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
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::D: //If the user clicks to shoot
					ball.shoot(0, map, window);
					//ball.mShape.move(0, -10);
					break;

				}
				break;
			}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //If the user clicks the left button
			//{
			//	//Get the time length of the click
			//	//Depending on how long the click is, shoot the ball
			//	ball.mShape.move(0, -10);
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			//{
			//	ball.mShape.move(-10, 0);
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			//{
			//	ball.mShape.move(0, 10);
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			//{
			//	ball.mShape.move(10, 0);
			//}
			//if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) //If the user clicks the left button
			//{
			//	ball.mShape.move(10, 0);
			//}
			window.clear();
			window.draw(ball.mShape);
			window.display();
		}
	}
	printf("(%f, ", (ball.mShape.getPosition()).x);
	printf("%f)\n", (ball.mShape.getPosition()).y);
	return 0;
}
/*
+double mass[100], XPos[100], YPos[100], XVel[100], YVel[100];
+mass[0] = 25;
+XPos[0] = 111;
+YPos[0] = 300;
+XVel[0] = 40;
+YVel[0] = 30;
+staticBody testStatic;
+Universe testU(2, mass, XPos, YPos, XVel, YVel);
+*/

