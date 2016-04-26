#include "Header.h"
#include "Body.h"

int main()
{
	const float ball_radius = 16.f;
	int n = 0, t = 0;
	float speed;
	sf::Clock clock;
	sf::Time elapsed = clock.restart();
	const sf::Time update_ms = sf::seconds(1.f / 30.f);
	sf::RenderWindow window(sf::VideoMode(600, 600), "Gravity Golf"); //if you change dimentions, also change the values in moving()
	sf::Texture background;
	if (!background.loadFromFile("space.jpg"))
		cout << "Could not load the background texture." << endl;
	sf::Vector2f recShape(600, 600);
	sf::RectangleShape backShape(recShape); //the golf ball
	backShape.setPosition(0, 0);
	backShape.setTexture(&background);
	sf::Vector2f direction[10];
	//starting direction
	sf::Vector2f direction1(15, -15), direction2(0, 0); //the direction of the golf ball
	direction[0] = direction1;
	for (n = 1; n < 10; n++) //sets the direction of non-golf ball objects to 0
		direction[n] = direction2;
	float delta = 0;
	Universe map;
	sf::CircleShape shapeArray[10];
	//map.initUniverse(10); //Initializes the universe by applying textures and populating member Bodies[]
	sf::Texture ballTexture, mercuryTexture, venusTexture, earthTexture, marsTexture, jupiterTexture, saturnTexture, uranusTexture, neptuneTexture, plutoTexture;
	//Load all the textures
	if (!ballTexture.loadFromFile("golf_ball.jpg"))
		cout << "Could not load the ball texture." << endl;
	if (!mercuryTexture.loadFromFile("mercury.jpg"))
		cout << "Could not load Mercury texture." << endl;
	if (!venusTexture.loadFromFile("venus.jpg"))
		cout << "Could not load Venus texture." << endl;
	if (!earthTexture.loadFromFile("earth.jpg"))
		cout << "Could not load Earth texture." << endl;
	if (!marsTexture.loadFromFile("mars.jpg"))
		cout << "Could not load Mars texture." << endl;
	if (!jupiterTexture.loadFromFile("jupiter.jpg"))
		cout << "Could not load Jupiter texture." << endl;
	if (!saturnTexture.loadFromFile("saturn.jpg"))
		cout << "Could not load Saturn texture." << endl;
	if (!uranusTexture.loadFromFile("uranus.jpg"))
		cout << "Could not load Uranus texture." << endl;
	if (!neptuneTexture.loadFromFile("neptune.jpg"))
		cout << "Could not load Neptune texture." << endl;
	if (!plutoTexture.loadFromFile("pluto.jpg"))
		cout << "Could not load Pluto texture." << endl;
	Body *golfBall = new nonstaticBody, *mercury = new staticBody, *venus = new staticBody, *earth = new staticBody, *mars = new staticBody, *jupiter = new staticBody, *saturn = new staticBody, *uranus = new staticBody, *neptune = new staticBody, *pluto = new staticBody;
	int i = 0;
	map.setMaxSize(10);
	map.Bodies[0] = golfBall;
	map.Bodies[0]->mShape.setTexture(&ballTexture);
	map.Bodies[0]->mShape.setPosition(50, 50);
	map.Bodies[1] = mercury;
	map.Bodies[1]->mShape.setTexture(&mercuryTexture);
	map.Bodies[1]->mShape.setPosition(100, 100);
	map.Bodies[2] = venus;
	map.Bodies[2]->mShape.setTexture(&venusTexture);
	map.Bodies[2]->mShape.setPosition(150, 150);
	map.Bodies[3] = earth;
	map.Bodies[3]->mShape.setTexture(&earthTexture);
	map.Bodies[3]->mShape.setPosition(200, 200);
	map.Bodies[4] = mars;
	map.Bodies[4]->mShape.setTexture(&marsTexture);
	map.Bodies[4]->mShape.setPosition(250, 250);
	map.Bodies[5] = jupiter;
	map.Bodies[5]->mShape.setTexture(&jupiterTexture);
	map.Bodies[5]->mShape.setPosition(300, 300);
	map.Bodies[6] = saturn;
	map.Bodies[6]->mShape.setTexture(&saturnTexture);
	map.Bodies[6]->mShape.setPosition(350, 350);
	map.Bodies[7] = uranus;
	map.Bodies[7]->mShape.setTexture(&uranusTexture);
	map.Bodies[7]->mShape.setPosition(400, 400);
	map.Bodies[8] = neptune;
	map.Bodies[8]->mShape.setTexture(&neptuneTexture);
	map.Bodies[8]->mShape.setPosition(450, 450);
	map.Bodies[9] = pluto;
	map.Bodies[9]->mShape.setTexture(&plutoTexture);
	map.Bodies[9]->mShape.setPosition(500, 500);
	for (; i < map.getMaxSize(); i++)
	{
		map.Bodies[i]->mShape.setRadius(20);
		map.Bodies[i]->mShape.setTextureRect(sf::IntRect(100, 100, 100, 100));
	}
	for (n = 0; n < 10; n++) //Populate shapeArray so we can use it in moving and collide
		shapeArray[n] = map.Bodies[n]->mShape;
	sf::CircleShape goal;
	goal.setFillColor(sf::Color::Color(sf::Uint32(16902555)));
	int level = 10; //Tutorial

	while (window.isOpen()) 
	{
		//Game loop
		while (level < 11)
		{
			sf::Event event;
			goal.setRadius(20);
			goal.setPosition(40, 40);
			elapsed += clock.restart();
			while (elapsed >= update_ms)
			{
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
							shapeArray->getPosition();
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
							const auto pos = shapeArray->getPosition(); //needed for moving()
							sf::Vector2f new_pos(pos.x + direction[0].x * delta, pos.y + direction[0].y * delta); //needed for moving()
							moving(shapeArray, direction, delta, 0); //moves the ball
							for (n = 0; n < level; n++)
								collide(shapeArray, direction, n); //collision detection, only works for circles
							if (delta >= .005)
								delta -= .005; //slows the ball
							window.draw(backShape);
							window.draw(goal);
							for (n = 0; n < level; n++)
								window.draw(shapeArray[n]); //Draw all the planets
							window.display();
						}
						delta = 0; //makes the ball stop
					}
				}
				elapsed -= update_ms;
			}
			window.draw(backShape);
			window.draw(goal);
			for (n = 0; n < level; n++)
				window.draw(shapeArray[n]);
			window.display();
			sf::Vector2f positiveHitArea = goal.getPosition(), negativeHitArea = goal.getPosition();
			positiveHitArea.x += goal.getRadius(); //Increases the x component of positive hit area
			positiveHitArea.y += goal.getRadius(); //Increases the y component of positive hit area
			negativeHitArea.x -= goal.getRadius();
			negativeHitArea.y -= goal.getRadius();

			if (shapeArray[0].getPosition() == positiveHitArea || shapeArray[0].getPosition() == negativeHitArea) //If the ball's current position is in the hit range
			{
				cout << "You win!" << endl;
				level++;
			}
		}
	}
	return EXIT_SUCCESS;
}