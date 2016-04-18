#include <SFML/Graphics.hpp>

#include <iostream>

using std::endl;
using std::cout;


void main(void)
{

	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	sf::CircleShape shape;
	shape.setRadius(10.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Cyan);
	float fps = 60;

	sf::Clock clock;
	sf::Time currentTime;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//if running sim
		//if time is >= proper time
		//run main loop
		//reset time

		currentTime = clock.getElapsedTime();

		if (currentTime.asSeconds() >= 1.0f/fps)
		{
			
			//Run Position setting here...
			
			clock.restart();
		}
	
		
		window.clear();
		window.draw(shape);
		window.display();
	}



}