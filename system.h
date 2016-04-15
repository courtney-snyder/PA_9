#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define G = 6.67*pow(10, -11); //not sure if this is right, the N didn't work out well
//#define N = 100;


class Body
{
public:
	Body();
	Body(Body *& newBody);//not sure about this
	~Body();


	virtual double getMass() const;
	virtual double getxpos() const;
	virtual double getypos() const;

	virtual void setMass(double m);
	virtual void setXPos(double xPos);
	virtual void setYPos(double yPos);

	//find newPos
	//find newVeloc

private:
	double mass;
	double xpos;
	double ypos;
	double x_veloc;
	double y_veloc;
};


class Universe
{
public:
	Universe();
	~Universe();
	
	Body *& getBody(int i);
	double getMass(int i) const;
	double getxpos(int i) const;
	double getypos(int i) const;

	//void setBody();
	void setMass(int i, double m);
	void setXPos(int i, double xPos);
	void setYPos(int i, double yPos);

private:
	Body * Bodies[100];
	double mass[100]; 
	double xpos[100];//these are used by other functions instead of the values inside each "Body" object. This way, all moveable objects update at once.  
	double ypos[100];
};




class staticBody : public Body //does not move, is not affected by forces
{

};

class nonstaticBody : public Body //something that can move around, is affected
{

};

class constantBody : public Body //like something orbiting another body, maintains constant path
{

};