#include "globalVar.h"
#include "anime.h"

class effect {
public:
	void setTexture(sf::Texture);
	void setRect();
	void resetRect();
public:
	sf::Texture texture;
	sf::RectangleShape check;
	sf::Sprite body;
	anime animation;

};