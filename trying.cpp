#include "Header.h"

void moving(sf::CircleShape ball[], sf::Vector2f direction[], float delta, int n)
{
	sf::Vector2f new_pos(ball[n].getPosition().x + direction[n].x * delta, ball[n].getPosition().y + direction[n].y * delta);
	if (new_pos.x - ball[n].getRadius() < 0) { // left window edge
		direction[n].x *= -1;
		new_pos.x = 0 + ball[n].getRadius();
	}
	else if (new_pos.x + ball[n].getRadius() >= 600) { // right window edge
		direction[n].x *= -1;
		new_pos.x = 400 - ball[n].getRadius();
	}
	else if (new_pos.y - ball[n].getRadius() < 0) { // top of window
		direction[n].y *= -1;
		new_pos.y = 0 + ball[n].getRadius();
	}
	else if (new_pos.y + ball[n].getRadius() >= 600) { // bottom of window
		direction[n].y *= -1;
		new_pos.y = 300 - ball[n].getRadius();
	}
	ball[n].setPosition(new_pos);
}



void collide(sf::CircleShape ball[], sf::Vector2f direction[], int n) //only works for circles
{
	float dx, dy, distance, cPX, cPY;

	dx = (ball[0].getPosition().x - ball[n].getPosition().x);
	dy = (ball[0].getPosition().y - ball[n].getPosition().y);

	distance = std::sqrt((dx * dx) + (dy * dy));

	if (distance < ball[0].getRadius() + ball[n].getRadius())
	{
		cPX =
			((ball[0].getPosition().x * ball[n].getRadius()) + (ball[n].getPosition().x * ball[0].getRadius()))
			/ (ball[0].getRadius() + ball[n].getRadius());
		cPY =
			((ball[0].getPosition().y * ball[n].getRadius()) + (ball[n].getPosition().y * ball[0].getRadius()))
			/ (ball[0].getRadius() + ball[n].getRadius());

		direction[0].x = -(cPX - ball[0].getPosition().x);
		direction[0].y = -(cPY - ball[0].getPosition().y);
	}

}

float shotAngle(sf::Vector2f direction[], float delta, int x, int y)
{
	direction[0].x = x;
	direction[0].y = y;
	delta += 0.05;
	return delta;
}