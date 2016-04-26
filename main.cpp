
#include "Header.h"

int main()
{

	const float ball_radius = 16.f;
	int n = 0, t = 0;
	float speed;

	sf::Clock clock;
	sf::Time elapsed = clock.restart();
	const sf::Time update_ms = sf::seconds(1.f / 30.f);


	sf::RenderWindow window(sf::VideoMode(400, 300), "Bouncing ball"); //if you change dimentions, also change the values in moving()

	sf::Texture background;
	if (!background.loadFromFile("space.jpg")) //If the ball texture is not loaded
		cout << "Could not load the texture." << endl;
	sf::Vector2f recShape(400,300);
	sf::RectangleShape backShape(recShape); //the golf ball
	backShape.setPosition(0, 0);
	backShape.setTexture(&background);

	sf::Vector2f direction[10];
	//starting direction
	sf::Vector2f direction1(15, -15), direction2(0, 0); //the direction of the golf ball
	direction[0] = direction1;
	for (n = 1; n < 10; n++) //sets the direction of non-golf ball objects to 0
		direction[n] = direction2;

	//starting speed
	//auto delta = update_ms.asSeconds() * std::sqrt(direction[0].x * direction[0].x + direction[0].y * direction[0].y);
	float delta = 0;
	//auto delta = 0;

	sf::CircleShape ballMove(ball_radius - 4); //the golf ball
	ballMove.setOutlineThickness(4);
	ballMove.setOutlineColor(sf::Color::Black);
	ballMove.setFillColor(sf::Color::Red);
	ballMove.setOrigin(ballMove.getRadius(), ballMove.getRadius());
	ballMove.setPosition(350, 190);

	sf::CircleShape ball3(ball_radius - 4); //all other objects at the moment
	ball3.setOutlineThickness(4);
	ball3.setOutlineColor(sf::Color::Black);
	ball3.setFillColor(sf::Color::Yellow);
	ball3.setOrigin(ball3.getRadius(), ball3.getRadius());

	sf::CircleShape ball[10]; // sets the balls in an array, so that moving() and collide() dont need pointers
	ball[0] = ballMove;
	for (n = 1; n < 10; n++) // when the other balls will be other objects, they will be assigned 1 by 1, not in a for loop
	{
		ball[n] = ball3; 
		ball[n].setPosition(20 * (n + 1), 20 * (n + 1));
	}

	while (window.isOpen()) {
		sf::Event event;
		/*if (window.pollEvent(event)) 
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
				window.close();
				break;
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D)) {
				;
				break;
			}
		}*/

		elapsed += clock.restart();
		while (elapsed >= update_ms) {

			while (window.pollEvent(event))
			{
				if ((event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
					window.close();
				}
				
				if (event.type == sf::Event::KeyPressed) {
					switch (event.key.code)
					{
					case sf::Keyboard::D:
						ball[0].getPosition();
						delta = shotAngle(direction, delta, 15, 0);
						break;
					case sf::Keyboard::E:
						delta = shotAngle(direction, delta, 15, -15);
						break;
					case sf::Keyboard::W:
						delta = shotAngle(direction, delta, 0, -15);
						break;
					case sf::Keyboard::Q:
						delta = shotAngle(direction, delta, -15, -15);
						break;
					case sf::Keyboard::A:
						delta = shotAngle(direction, delta, -15, 0);
						break;
					case sf::Keyboard::Z:
						delta = shotAngle(direction, delta, -15, 15);
						break;
					case sf::Keyboard::X:
						delta = shotAngle(direction, delta, 0, 15);
						break;
					case sf::Keyboard::C:
						delta = shotAngle(direction, delta, 15, 15);
						break;
					}
				}


				else if (event.type == sf::Event::KeyReleased)
				{
					while (delta >= .005)
					{
						const auto pos = ball[0].getPosition(); //needed for moving()



						sf::Vector2f new_pos(pos.x + direction[0].x * delta, pos.y + direction[0].y * delta); //needed for moving()


						moving(ball, direction, delta, 0); //moves the ball

						for (n = 1; n < 10; n++)
						{
							collide(ball, direction, n); //collision detection, only works for circles
						}
						if (delta >= .005)
							delta -= .005; //slows the ball
						window.draw(backShape);
						for (n = 0; n < 10; n++)
							window.draw(ball[n]);
						window.display();
					}
					delta = 0; //makes the ball stop
				}
			}

			//const auto pos = ball[0].getPosition(); //needed for moving()
			//sf::Vector2f new_pos(pos.x + direction[0].x * delta, pos.y + direction[0].y * delta); //needed for moving()


			//
			//moving(ball, direction, delta, 0); //moves the ball

			//for (n = 1; n < 10; n++)
			//{
			//	collide(ball, direction, n); //collision detection, only works for circles
			//}

			//if (delta >= .005)
			//	delta -= .005; //slows the ball
			//else
			//	delta = 0; //makes the ball stop
			elapsed -= update_ms;
		}

		//window.clear(sf::Color(30, 30, 120));
		window.draw (backShape);
		for (n = 0; n < 10; n++)
			window.draw(ball[n]);
		window.display();
	}

	return EXIT_SUCCESS;
}

