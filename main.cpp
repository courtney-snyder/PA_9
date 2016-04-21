#include "Body.h"

//To do:
//Fix Universe::getBody function.  also, does it need to be a pointer?
//PROBLEM: CANNOT RETRIEVE ORBITTING BODY b/c cannot cast a Body as a constantBody
//Why was Universe derived from Body?


void main(void)
{
	Universe uni;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Gravity Golf");
	sf::CircleShape shape;
	shape.setRadius(10.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Cyan);
	
	int ans = 0;

	sf::Clock clock;
	sf::Clock endClock;
	sf::Time currentTime;
	
	while (window.isOpen() && (ans <= 0 || ans >=5)) { //will need to change eventually

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}

		currentTime = clock.getElapsedTime();

		if (currentTime.asSeconds() >= 1.0f/fps)//so it goes off a certain number of times per second
		{
			
			//ans = uni.runSim(&clock);
			shape.move(.5f, .5f);

		

			clock.restart();
		}
	
		
		

		window.clear();
		window.draw(shape);
		window.display();
	}



}
