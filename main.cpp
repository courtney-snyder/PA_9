#include "Body.h"

//To do:
//Fix Universe::getBody function.  also, does it need to be a pointer?
//PROBLEM: CANNOT RETRIEVE ORBITTING BODY b/c cannot cast a Body as a constantBody
//Why was Universe derived from Body?

void main(void)
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Gravity Golf");
		
		Universe map;
	
	
		while (window.isOpen())
		{
			if (!background.loadFromFile("background.jpg"))
				return -1;

			
		}
		
	
}



//void main(void)
//{
//	Universe uni;
//	sf::RenderWindow window(sf::VideoMode(1080, 720), "Gravity Golf");
//	sf::CircleShape shape;
//	shape.setRadius(10.f);
//	shape.setPosition(100.f, 100.f);
//	shape.setFillColor(sf::Color::Cyan);
//	
//	int ans = 0;
//
//	sf::Clock clock;
//	sf::Clock endClock;
//	sf::Time currentTime;
//	
//	//this loop checks if the ball is still moving, and then goes into the simulation to find its new position
//	while (window.isOpen() && ans == 0) { //will need to change eventually
//
//
//
//		sf::Event event;
//		while (window.pollEvent(event)) {
//
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		currentTime = clock.getElapsedTime();
//
//		if (currentTime.asSeconds() >= 1.0f/fps)//so it goes off a certain number of times per second
//		{
//			
//			//ans = uni.runSim(&clock);
//			shape.move(1.0f, 1.0f);
//		
//			clock.restart();
//		}
//		
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//
//
//}



//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(640, 480), "Gravity Golf");
//	double fps = 60;
//	float i = 0;
//	sf::Clock clock;
//	sf::Time currentTime;
//	Universe map;
//
//	sf::Texture ballTexture; //Initialize the golf ball texture
//	if (!ballTexture.loadFromFile("golf_ball.jpg")) //If the ball texture is not loaded
//		cout << "Could not load the texture." << endl;
//	sf::Sprite testSprite(ballTexture); //Create the sprite and set the texture
//
//	nonstaticBody ball;
//	currentTime = clock.getElapsedTime();
//	/*if (currentTime.asSeconds() >= 1.0f / fps)
//	{
//	ball.mShape.setFillColor(sf::Color::White); //Ball is WHITE
//	ball.mShape.setRadius(20);
//	window.draw(ball.mShape);
//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If the user clicks the left button
//	{
//	//Get the time length of the click
//	//Depending on how long the click is, shoot the ball
//	ball.mShape.move(10, 10);
//	}
//	clock.restart();
//	}*/
//	//ball.mShape.setFillColor(sf::Color::White); //Ball is WHITE
//	ball.mShape.setTexture(&ballTexture);
//	ball.mShape.setRadius(20);
//	ball.mShape.setPosition(0, 400);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//			case sf::Event::Closed: //If the user clicks the X
//				window.close();
//				break; //Close the window
//			case sf::Event::KeyPressed:
//				switch (event.key.code)
//				{
//				case sf::Keyboard::D: //If the user clicks to shoot
//					ball.shoot(0, map, window);
//					//ball.mShape.move(0, -10);
//					break;
//
//				}
//				break;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //If the user clicks the left button
//			{
//				//Get the time length of the click
//				//Depending on how long the click is, shoot the ball
//				ball.mShape.move(0, -10);
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//			{
//				ball.mShape.move(-10, 0);
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//			{
//				ball.mShape.move(0, 10);
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//			{
//				ball.mShape.move(10, 0);
//			}
//			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) //If the user clicks the left button
//			{
//				ball.mShape.move(10, 0);
//			}
//			window.clear();
//			window.draw(ball.mShape);
//			window.display();
//			//MainMenu(window);
//		}
//	}
//	printf("(%f, ", (ball.mShape.getPosition()).x);
//	printf("%f)\n", (ball.mShape.getPosition()).y);
//	return 0;
//}