#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define Gravity = 1; //Had to change to gravity because G and g already exist within SFML
#define Million = 1000000;
class Body
{
public:
	//Constructor
	Body(double initMass = 0, double initRadius = 1, double initxPos = 0, double inityPos = 0, double initxVel = 0, double inityVel = 0);
	//Copy Constructor
	Body(Body *& newBody);
	//Setters
	void setMass(double newMass);
	void setRadius(double newRadius);
	void setXPos(double newXPos);
	void setYPos(double newYPos);
	void setXVel(double newXVel);
	void setYVel(double newYVel);
	virtual Body* getBody(int i = 0);
	//Getter
	double getMass()const;
	double getRadius()const;
	double getXPos()const;
	double getYPos()const;
	double getXVel()const;
	double getYVel()const;
	sf::CircleShape mShape; //Graphic for whatever body we will create; static, nonstatic, or constant
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
	Body* getBody(int i)const;
	//Others
	int isOpen(sf::RenderWindow &window, double x, double y);
	void initUniverse(int maxSize);
	Body *Bodies[100]; //This is an array of type BODY because that way we can have Body* types
protected:
	int maxSize;
	double mMass[100];
	double mXPos[100];//these are used by other functions instead of the values inside each "Body" object. This way, all moveable objects update at once.  
	double mYPos[100];
	double mXVel[100];
	double mYVel[100];
};

class staticBody : public Body //does not move, is not affected by forces (like a planet)
{
public:
	//A large planet
	staticBody(double initMass = 0, double initRadius = 0, double initxPos = 0, double inityPos = 0);
	//Setter
	void setDie(bool newDeath);
	//Getter
	bool getDie()const;
	staticBody* getBody(int i, Universe &map)const;
private:
	/*
	INHERITS:
	sf::CircleShape mShape;
	double mMass;
	double mRadius;
	double mXPos;
	double mYPos;
	double mXVel;
	double mYVel;
	& all setters and getters
	*/
	bool mDie; //If true, you die
};

class nonstaticBody : public Body //something that can move around, is affected (like the ball)
{
public:
	nonstaticBody(double initMass = 0, double initRadius = 0, double initxPos = 0, double inityPos = 0, double initxVel = 0, double inityVel = 0);
	//Getter
	nonstaticBody* getBody(int i, Universe &map);
	//Others
	void shoot(int i, Universe &map, sf::RenderWindow &window);
	void moving(Universe &map, sf::RenderWindow &window);

	/*
	INHERITS:
	sf::CircleShape mShape;
	double mMass;
	double mRadius;
	double mXPos;
	double mYPos;
	double mXVel;
	double mYVel;
	& all setters and getters
	*/
};

class constantBody : public nonstaticBody //like something orbiting another body, maintains constant path (like a moon orbitting a planet)
{
	//Constructor
	constantBody(double initMass = 0, double initRadius = 0, double initxPos = 0, double inityPos = 0, double initxVel = 0, double inityVel = 0);
	//Setters
	void setOrbittingBody(int newBody);
	void setDirection(bool newDirection);
	//Getters
	int getOrbittingBody()const;
	bool getDirection()const;
	constantBody* getBody(int i, Universe &map);
private:
	/*
	INHERITS:
	//From Body
	sf::CircleShape mShape;
	double mMass;
	double mRadius;
	double mXPos;
	double mYPos;
	double mXVel;
	double mYVel;
	& all setters and getters
	//From nonstaticBody
	bool mDie;
	& the setter and getter
	*/
	int mOrbittingBody; //What body the moon is orbitting
	bool mDirection; //Clockwise or counterclockwise
};

//int tutorial(int level, sf::RenderWindow &window, Universe &map, sf::CircleShape goal);
//int level1(int level, sf::RenderWindow &window, Universe &map, sf::CircleShape goal);
//int level(Universe &map, int goalXCoord, int goalYCoord);