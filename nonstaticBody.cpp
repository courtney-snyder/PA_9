#include "Body.h"

nonstaticBody::nonstaticBody(double initMass, double initRadius, double initxPos, double inityPos, double initxVel, double inityVel) : Body(initMass, initRadius, initxPos, inityPos, initxVel, inityVel)
{
	//Invokes the Body constructor
}

void nonstaticBody::shoot(int i, Universe map, sf::RenderWindow &window)
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		i++;
	//mShape.move(i / 100000, 0);
	mXVel = i / 200000;
	mYVel = i / 200000;
	this->moving(map, window);
}

void nonstaticBody::moving(Universe map, sf::RenderWindow &window)
{
	int direction = 0;

	while (mXVel != 0 && mYVel != 0)
	{
		if (map.isOpen(window, mShape.getPosition().x, mShape.getPosition().y) != 0 )
			printf("working\n");
		if (map.isOpen(window, mShape.getPosition().x, mShape.getPosition().y) != direction)
			direction = map.isOpen(window, mShape.getPosition().x, mShape.getPosition().y);
		printf("%d\n", direction);
		switch (direction)
		{
		case 1:
			mYVel = 0 - mYVel;
			break;
		case 2:
			mXVel = 0 - mXVel;
			break;
		case 3:
			mYVel = 0 - mYVel;
			break;
		case 4:
			mXVel = 0 - mXVel;
			break;
		}

		mShape.move(mXVel--, mYVel--);
		if (mShape.getPosition().x < 20)
			mShape.move(-2*mXVel, 0);
		if (mShape.getPosition().x > 620)
			mShape.move(-2 * mXVel, 0);
		if (mShape.getPosition().y < 20)
			mShape.move(0, -2 * mYVel);
		if (mShape.getPosition().y > 460)
			mShape.move(0, -2 * mYVel);
		window.draw(this->mShape);
	}
}