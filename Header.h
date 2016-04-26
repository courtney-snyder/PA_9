#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;


void moving(sf::CircleShape ball[], sf::Vector2f direction[], float delta, int n);
void collide(sf::CircleShape ball[], sf::Vector2f direction[], int n);
float shotAngle(sf::Vector2f direction[], float delta, int x, int y);
