//#include "SFML/Graphics.hpp"
//#include "SFML/Audio.hpp"
//#include "SFML/System.hpp"
//#include "sfeMovie/Movie.hpp"
//#include <iostream>
//
//using namespace std;
//using namespace sf;
//
//sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dance Densu", sf::Style::Fullscreen | sf::Style::Close | sf::Style::Titlebar);
//
//sf::Texture Background1; Background1.loadFromFile("bg.jpg");
//sf::RectangleShape BG1(sf::Vector2f(1920.f, 1080.f)); BG1.setPosition(0, 0); BG1.setTexture(&Background);
//
//User1.setPosition(800.f, 360.f);
//sf::Texture Sprite1;
//Sprite1.loadFromFile("5555.png");
//User1.setOrigin(125, 125);
//sf::RectangleShape User1(sf::Vector2f(250.f, 250.f));
//
//
//int main()
//{
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && x > 50) {
//			s.move(-10, 0);
//			x -= 10;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x < 1870) {
//			s.move(10, 0);
//			x += 10;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && y < 1030) {
//			s.move(0, 10);
//			y += 10;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && y > 50) {
//			s.move(0, -10);
//			y -= 10;
//		}
//}