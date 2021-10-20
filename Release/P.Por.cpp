//#include <SFML\Graphics.hpp>
//#include <SFML\System.hpp>
//
//#include <SFML\Audio.hpp>
//#include <SFML\OpenGL.hpp>
//#include <SFML/Graphics.hpp>
//#include <stdio.h>
//#include <conio.h>
//#include <vector>
//#include "FFT.h"
//#include <stdlib.h>
//#include <string>
//
//#define s_menu 0
//#define s_game 1
//
//sf::Font font;
//sf::Texture blueTexture;
//sf::Texture triTexture;
//sf::Texture playerTexture;
//sf::Texture bgTexture;
//sf::Texture bg2Texture;
//sf::Texture speakerTexture;
//sf::Texture swapTexture;
//
//float gravity = 1600;
//int isDown = 1;
//int dD = 1;
//bool normalMode = true;;
//bool isPause = false;
//bool isDeath = false;
//float score = 0;
//int state = 0;
//int selectedMenu = 0;
//
//RenderWindow window(sf::VideoMode(1280, 720), "PressSpaceBarTheGame");
//
//FFT fft1("Ressources/1.ogg", 4096);
//FFT fft("Ressources/1.ogg", 4096);
//
//
//void r_menu() 
//{
//	window.clear();
//	fft1.update(window);
//
//
//	int alpha = 5 * fft1.power + 150;
//	sf::Vector2f vCen = window.getView().getCenter();
//	sf::RectangleShape shape;
//	shape.setFillColor(sf::Color(255, 80 + (fft.power * 5), 0, alpha));
//	shape.setTexture(&bgTexture);
//	shape.setSize(sf::Vector2f(1280, 720));
//	shape.setPosition(vCen);
//	shape.setOrigin(1280 / 2, 720 / 2);
//	window.draw(shape);
//
//	sf::RectangleShape playerShape;
//	playerShape.setTexture(&playerTexture);
//	playerShape.setFillColor(sf::Color::Green);
//	playerShape.setRotation(45);
//	playerShape.setSize(sf::Vector2f(150, 150));
//	playerShape.setOrigin(sf::Vector2f(15, 15));
//	playerShape.setPosition(300, 200);
//	window.draw(playerShape);
//
//	sf::Text stxt;
//	stxt.setCharacterSize(50);
//	stxt.setString("Press SpaceBar \n     The Game");
//	stxt.setPosition(vCen.x - 330, vCen.y - 300);
//	stxt.setFont(font);
//	stxt.setColor(sf::Color::White);
//	window.draw(stxt);
//
//	sf::RectangleShape sShape;
//	sShape.setFillColor(sf::Color::Black);
//	if (selectedMenu == 0) {
//		sShape.setSize(sf::Vector2f(285, 50));
//		sShape.setPosition(vCen.x - 150, vCen.y - 105);
//	}
//	else {
//		sShape.setSize(sf::Vector2f(120, 50));
//		sShape.setPosition(vCen.x - 70, vCen.y + 15);
//	}
//
//	window.draw(sShape);
//
//	sf::Text ptxt;
//	ptxt.setCharacterSize(30);
//	ptxt.setString("Play game");
//	ptxt.setPosition(vCen.x - 140, vCen.y - 100);
//	ptxt.setFont(font);
//	ptxt.setColor(sf::Color::White);
//	ptxt.setOutlineColor(sf::Color::White);
//	window.draw(ptxt);
//
//	sf::Text etxt;
//	etxt.setCharacterSize(30);
//	etxt.setString("Exit");
//	etxt.setPosition(vCen.x - 60, vCen.y + 20);
//	etxt.setFont(font);
//	etxt.setColor(sf::Color::White);
//	window.draw(etxt);
//
//	sf::Text ntxt;
//	ntxt.setCharacterSize(24);
//	ntxt.setString("Suchakree Chatpoch 59O11427");
//	ntxt.setPosition(vCen.x, vCen.y + 200);
//	ntxt.setFont(font);
//	ntxt.setColor(sf::Color::White);
//	window.draw(ntxt);
//
//
//
//
//	window.display();
//}
//
//ac sdf() {
//	srand(time(NULL));
//	blueTexture.loadFromFile("Ressources\\blue.png");
//	playerTexture.loadFromFile("Ressources\\player.png");
//	bgTexture.loadFromFile("Ressources\\bg.png");
//	bg2Texture.loadFromFile("Ressources\\bg2.png");
//	triTexture.loadFromFile("Ressources\\tri.png");
//
//
//
//	speakerTexture.loadFromFile("Ressources\\vol.png");
//	swapTexture.loadFromFile("Ressources\\swap.png");
//
//
//	font.loadFromFile("font.ttf");
//	//init();
//	window.setFramerateLimit(70);
//	window.setActive(false);
//	
//	//sf::Thread renderThread(render);
//	//sf::Thread gameThread(update);
//	//renderThread.launch();
//	//gameThread.launch();
//	
//int lastx, lasty = 0;
//	fft1.sound.play();
//	fft1.sound.setPlayingOffset(sf::seconds(60));
//
//	while (window.isOpen()) {
//		Event event;
//		
//		sf::sleep(sf::milliseconds(10));
//	}
//
//	return 0;
//}