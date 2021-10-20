#pragma once
#include "globalVar.h"

class anime {
public:
	void set(sf::Vector2i, sf::Vector2i, sf::Time);
	void set(sf::Vector2i);
	sf::IntRect update();
public:
	sf::Vector2i SIZE;
	sf::Vector2i CR;
	sf::Vector2i FromTo;
	int nowW = 0 ;
	sf::Time now;
	sf::Time deltaTime;

};
