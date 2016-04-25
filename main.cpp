/*
Programmers: Courtney Snyder, Greg Wallace, Michael LaFountain
Last Updated: 4/25/16
Description: A game of gravity golf.
*/
#include "Body.h"

int main(void)
{
	double mercury = 330, venus = 0, earth = 0, mars = 0, jupiter = 0, saturn = 0, uranus = 0, neptune = 0, pluto = 0;
	double initMass[100];
	double initXPos[100];
	double initYPos[100];
	double initXVel[100];
	double initYVel[100];
	Universe tutorial, level1(1, initMass, initXPos, initYPos, initXVel, initYVel);
	level(tutorial, 200, 200);
	level(level1, 400, 400);
	return 0;
}