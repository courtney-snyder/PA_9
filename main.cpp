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
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) //If the user clicks the X
				window.close(); //Close the window
			sf::Texture ballTexture; //Initialize the golf ball texture
			if (!ballTexture.loadFromFile("golf_ball.jpg")) //If the ball texture is not loaded
				cout << "Could not load the texture." << endl;
			sf::Sprite testSprite(ballTexture); //Create the sprite and set the texture
			nonstaticBody ball;
			currentTime = clock.getElapsedTime();
			/*
			if (currentTime.asSeconds() >= 1.0f / fps)
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
			}
			*/
			ball.mShape.setFillColor(sf::Color::White); //Ball is WHITE
			ball.mShape.setRadius(20);
			ball.mShape.setPosition(0, 400);
			window.draw(ball.mShape);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If the user clicks the left button
			{
				//Get the time length of the click
				//Depending on how long the click is, shoot the ball
				ball.mShape.move(10, 10);
			}
			window.clear();
			window.draw(ball.mShape);
			window.display();
		}
	}
	return 0;
}

/*
double mass[100], XPos[100], YPos[100], XVel[100], YVel[100];
mass[0] = 25;
XPos[0] = 111;
YPos[0] = 300;
XVel[0] = 40;
YVel[0] = 30;
staticBody testStatic;
Universe testU(2, mass, XPos, YPos, XVel, YVel);
*/