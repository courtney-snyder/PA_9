#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define gravity = 6.67*pow(10, -11); //Had to change to gravity because G and g already exist within SFML
//#define N = 100;

class Body
{
public:
	Body(double initMass = 0, double initRadius = 0, double initxPos = 0, double inityPos = 0, double initxVel = 0, double inityVel = 0);
	Body(Body *& newBody);
	//Setters
	void setMass(double newMass);
	void setRadius(double newRadius);
	void setXPos(double newXPos);
	void setYPos(double newYPos);
	void setXVel(double newXVel);
	void setYVel(double newYVel);
	//Getters
	double getMass()const;
	double getRadius()const;
	double getXPos()const;
	double getYPos()const;
	double getXVel()const;
	double getYVel()const;
	sf::CircleShape mShape; //graphic for the body
protected:
	double mMass;
	double mRadius;
	double mXPos;
	double mYPos;
	double mXVel;
	double mYVel;
};


class Universe : public Body
{
public:
	//Constructor
	Universe(int numOfBodies = 0, double initMass[100] = 0, double initXPos[100] = 0, double initYPos[100] = 0, double initXVel[100] = 0, double initYVel[100] = 0);
	//Setters
	void setMaxSize(int i);
	void setBody(int i, double newMass, double newXPos, double newYPos, double newXVel, double newYVel);
	//Getter
	int getMaxSize()const;
	Body getBody(int i)const;
	int isOpen(sf::RenderWindow &window, double x, double y);
		
private:
	int maxSize;
	Body Bodies[100];
	double mMass[100];
	double mXPos[100];//these are used by other functions instead of the values inside each "Body" object. This way, all moveable objects update at once.  
	double mYPos[100];
	double mXVel[100];
	double mYVel[100];
};




class staticBody : public Body //does not move, is not affected by forces
{
public:
	//A large planet
	staticBody(double initMass = 0, double initRadius = 0, double initxPos = 0, double inityPos = 0);
//	//Setters
//	void setMass(double newMass);
//	void setXPos(double newXPos);
//	void setYPos(double newYPos);
//	//Getters
//	double getMass()const;
//	double getXPos()const;
//	double getYPos()const;
//protected:
//	double mMass;
//	double mXPos;
//	double mYPos;

	//setter
	void setDie(bool newDeath);
	//getter
	bool getDie()const;

private:
	bool mDie; //if ture, you die

};

class nonstaticBody : public Body //something that can move around, is affected
{
public:
	//The ball
	nonstaticBody(double initMass = 0, double initRadius = 0, double initxPos = 0, double inityPos = 0, double initxVel = 0, double inityVel = 0);

	void shoot(int i, Universe map, sf::RenderWindow &window);
	void moving(Universe map, sf::RenderWindow &window);
};

class constantBody : public nonstaticBody //like something orbiting another body, maintains constant path
{
	//Moon orbitting a planet
	constantBody(double initMass = 0, double initRadius = 0, double initxPos = 0, double inityPos = 0, double initxVel = 0, double inityVel = 0);
	//Setters
	void setOrbittingBody(int newBody);
	//void setRadius(double newRadius);
	void setDirection(bool newDirection);
	//Getters
	int getOrbittingBody()const;
	//double getRadius()const;
	bool getDirection()const;
private:
	int mOrbittingBody; //What body it is orbitting
	//double mRadius;
	bool mDirection; //Clockwise or counterclockwise
};