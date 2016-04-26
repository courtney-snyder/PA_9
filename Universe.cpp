#include "Body.h"

//Constructor
Universe::Universe(int numOfBodies, double initMass[100], double initXPos[100], double initYPos[100], double initXVel[100], double initYVel[100])
{
	int i = 0;
	this->maxSize = numOfBodies;
	sf::Color planetColors[100] = { sf::Color::Black, sf::Color::Yellow, sf::Color::Blue, sf::Color::Red };
	while (i < numOfBodies)
	{
		Bodies[i] = new staticBody;
		Bodies[i]->setMass(initMass[i]);
		Bodies[i]->setXPos(initXPos[i]);
		Bodies[i]->setXVel(initXVel[i]);
		Bodies[i]->setYPos(initYPos[i]);
		Bodies[i]->setYVel(initYVel[i]);
		Bodies[i]->mShape.setFillColor(planetColors[i]);
		Bodies[i]->mShape.setPosition(initXPos[i], initYPos[i]);
		i++;
	}
}
//Setters
void Universe::setMaxSize(int i)
{
	if (i <= 100)
		this->maxSize = i;
	else
	{
		i %= 100; //Because we only have space for 100 bodies in the universe
		this->maxSize = i;
	}
}
void Universe::setBody(int i, double newMass, double newXPos, double newYPos, double newXVel, double newYVel)
{
	this->Bodies[i]->setMass(newMass);
	this->Bodies[i]->setXPos(newXPos);
	this->Bodies[i]->setXVel(newXVel);
	this->Bodies[i]->setYPos(newYPos);
	this->Bodies[i]->setYVel(newYVel);
}
//Getters
int Universe::getMaxSize()const
{
	return this->maxSize;
}
Body* Universe::getBody(int i)const //Choose which body you want to get (1, 2, 3, 4). How we number the bodies will be determined later
{
	if (i >= 0)
		return this->Bodies[i]; //Retrieves the appropriate body
}
//Others
int Universe::isOpen(sf::RenderWindow &window, double x, double y)
{
	printf("(%lf,%lf)\n", x, y);
	if (y > 460)
		return 1;
	else if (x > 620)
		return 2;
	else if (y < 20)
		return 3;
	else if (x < 20)
		return 4;
	else
		return 0;
}
void Universe::initUniverse(int maxSize)
{
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
	this->setMaxSize(maxSize);
	this->Bodies[0] = golfBall;
	this->Bodies[0]->mShape.setTexture(&ballTexture);
	this->Bodies[1] = mercury;
	this->Bodies[1]->mShape.setTexture(&mercuryTexture);
	this->Bodies[2] = venus;
	this->Bodies[2]->mShape.setTexture(&venusTexture);
	this->Bodies[3] = earth;
	this->Bodies[3]->mShape.setTexture(&earthTexture);
	this->Bodies[4] = mars;
	this->Bodies[4]->mShape.setTexture(&marsTexture);
	this->Bodies[5] = jupiter;
	this->Bodies[5]->mShape.setTexture(&jupiterTexture);
	this->Bodies[6] = saturn;
	this->Bodies[6]->mShape.setTexture(&saturnTexture);
	this->Bodies[7] = uranus;
	this->Bodies[7]->mShape.setTexture(&uranusTexture);
	this->Bodies[8] = neptune;
	this->Bodies[8]->mShape.setTexture(&neptuneTexture);
	this->Bodies[9] = pluto;
	this->Bodies[9]->mShape.setTexture(&plutoTexture);
	for (; i < this->getMaxSize(); i++)
	{
		this->Bodies[i]->mShape.setRadius(20);
		this->Bodies[i]->mShape.setPosition(i + 50, i + 10);
		this->Bodies[i]->mShape.setTextureRect(sf::IntRect(100, 100, 100, 100));
	}
}
int tutorial(int level, sf::RenderWindow &window, Universe &map, sf::CircleShape goal)
{
	int x = 0, y = 0;
	Body* ball = new nonstaticBody;
	ball = map.getBody(0);
	ball->setXVel(1);
	ball->setYVel(1);

	window.draw(map.getBody(0)->mShape); //Draw the ball in the initial position
	sf::Vector2i localPosition = sf::Mouse::getPosition(window); //Gets the place in the window that the user clicked (X & Y coords)
	x = localPosition.x; //Gets the x coordinate of localPosition (mouse click)
	y = localPosition.y; //Gets the y coordinate of localPosition (mouse click)
	dynamic_cast<nonstaticBody*>(ball)->shoot(y, map, window); //Get the time length of the click with clock and currentTime
	if (ball->mShape.getPosition() != goal.getPosition())
		level++;
	window.clear(); //Clear the previous position of the ball
	window.draw(map.getBody(0)->mShape); //Draw the ball in the new position
	window.draw(goal);
	window.display(); //Display the updated window
	return level;
}
int level1(int level, sf::RenderWindow &window, Universe &map, sf::CircleShape goal)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //If the user clicks the left button
	{
		int x = 0, y = 0;
		sf::Vector2i localPosition = sf::Mouse::getPosition(window); //Gets the place in the window that the user clicked (X & Y coords)
		x = localPosition.x; //Gets the x coordinate of localPosition
		y = localPosition.y; //Gets the y coordinate of localPosition
							 //Get the time length of the click with clock and currentTime
							 //Add all the math in and manipulate x and y
		Body* ball = new nonstaticBody;
		ball = map.getBody(0);
		dynamic_cast<nonstaticBody*>(ball)->mShape.setPosition(x, y); //Draw the ball in the final position
		if (dynamic_cast<nonstaticBody*>(ball)->mShape.getPosition() == goal.getPosition())
			level++;
		window.clear(); //Clear the previous position of the ball
		window.draw(dynamic_cast<nonstaticBody*>(ball)->mShape); //Draw the ball in the new position
		window.draw(goal);
		window.display(); //Display the updated window
	}
	return level;
}