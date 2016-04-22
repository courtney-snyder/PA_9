#pragma once
#include "Body.h"
#include <SFML/Graphics.hpp>

int tutorial(int &level, sf::RenderWindow &window, nonstaticBody &ball, sf::CircleShape goal);
int level1(int &level, sf::RenderWindow &window, nonstaticBody &ball, staticBody &planet, sf::CircleShape goal);