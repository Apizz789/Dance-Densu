#include "effect.h"

void effect::setTexture(sf::Texture tt){
	texture = tt;
	body.setTexture(texture);
}

void effect::setRect() {
	body.setTextureRect(animation.update());
}

void effect::resetRect(){
	animation.nowW = animation.FromTo.x;
}
