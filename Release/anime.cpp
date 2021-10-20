#include "anime.h"

void anime::set(sf::Vector2i size, sf::Vector2i colrow, sf::Time deltatime){
	deltaTime = deltatime;
	SIZE = size;
	CR = colrow;
	nowW = 0;
	FromTo.x = 0;
	FromTo.y = colrow.x;
}

void anime::set(sf::Vector2i ft){ // from x col to y col
	FromTo.x = ft.x;
	FromTo.y = ft.y;
}

sf::IntRect anime::update(){ // { LEFT, TOP , WIDTH ,HEIGHT }
    if(gv::worldClock.getElapsedTime() - now > deltaTime){
		now = gv::worldClock.getElapsedTime();
		if(nowW < FromTo.y-1 && nowW != -1){
			nowW++;
		}
		else {
			nowW = -1;
		}
	}
	return { SIZE.x*nowW,0,SIZE.x,SIZE.y };
}