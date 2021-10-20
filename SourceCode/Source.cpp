#include "globalVar.h"
#include "effect.h"
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
using namespace sf;

struct Note
{
	sf::RectangleShape N;
	float speed = 1.275;
};


int sum;
bool LLOSE = false;
bool WWIN = false;
bool BONUSTIME = false;
int numhp = 100;
bool BONUS = false;
long long score = 0, score1, Sperfect = 0, Scool = 0, Sgood = 0, Smiss = 0;
int BonusBegin;

int Catperfect = 0;
int ch = true, rev = false, rev1 = false;
bool BonusTime = false;

bool STAR = false;
int numstr;
int BonusTimecount = 0;
int bonustimecount = 0;


int Cookie = 0;
sf::Clock CookieClock;
int CokieTime = 0;
bool cookieMovement = false;

bool mouse = false;
bool Healing = false;
bool Shushi = false;  bool getsushi = false, getcookie = false;;
bool Apple = false, getapple = false, applego = false;
int BT, gap = 0;

bool hpsp = false;
sf::Font font;
std::string input = " ";
sf::Clock cock, cock1, cock2, cock3, cock4, cockBN, cockAPP;
sf::Time redTime[10], Bg[10];
int randMusic;
sf::Texture bubu[10];
sf::Texture BOOM[10];
sf::Texture STR[10];
sf::Texture _star[10];
effect _BOOM[10][10], _bubu[10];

sf::Time LastPressed[5];
string scoretext[10];
int perfect = 2000, cool = 1000, miss = -1000;
int kperfect, kcool, kmiss;
sf::RectangleShape Eff_PERFECT[5];
sf::RectangleShape Eff_COOL[5];
sf::RectangleShape Eff_GOOD[5];
sf::RectangleShape Eff_MISS[5];
int effIDx[5];

void hsc(int kanan, string player)
{
	vector<pair<int, string> > score1;
	fstream myFile;
	myFile.open("KA.txt");
	string temp;
	string tempString;
	int tempInt = 0, P = 1;
	bool state = false;

	while (getline(myFile, temp))
	{
		if (state == false)
		{
			tempString = temp;
		}
		else
		{
			for (int i = temp.length() - 1; i >= 0; i--, P *= 10)
			{
				tempInt += (temp[i] - '0') * P;
			}
			score1.push_back(make_pair(tempInt, tempString));
			P = 1;
			tempInt = 0;
		}
		state = !state;

	}
	myFile.close();

	score1.push_back(make_pair(kanan, player));

	sort(score1.begin(), score1.end());

	myFile.open("KA.txt");
	for (int i = 5; i >= 1; i--)
	{
		myFile << score1[i].second << "\n" << score1[i].first << endl;
		cout << score1[i].first << " -- " << score1[i].second << endl;
	}

	myFile.close();

}
void showscore()
{
	std::fstream showscore1;
	showscore1.open("KA.txt");
	std::string show;
	int z = 0;

	while (getline(showscore1, show))
	{
		scoretext[z] = show;
		z++;
		if (z >= 10)
		{
			break;
		}
	}
	showscore1.close();
}
void Float(sf::RectangleShape& spa, int idx) {
	Eff_PERFECT[idx].setFillColor(sf::Color::Transparent);
	Eff_COOL[idx].setFillColor(sf::Color::Transparent);
	Eff_GOOD[idx].setFillColor(sf::Color::Transparent);
	Eff_MISS[idx].setFillColor(sf::Color::Transparent);
	if (spa.getPosition().y > 665.f) {
		spa.move(0, -1);
		spa.setFillColor(sf::Color::White);
	}
	else {
		spa.setFillColor(sf::Color::Transparent);
		effIDx[idx] = -1;
	}
}


int main()
{

	RenderWindow window(sf::VideoMode::getDesktopMode(), "Dance Densu", sf::Style::Fullscreen);
	sf::Font font;
	font.loadFromFile("FONTT.ttf"); //// <- Enter font here

	sfe::Movie OP;
	OP.openFromFile("Open.mp4");
	OP.fit(0, 0, 1920, 1080);

	srand(time(NULL));

#pragma region INIT
	bool BEGIN = true;
	bool NAME = false;
	bool MENU = false;
	bool PLAY = false;
	bool STORY = false;
	bool HOWTOPLAY = false;
	bool HIGHSCORE = false;
	bool EXIT = false;
	bool WL = false;

	sf::Image Icon;
	Icon.loadFromFile("icon.JPG");
	window.setIcon(480, 480, Icon.getPixelsPtr());



	sf::RectangleShape AKB(sf::Vector2f(1920.f, 1080.f));
	sf::RectangleShape thk(sf::Vector2f(1920.f, 1080.f));

	//////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////

	sf::Texture _BEGIN, _thk; _BEGIN.loadFromFile("LOGO.PNG"); _thk.loadFromFile("THK.png");
	AKB.setTexture(&_BEGIN); thk.setTexture(&_thk); thk.setPosition(20, 0);

	////  Load the icon  ////
	sf::Image image;
	sf::Cursor cursor;

	if (!image.loadFromFile("icon.png"))
		return -1;
	if (!cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), { 0, 0 }))
		return -1;
	window.setMouseCursor(cursor);

#pragma endregion 

#pragma region jaDE 
	int oppa = 0;
	while (BEGIN && cock1.getElapsedTime() < sf::seconds(7))
	{
		if (cock1.getElapsedTime().asMilliseconds() % 10 == 0)
		{
			if (oppa < 255)
				AKB.setFillColor(sf::Color(255, 255, 255, oppa += 3));
		}
		window.clear();
		window.draw(AKB);
		window.display();

	}
	cock1.restart();
	while (BEGIN && cock1.getElapsedTime() <= sf::seconds(3)) {
		if (cock1.getElapsedTime().asMilliseconds() % 10 == 0) {
			if (oppa > 0)
				AKB.setFillColor(sf::Color(255, 255, 255, oppa -= 3));
		}

		window.clear();
		window.draw(AKB);
		window.display();

	}
	cock1.restart();
	while (BEGIN && cock1.getElapsedTime() <= sf::seconds(56.5))
	{
		OP.play(); OP.setVolume(80);

		OP.update();
		window.clear();
		window.draw(OP);
		window.display();
	}
	OP.stop();
	cock1.restart();
	while (BEGIN && cock1.getElapsedTime() < sf::seconds(3)) {
		if (cock1.getElapsedTime().asMilliseconds() % 10 == 0) {
			if (oppa < 255)
				thk.setFillColor(sf::Color(255, 255, 255, oppa += 3));
		}

		window.clear();
		window.draw(thk);
		window.display();
	}

	MENU = true;  /// <<< PLZ OPEN this LINE
//////////////////////////////////////////////////////---------------------------------------------/////////////////////////////////////////////////////////////////

#pragma endregion

	while (EXIT == false && window.isOpen())
	{
		//////////////////////// MENU PAGE /////////////////////////
		if (MENU == true)
		{
			PLAY = false;
			numstr = 0;
			rev = false;
			rev1 = false;
			Sperfect = 0; Scool = 0; Sgood = 0; Smiss = 0; score = 0;
			cookieMovement = false;
			Cookie = 0;
			numhp = 500;
			LLOSE = false;
			WWIN = false;
			sum = 0;
			hpsp = false;
			Shushi = false;
			getsushi = false;
			getcookie = false;
			getapple = false;
			applego = false;
			BT = 0; gap = 0;
			cock4.restart();
			mouse = false;

			sf::Text ScoreText[10];
			for (int j = 0; j < 10; j++)
			{
				ScoreText[j].setFont(font);
				ScoreText[j].setCharacterSize(40);
				ScoreText[j].setFillColor(sf::Color::Black);
			}
			showscore();
			int name_y = -900;
			int score_y = -900;

			for (int a = 0; a < 10; a++)
			{
				if (a % 2 == 0)
				{
					ScoreText[a].setString(scoretext[a]);
					ScoreText[a].setPosition(1100, name_y += 150);  /// 350 
				}
				else
				{
					ScoreText[a].setString(scoretext[a]);
					ScoreText[a].setPosition(1600, score_y += 150);
				}
				std::cout << scoretext[a] << std::endl;
			}

			//////////////////////////////////
			input = " ";
			sf::Texture  MENU1, MENU2, MENU3, MENU4, MENU5, MENU6, BG_MENU1, BG_MENU2, BG_MENU3, BG_MENU4;
			sf::Texture  _BEGINPAGE;
			_BEGINPAGE.loadFromFile("LOGO1.png");

			sf::RectangleShape begin(sf::Vector2f(1920, 1080));

			begin.setPosition(0.f, -170.f); begin.setTexture(&_BEGINPAGE);

			MENU1.loadFromFile("B_play.png");
			MENU2.loadFromFile("B_story.png");
			MENU3.loadFromFile("B_howtoplay.png");
			MENU4.loadFromFile("B_highscore.png");
			MENU5.loadFromFile("B_demo.png");
			MENU6.loadFromFile("B_exit.png");

			BG_MENU1.loadFromFile("BG_MENU_1.png");
			BG_MENU2.loadFromFile("BG_MENU_2.png");
			BG_MENU3.loadFromFile("BG_MENU_3.png");

			sf::RectangleShape BPLAY(sf::Vector2f(500.f, 120.f));
			sf::RectangleShape BSTORY(sf::Vector2f(500.f, 120.f));
			sf::RectangleShape BHOWTO(sf::Vector2f(500.f, 120.f));
			sf::RectangleShape BHIGHS(sf::Vector2f(500.f, 120.f));
			sf::RectangleShape BDEMO(sf::Vector2f(500.f, 200.f));
			sf::RectangleShape BEXIT(sf::Vector2f(500.f, 120.f));

			sf::RectangleShape BGMENU1(sf::Vector2f(2420.f, 1080.f));
			sf::RectangleShape BGMENU2(sf::Vector2f(1920.f, 1580.f));
			sf::RectangleShape BGMENU3(sf::Vector2f(2520.f, 1080.f));

			BPLAY.setPosition(710.745f, 788.589f); BPLAY.setTexture(&MENU1);
			BSTORY.setPosition(72.356, 670.632); BSTORY.setTexture(&MENU2);
			BHOWTO.setPosition(72.356, 907.069); BHOWTO.setTexture(&MENU3);
			BHIGHS.setPosition(1341.782, 670.632); BHIGHS.setTexture(&MENU4);
			BDEMO.setPosition(1426, 865); BDEMO.setTexture(&MENU5);
			BEXIT.setPosition(1341.782, 907.069); BEXIT.setTexture(&MENU6);


			BGMENU1.setPosition(0, 0); BGMENU1.setTexture(&BG_MENU1);
			BGMENU2.setPosition(0, 0); BGMENU2.setTexture(&BG_MENU2);
			BGMENU3.setPosition(0, 0); BGMENU3.setTexture(&BG_MENU3);

			sf::Texture htp1, htp2, htp3, htp4;
			htp1.loadFromFile("HTP1.png");
			htp2.loadFromFile("HTP2.png");
			htp3.loadFromFile("HTP3.png");
			htp4.loadFromFile("HTP4.png");
			sf::RectangleShape HTP1(sf::Vector2f(1870.f, 1078.f));
			sf::RectangleShape HTP2(sf::Vector2f(1870.f, 1078.f));
			sf::RectangleShape HTP3(sf::Vector2f(1870.f, 1078.f));
			sf::RectangleShape HTP4(sf::Vector2f(1870.f, 1078.f));
			// from 960 1038 to 960 538

			HTP1.setPosition(25, 1100); HTP1.setTexture(&htp1);
			HTP2.setPosition(25, 2160); HTP2.setTexture(&htp2);
			HTP3.setPosition(25, 3260); HTP3.setTexture(&htp3);
			HTP4.setPosition(25, 4340); HTP4.setTexture(&htp4);

			sf::Texture hs;
			hs.loadFromFile("HSC.png");
			sf::RectangleShape HSC(sf::Vector2f(1870.f, 1078.f));
			HSC.setPosition(25, -1100); HSC.setTexture(&hs);


			/////////////////////////////////////////////////////////

			BGMENU1.setPosition(-150, 0);
			BGMENU2.setPosition(0, -150);
			BGMENU3.setPosition(-150, 0);

			float a = 200, b = 0.1;
			float logo_a = 200, logo_b = 0.1;

			window.setFramerateLimit(1000);
			sfe::Movie A0;

			A0.openFromFile("AV0.mp4");
			A0.fit(0, 0, 1920, 1080);
			A0.play();
			A0.setVolume(90);

			/////////////////////// Decrease Opacity ////////////////////
			cock1.restart();
			while (BEGIN && cock1.getElapsedTime() < sf::seconds(3)) {
				if (cock1.getElapsedTime().asMilliseconds() % 10 == 0) {
					if (oppa > 0)
						thk.setFillColor(sf::Color(255, 255, 255, oppa -= 3));
				}

				window.clear();
				window.draw(thk);
				window.display();
			}
			BEGIN = false;

			////////////////////////               Sound             /////////////////////////////////

			sf::SoundBuffer buffer3;
			if (!buffer3.loadFromFile("button.ogg"))
			{

			}
			sf::Sound sound3;
			sound3.setBuffer(buffer3);
			sound3.setVolume(80);
			////////////////////////////////////////////////////////////////

			while (window.isOpen() && MENU == true)
			{

				if (A0.getStatus() == sfe::Stopped)
				{
					int r = rand() % 20;
					A0.openFromFile("AV" + to_string(r) + ".mp4");
					A0.play(); A0.setVolume(100);
				}

				sf::Event event;
				while (window.pollEvent(event)) /// ???????????????????????????????
				{

					sf::Vector2f mouseCord;
					mouseCord.x = float(sf::Mouse::getPosition(window).x);
					mouseCord.y = float(sf::Mouse::getPosition(window).y);
					///////////////////////////////////////// BUTTON PRESSED ////////////////////////////////////////////
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						if (BPLAY.getGlobalBounds().contains(mouseCord))
							if (BPLAY.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
							{
								sound3.play();
								A0.stop();
								BPLAY.setScale(0.f, 0.8f);
								ch = false;
								rev = true;
								rev1 = true;
								NAME = true;
								MENU = false;
								HOWTOPLAY = false;
								HIGHSCORE = false;
								system("cls");
								std::cout << "BPLAY\n";
							}

						if (BSTORY.getGlobalBounds().contains(mouseCord))
						{
							sound3.play();
							BSTORY.setScale(0.f, 0.8f);
							ch = false;
							STORY = true;
							MENU = false;
							NAME = false;
							HOWTOPLAY = false;
							HIGHSCORE = false;
							system("cls");
							std::cout << "BSTORY\n";
						}
						if (BHOWTO.getGlobalBounds().contains(mouseCord))
						{
							sound3.play();
							BHOWTO.setScale(0.f, 0.8f);
							HOWTOPLAY = true;
							rev = false;
							system("cls");
							std::cout << "BHOWTO\n";
						}
						if (BHIGHS.getGlobalBounds().contains(mouseCord))
						{
							sound3.play();

							BHIGHS.setScale(0.f, 0.8f);
							HIGHSCORE = true;
							rev1 = false;
							system("cls");
							std::cout << "BHIGHS\n";
						}
						if (BEXIT.getGlobalBounds().contains(mouseCord))
						{
							sound3.play();

							BEXIT.setScale(0.f, 0.8f);
							window.close();
							return 0;
							system("cls");
							std::cout << "BEXIT\n";
						}

					}
					if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
					{

						BPLAY.setScale(1.f, 1.f);


						BSTORY.setScale(1.f, 1.f);


						BHOWTO.setScale(1.f, 1.f);


						BHIGHS.setScale(1.f, 1.f);


						BEXIT.setScale(1.f, 1.f);


					}

				}

				if (!rev)
				{
					if (HOWTOPLAY == true)
					{
					
						if (HTP4.getPosition().y > 0) {
							for (int j = 0; j < 2; j++)
							{
								begin.move(0, -0.5);
								BPLAY.move(0, -0.5);
								BHOWTO.move(0, -0.5);
								BSTORY.move(0, -0.5);
								BHIGHS.move(0, -0.5);
								BEXIT.move(0, -0.5);
							}

							for (int j = 0; j < 2; j++)
							{
								HTP1.move(0, -0.5);
								HTP2.move(0, -0.5);
								HTP3.move(0, -0.5);
								HTP4.move(0, -0.5);
							}
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							rev = true;
						}
					}
				}
				else
				{

					if (HTP1.getPosition().y < 1098)
					{
						for (int j = 0; j < 2; j++)
						{
							begin.move(0, 0.5);
							BPLAY.move(0, 0.5);
							BHOWTO.move(0, 0.5);
							BSTORY.move(0, 0.5);
							BHIGHS.move(0, 0.5);
							BEXIT.move(0, 0.5);
						}

						for (int j = 0; j < 2; j++)
						{
							HTP1.move(0, 0.5);
							HTP2.move(0, 0.5);
							HTP3.move(0, 0.5);
							HTP4.move(0, 0.5);

						}
					}

				}

				if (!rev1)
				{
					if (HIGHSCORE == true)
					{
						if (HSC.getPosition().y < 0)
						{
							for (int j = 0; j < 2; j++)
							{
								begin.move(0, 1);
								BPLAY.move(0, 1);
								BHOWTO.move(0, 1);
								BSTORY.move(0, 1);
								BHIGHS.move(0, 1);
								BEXIT.move(0, 1);
							}
							for (int j = 0; j < 2; j++)
							{
								HSC.move(0, 1);
							}
							name_y = HSC.getPosition().y + 200;
							score_y = HSC.getPosition().y + 200;
							for (int a = 0; a < 10; a++)
							{
								if (a % 2 == 0)
								{

									ScoreText[a].setPosition(1100, name_y += 150);

								}
								else
								{

									ScoreText[a].setPosition(1600, score_y += 150);
								}

							}
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							rev1 = true;
						}
					}
				}
				else
				{

					if (HSC.getPosition().y > -1100)
					{
						if (begin.getPosition().y > -170)
						{
							for (int j = 0; j < 1; j++)
							{
								begin.move(0, -1);
								BPLAY.move(0, -1);
								BHOWTO.move(0, -1);
								BSTORY.move(0, -1);
								BHIGHS.move(0, -1);
								BEXIT.move(0, -1);
							}
						}
						HSC.move(0, -1);
						for (int a = 0; a < 10; a++)
						{

							if (a % 2 == 0)
							{
								ScoreText[a].move(0, -1);
							}
							else
							{
								ScoreText[a].move(0, -1);
							}

						}
					}

				}


				BGMENU1.move(sin(a), 0);
				BGMENU2.move(0, sin(a));
				BGMENU3.move(sin(a), 0);

				if (begin.getPosition().x + 1030 < Mouse::getPosition().x)
				{
					a -= 0.01;
					while (sin(logo_b) < 0) logo_b += 0.01;
					if (sin(logo_b) < 0.9) {
						logo_b += 0.01;
					}
				}
				else if (begin.getPosition().x + 1030 > Mouse::getPosition().x)
				{
					while (sin(logo_b) > 0) logo_b -= 0.01;
					if (sin(logo_b) > -0.9) {
						logo_b -= 0.01;
					}
				}
				begin.move(sin(logo_b), 0);
				b += 0.01; a -= 0.01;

				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				A0.update();

				window.clear();

				window.draw(A0);

				window.setMouseCursorVisible(true);

				window.draw(BGMENU3);
				window.draw(BGMENU2);
				window.draw(BGMENU1);
				window.draw(BPLAY);
				window.draw(BHOWTO);
				window.draw(BSTORY);
				window.draw(BHIGHS);
				window.draw(BEXIT);

				window.draw(begin);

				window.draw(HTP1);
				window.draw(HTP2);
				window.draw(HTP3);
				window.draw(HTP4);

				window.draw(HSC);
				for (int j = 0; j < 10; j++)
				{
					window.draw(ScoreText[j]);
				}
				window.display();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
					return 0;
				}
			}

		}
		if (STORY == true)
		{
			sfe::Movie str;
			str.openFromFile("STORY.mp4");
			str.fit(0, 0, 1920, 1080);
			str.play();
			str.setVolume(100);
			while (window.isOpen() && STORY == true)
			{
				if (str.getStatus() == sfe::Stopped)
				{
					STORY = false;
					MENU = true;

				}
				str.update();
				window.clear();

				window.draw(str);
				window.setMouseCursorVisible(false);
				window.display();
			}
		}
		if (NAME == true)
		{

			sf::Texture MENU7;
			MENU7.loadFromFile("B_enter.png");
			sf::RectangleShape BMOUSE(sf::Vector2f(137.f, 83.f));
			BMOUSE.setPosition(1700, 50); BMOUSE.setTexture(&MENU7);
			BMOUSE.setFillColor(sf::Color::Red);

			sf::RectangleShape object;
			object.setSize(sf::Vector2f(300.0f, 70.0f));
			object.setOrigin(sf::Vector2f(150.0f, 35.0f));
			object.setPosition(sf::Vector2f(1000, 600.0f));

			sf::RectangleShape cursor;
			cursor.setSize(sf::Vector2f(5.0f, 64.0f));
			cursor.setOrigin(sf::Vector2f(2.5f, 32.0f));
			cursor.setPosition(sf::Vector2f(730, 625.0f));
			cursor.setFillColor(sf::Color::Black);

			float totalTime = 0;
			sf::Clock clock;
			bool state = false;

			char last_char = ' ';

			sf::Text text;
			text.setFont(font);
			text.setCharacterSize(40);
			text.setFillColor(sf::Color::Black);
			text.setPosition(725, 600);

			sf::Texture lg, tex;
			lg.loadFromFile("name.png");
			tex.loadFromFile(".............png");
			sf::RectangleShape bgname(sf::Vector2f(1980.f, 1080.f));

			sf::RectangleShape iconname(sf::Vector2f(1870.f, 1078.f));
			bgname.setPosition(0, 0); bgname.setTexture(&lg);
			iconname.setPosition(25, -1100); iconname.setTexture(&lg);

			sf::Sound sound11, Smouse;
			sf::SoundBuffer buffer11, SSmouse;
			if (!buffer11.loadFromFile("JP.wav"))
			{
			}
			if (!SSmouse.loadFromFile("mouse.wav"))
			{
			}
			sound11.setBuffer(buffer11); /// menu
			sound11.setVolume(100);
			sound11.play();
			sound11.setLoop(true);
			Smouse.setBuffer(SSmouse); /// menu
			Smouse.setVolume(100);
			Smouse.play();

			while (window.isOpen() && NAME == true)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					sf::Vector2f mouseCord;
					mouseCord.x = float(sf::Mouse::getPosition(window).x);
					mouseCord.y = float(sf::Mouse::getPosition(window).y);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (BMOUSE.getGlobalBounds().contains(mouseCord))
						{
							Smouse.play();
							mouse = true;
							BMOUSE.setScale(0.f, 0.8f);
							text.setString("               /AKB48/        ");
							NAME = false; PLAY = true;
						}
						else
						{
							BMOUSE.setScale(1.f, 1.f);
						}
					}
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
					if (event.type == sf::Event::EventType::KeyPressed)
					{
						bool ogg = true;
						if (event.key.code == sf::Keyboard::Enter)
						{

							ogg = false;
							if (ogg == false)
							{
								NAME = false;
								PLAY = true;

							}
						}
					}
				}

				if (event.type == sf::Event::EventType::TextEntered)
				{

					if (last_char != event.text.unicode && event.text.unicode == 8 &&
						input.length() > 0) // delete
					{

						last_char = event.text.unicode;
						input.erase(input.length() - 1);
						text.setString(input);
						cursor.setPosition(725.0f + text.getGlobalBounds().width + 5, 625.f);
						std::cout << input << std::endl;

					}
					else if (last_char != event.text.unicode &&
						(event.text.unicode >= 'a' && event.text.unicode <= 'z' ||
							event.text.unicode >= 'A' && event.text.unicode <= 'Z' ||
							event.text.unicode >= '0' && event.text.unicode <= '9'))
					{

						last_char = event.text.unicode;

						input += event.text.unicode;

						text.setString(input);

						cursor.setPosition(725.0f + text.getGlobalBounds().width + 5, 625.0f);

						std::cout << input << std::endl;
					}

				}

				if (event.type == sf::Event::EventType::KeyReleased && last_char != ' ')
				{
					last_char = ' ';
				}


				window.clear();

				window.draw(bgname);

				totalTime += clock.restart().asSeconds();
				if (totalTime >= 0.5)
				{
					totalTime = 0;
					state = !state;
				}
				if (state == true)
				{
					window.draw(cursor);
				}

				window.draw(BMOUSE);
				window.draw(text);
				window.display();

			}

		}
		if (PLAY == true)
		{
			//////////////////////////////////////////////////////////////////////////////

			srand(time(0));
			font.loadFromFile("FONTT.ttf");
			sf::Text P("PER : ", font, 50U);
			sf::Text p("", font, 80U);
			sf::Text S("", font, 60U);

			p.setPosition(100.f, 350.f);
			p.setFillColor(sf::Color::Black);

			P.setPosition(15.f, 5.f);
			P.setFillColor(sf::Color::Black);

			S.setPosition(1260.f, -5.f);
			S.setFillColor(sf::Color::Black);


			//////////////////////////////////////////////////////////////////////////////
			float X = 800, Y = 360;

			long long  hp = 17500, max = hp;


			sf::Texture status, blood, hearto, heart1, STR, STR1, STR2, STR3, STR4, bonus, bonus2, bonus3, bonus4;

			status.loadFromFile("status.png");
			sf::RectangleShape ST(sf::Vector2f(1920.f, 1080.f));
			ST.setPosition(0, 0); ST.setTexture(&status);

			blood.loadFromFile("color blood.png");
			sf::RectangleShape BD(sf::Vector2f(684.f, 53.f));
			BD.setPosition(1222, 110); BD.setTexture(&blood);

			hearto.loadFromFile("hreato0.png");
			sf::RectangleShape HAT(sf::Vector2f(105.f, 87.f));
			HAT.setPosition(1197, 95); HAT.setTexture(&hearto);

			heart1.loadFromFile("hreato.png");
			sf::RectangleShape HAT1(sf::Vector2f(105.f, 87.f));
			HAT1.setPosition(1197, 95); HAT1.setTexture(&heart1);

			bonus.loadFromFile("CAT.png");
			sf::RectangleShape CAT(sf::Vector2f(189.f, 171.f));
			CAT.setPosition(0, 331); CAT.setTexture(&bonus); CAT.setOrigin(189 / 2.f, 171 / 2.f);

			bonus2.loadFromFile("sushi.png");
			sf::RectangleShape SUS(sf::Vector2f(189.f, 171.f));
			SUS.setPosition(-500, 400); SUS.setTexture(&bonus2); SUS.setOrigin(189 / 2.f, 171 / 2.f);

			bonus3.loadFromFile("cookie.png");
			sf::RectangleShape COK(sf::Vector2f(189.f, 171.f));
			COK.setPosition(-500, 330); COK.setTexture(&bonus3); COK.setOrigin(189 / 2.f, 171 / 2.f);

			bonus4.loadFromFile("apple1s5p0k8.png");
			sf::RectangleShape APP(sf::Vector2f(189.f, 171.f));
			APP.setPosition(-500, 330); APP.setTexture(&bonus4); APP.setOrigin(189 / 2.f, 171 / 2.f);

			STR.loadFromFile("star.png");
			sf::RectangleShape star(sf::Vector2f(78.f, 69.f));
			star.setPosition(705, 3); star.setTexture(&STR);

			STR1.loadFromFile("star.png");
			sf::RectangleShape star1(sf::Vector2f(78.f, 69.f));
			star1.setPosition(705 + 90 * 1, 3); star1.setTexture(&STR1);

			STR2.loadFromFile("star.png");
			sf::RectangleShape star2(sf::Vector2f(78.f, 69.f));
			star2.setPosition(705 + 90 * 2, 3); star2.setTexture(&STR2);

			STR3.loadFromFile("star.png");
			sf::RectangleShape star3(sf::Vector2f(78.f, 69.f));
			star3.setPosition(704 + 91 * 3, 3); star3.setTexture(&STR3);

			STR4.loadFromFile("star.png");
			sf::RectangleShape star4(sf::Vector2f(78.f, 69.f));
			star4.setPosition(704 + 91 * 4, 3); star4.setTexture(&STR4);

			/////////////////////////////////////////////////////////////////////////////////////////////////////
			for (int i = 1; i <= 4; i++) {
				BOOM[i].loadFromFile("B" + std::to_string(i) + ".png");
				bubu[i].loadFromFile("SABU.png");
			}

			for (int i = 1; i <= 4; i++) {
				for (int j = 1; j <= 4; j++)
				{
					_BOOM[i][j].setTexture(BOOM[j]);
					_BOOM[i][j].animation.set({ 233,207 }, { 12,1 }, sf::seconds(0.09));
					_BOOM[i][j].setRect();
					_BOOM[i][j].resetRect();
					_BOOM[i][j].body.setPosition(210 + (i - 1) * 400, 850);
					_BOOM[i][j].animation.nowW = -1;
				}
			}

			for (int i = 1; i <= 4; i++)
			{
				_bubu[i].setTexture(bubu[i]);
				_bubu[i].animation.set({ 395,346 }, { 7,1 }, sf::seconds(0.09));
				_bubu[i].setRect();
				_bubu[i].resetRect();
				_bubu[i].body.setPosition(120 + (i - 1) * 400, 750);
				_bubu[i].animation.nowW = -1;
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			sf::Texture Arrow_UP, Arrow_DOWN, Arrow_RIGHT, Arrow_LEFT, BG_Status;
			Arrow_UP.loadFromFile("Arrow_UP.png");
			Arrow_DOWN.loadFromFile("Arrow_DOWN.png");
			Arrow_LEFT.loadFromFile("Arrow_LEFT.png");
			Arrow_RIGHT.loadFromFile("Arrow_RIGHT.png");
			BG_Status.loadFromFile("BG_Status.png");

			sf::RectangleShape Arrow1(sf::Vector2f(183.117f, 183.117f));
			sf::RectangleShape Arrow2(sf::Vector2f(183.117f, 183.117f));
			sf::RectangleShape Arrow3(sf::Vector2f(183.117f, 183.117f));
			sf::RectangleShape Arrow4(sf::Vector2f(183.117f, 183.117f));
			sf::RectangleShape BG3(sf::Vector2f(2420.f, 1080.f));
			Arrow1.setPosition(238, 865); Arrow1.setTexture(&Arrow_UP);
			Arrow2.setPosition(634, 865); Arrow2.setTexture(&Arrow_DOWN);
			Arrow3.setPosition(1030, 865); Arrow3.setTexture(&Arrow_LEFT);
			Arrow4.setPosition(1426, 865); Arrow4.setTexture(&Arrow_RIGHT);

			BG3.setPosition(0, 0); BG3.setTexture(&BG_Status); BG3.setFillColor(sf::Color::Black);
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			sf::Texture Eperfect, Ecool, Egood, Emiss;
			Eperfect.loadFromFile("Eff_PERFECT.png");
			Ecool.loadFromFile("Eff_COOL.png");
			Egood.loadFromFile("Eff_GOOD.png");
			Emiss.loadFromFile("Eff_MISS.png");
			for (int i = 0; i < 5; i++)
			{
				/// 340 102 ///
				Eff_PERFECT[i].setSize({ 340,102 });
				Eff_COOL[i].setSize({ 340,102 });
				Eff_GOOD[i].setSize({ 340,102 });
				Eff_MISS[i].setSize({ 340,102 });

				Eff_PERFECT[i].setPosition(238, 765); Eff_PERFECT[i].setTexture(&Eperfect); Eff_PERFECT[i].setOrigin(340 / 2.f, 102 / 2.f);
				Eff_COOL[i].setPosition(634, 765); Eff_COOL[i].setTexture(&Ecool);  Eff_COOL[i].setOrigin(340 / 2.f, 102 / 2.f);
				Eff_GOOD[i].setPosition(1030, 765);	Eff_GOOD[i].setTexture(&Egood); Eff_GOOD[i].setOrigin(340 / 2.f, 102 / 2.f);
				Eff_MISS[i].setPosition(1426, 765);  Eff_MISS[i].setTexture(&Emiss); Eff_MISS[i].setOrigin(340 / 2.f, 102 / 2.f);
				Eff_PERFECT[i].setFillColor(sf::Color::Transparent);
				Eff_COOL[i].setFillColor(sf::Color::Transparent);
				Eff_GOOD[i].setFillColor(sf::Color::Transparent);
				Eff_MISS[i].setFillColor(sf::Color::Transparent);
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			sf::Texture arrows1, arrows2, arrows3, arrows4;
			arrows1.loadFromFile("arrows1.png");
			arrows2.loadFromFile("arrows2.png");
			arrows3.loadFromFile("arrows3.png");
			arrows4.loadFromFile("arrows4.png");

			Note a[5], b[5];
			for (int i = 0; i < 4; i++)
			{
				a[i].N.setSize({ 183.117f, 183.117f });
				a[i].speed = 1.252;
				b[i].N.setSize({ 183.117f, 183.117f });
				b[i].speed = 1.252;

			}

			a[0].N.setPosition(238, 0);  a[0].N.setTexture(&arrows1);
			a[1].N.setPosition(634, 0);  a[1].N.setTexture(&arrows2);
			a[2].N.setPosition(1030, 0); a[2].N.setTexture(&arrows3);
			a[3].N.setPosition(1426, 0); a[3].N.setTexture(&arrows4);

			b[0].N.setPosition(238, 0);  b[0].N.setTexture(&arrows1);
			b[1].N.setPosition(634, 0);  b[1].N.setTexture(&arrows2);
			b[2].N.setPosition(1030, 0); b[2].N.setTexture(&arrows3);
			b[3].N.setPosition(1426, 0); b[3].N.setTexture(&arrows4);

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			sf::SoundBuffer buffer1;
			if (!buffer1.loadFromFile("open.wav"))
			{
				std::cout << "Sound" << std::endl;
			}
			sf::Sound sound_BG;

			sf::SoundBuffer buffer2;
			if (!buffer2.loadFromFile("sound2.wav"))
			{
			}
			sf::Sound sound_2;
			sound_2.setBuffer(buffer2);

			sf::SoundBuffer buffer3;
			if (!buffer3.loadFromFile("clik.wav"))
			{

			}
			sf::Sound sound3;
			sound3.setBuffer(buffer3);
			sound3.setVolume(50);

			sf::SoundBuffer buffer4;
			if (!buffer4.loadFromFile("Fail.wav"))
			{

			}
			sf::Sound sound4;
			sound4.setBuffer(buffer4);
			sound4.setVolume(100);

			sf::SoundBuffer buffer5;
			if (!buffer5.loadFromFile("break.wav"))
			{

			}
			sf::Sound sound5;
			sound5.setBuffer(buffer5);
			sound5.setVolume(100);

			sf::SoundBuffer buffer6;

			if (!buffer6.loadFromFile("cat.wav"))
			{
			}
			sf::SoundBuffer buffer7;
			if (!buffer7.loadFromFile("star.wav"))
			{
			}
			sf::SoundBuffer buffer8;
			if (!buffer8.loadFromFile("bonus.wav"))
			{
			}
			sf::SoundBuffer buffer9;
			if (!buffer9.loadFromFile("so1.wav"))
			{
			}
			sf::SoundBuffer buffer10;
			if (!buffer10.loadFromFile("break.wav"))
			{
			}
			sf::SoundBuffer buffer11;
			if (!buffer11.loadFromFile("eat.wav"))
			{
			}

			sf::Sound sound6, sound7, sound8, sound9, sound10, sound11;

			sound6.setBuffer(buffer6);  /// cat       
			sound6.setVolume(100);
			sound7.setBuffer(buffer7);  /// star
			sound7.setVolume(60);
			sound8.setBuffer(buffer8);  /// bonus
			sound8.setVolume(100);
			sound9.setBuffer(buffer9); /// win
			sound9.setVolume(100);
			sound10.setBuffer(buffer10); /// lose
			sound10.setVolume(100);
			sound11.setBuffer(buffer11); /// eat
			sound11.setVolume(100);


			sound6.play();

			///////////////////////////////////////////////////////////////////////
			sf::Sound eff1, eff2, eff3, eff4, eff5, eff6;
			sf::SoundBuffer buff1, buff2, buff3, buff4, buff5, buff6;



			if (!buff2.loadFromFile("blood.wav"))
			{
			}
			eff2.setBuffer(buff2); /// blood
			eff2.setVolume(100);

			if (!buff3.loadFromFile("apple.wav"))
			{
			}
			eff3.setBuffer(buff3); /// apple
			eff3.setVolume(100);

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			if (!sf::SoundBufferRecorder::isAvailable())
			{
				std::cout << "you need to install a mic" << std::endl;
			}
			sf::SoundBufferRecorder recorder;
			sf::SoundBuffer buffer;
			sf::Sound sound;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			float ad = 100;
			float ads = 100;
			float adck = 100;
			float ajed = 100;

			CAT.move(0.01, sin(ad));
			SUS.move(-1, -sin(ads));
			COK.move(1, sin(adck));
			APP.move(1, sin(ajed));

			ad += 0.01;
			ads += 0.01;
			adck += 0.01;
			ajed += 0.01;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//////////////////////////////////////   Video    /////////////////////////////////////////

			sfe::Movie A1, Ap;
			randMusic = rand() % 22;
			A1.openFromFile("AV" + std::to_string(randMusic) + ".mp4");
			Ap.openFromFile("Ap.mp4");
			/*A1.openFromFile("AV4.mp4");*/
			A1.fit(0, 0, 1920, 1080); Ap.fit(0, 0, 1920, 1080);
			A1.play();
			A1.setVolume(90); Ap.setVolume(90);
			cout << " " << endl << to_string(randMusic);

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////// Load the icon
			sf::Image image;
			sf::Cursor cursor;
			if (!image.loadFromFile("icon.png"))
				return -1;
			if (!cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), { 0, 0 }))
				return -1;
			while (window.isOpen() && PLAY == true)
			{
				sf::Time BonusTimer = cock3.getElapsedTime();
				BonusTimecount = BonusTimer.asSeconds();
				sf::Time Cokie = cock4.getElapsedTime();

				CokieTime = Cokie.asSeconds();
				sf::Event event;
				if (BonusTime == false)
				{
					ad += 0.01;
					CAT.move(1, sin(ad));

					if (CAT.getPosition().x > 2000)
					{
						Catperfect = 0;
						cock2.restart();
						CAT.setPosition(-500, 450);
					}
				}
				if (BonusTime == true)
				{
					Catperfect = 0;
					if (sound8.getStatus() != sf::Sound::Status::Playing && numstr >= 10)
					{
						sound8.play();
					}
				}

				if (BonusTime == true && BonusTimecount >= 10)
				{
					applego = false;
					BonusTime = false;
					sound8.stop();
					BT++;
				}

				//////////////////////////////////////  Cookie  ////////////////////////////////////////////
				if (CokieTime >= 50 && Cookie < 2)
				{
					if (rand() % 2 == 1)
					{
						Cookie++;
						getcookie = true;
						cookieMovement = true;
					}
					cock4.restart();
				}

				if (cookieMovement == true)
				{
					adck += 0.01;
					COK.move(0.75, sin(adck));
				}


				////////////////////////////////////////// Shushi ////////////////////////////////////////////
				if (hp <= 3500 && Healing == false)
				{
					Healing = true;
					Shushi = true;
					getsushi = true;

				}
				if (Shushi == true)
				{
					ads += 0.01;
					SUS.move(0.75, sin(ads));
				}
				if (SUS.getPosition().x > 2100 && Shushi == true)
				{
					Shushi = false;
					SUS.setPosition(-5000, 331);
				}

				///////////////////////////////////////////  Apple ////////////////////////////////////////////
				if (Sperfect >= 200 && Smiss <= 12 && hp >= 14500 && BT >= 1 && gap < 1)
				{
					Apple = true;
					getapple = true;

				}
				if (Apple == true)
				{
					ajed += 0.01;
					APP.move(1, sin(ajed));
				}
				if (APP.getPosition().x > 2100 && Apple == true)
				{
					Apple = false;
					APP.setPosition(-500, 331);
				}
				////////////////////////////////////////////////////////////////////////////////////////////
				for (int i = 1; i <= 4; i++)
				{
					if (cock.getElapsedTime() - redTime[i] > sf::seconds(0.5))
					{
						if (i == 1) {
							Arrow1.setFillColor(sf::Color::White);
						}
						else if (i == 2) {
							Arrow2.setFillColor(sf::Color::White);
						}
						else if (i == 3) {
							Arrow3.setFillColor(sf::Color::White);
						}
						else if (i == 4)
						{
							Arrow4.setFillColor(sf::Color::White);
						}
					}
				}
				cout << numstr << "\n";
				/////////////////////////////////////////////////////////////////////////////////////////////////////////
				float percent = (684 * hp) / 17500;      // from    (maxWidth * currentHp  ) / maxHp 
				BD.setSize({ percent,BD.getSize().y });
				////////////////////////////////////////////////////////////////////////////////////////

				while (window.pollEvent(event))
				{
					sf::Vector2f mouseCord; mouseCord.x = float(sf::Mouse::getPosition(window).x); mouseCord.y = float(sf::Mouse::getPosition(window).y);
					/////////////////////////////// BUTTON PRESSED //////////////////////////////////
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (Arrow1.getGlobalBounds().contains(mouseCord))
						{

							if ((a[0].N.getPosition().y >= 700 && a[0].N.getPosition().y <= 1000) || (b[0].N.getPosition().y >= 700 && b[0].N.getPosition().y <= 1000))
							{
								LastPressed[0] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow1.setPosition(268.0f, 880.0f);
								Arrow1.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow1\n";
								if (a[0].N.getGlobalBounds().intersects(Arrow1.getGlobalBounds()))
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[1].resetRect();
										_BOOM[1][2].resetRect();
										a[0].N.setPosition(238.f, -500.f);
										score += 7500;
										a[0].speed = rand() % 4 + 1.5;
										hp += 100; numhp = 100;
										Eff_PERFECT[1].setScale(1.f, 1.f);
										Eff_PERFECT[1].setPosition(328.f, 765.f); // start position +90 298
										effIDx[1] = 1;
									}
									else if (BonusTime == false)
									{
										if (a[0].N.getPosition().y >= 845 && a[0].N.getPosition().y <= 865 || a[0].N.getPosition().y >= 800 && a[0].N.getPosition().y < 845)
										{
											if (a[0].N.getPosition().y >= 845 && a[0].N.getPosition().y <= 865) //////////////  Perfect
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[1].resetRect();
												_BOOM[1][2].resetRect();
												a[0].N.setPosition(238.f, -500.f);
												score += 7500;
												a[0].speed = rand() % 4 + 1;
												hp += 100; //numhp = 100;
												Eff_PERFECT[1].setScale(1.f, 1.f);
												Eff_PERFECT[1].setPosition(328.f, 765.f); // start position +90 298
												effIDx[1] = 1;
											}
											if (a[0].N.getPosition().y >= 800 && a[0].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[1].resetRect();
												_BOOM[1][3].resetRect();
												a[0].N.setPosition(238.f, -500.f);
												score += 5000;
												a[0].speed = rand() % 3 + 1;
												hp += 50;
												Eff_COOL[1].setScale(1.f, 1.f);
												Eff_COOL[1].setPosition(328.f, 765.f); // start position
												effIDx[1] = 2;
											}
										}
										else    ////////////  Good  ////////////
										{
											Sgood++;
											_bubu[1].resetRect();
											_BOOM[1][4].resetRect();
											a[0].N.setPosition(238.f, -500.f);
											score += 1525;
											a[0].speed = rand() % 2 + 1;
											hp += 10;
											Eff_GOOD[1].setScale(1.f, 1.f);
											Eff_GOOD[1].setPosition(328.f, 765.f); // start position
											effIDx[1] = 3;
										}
									}

								}
								if (b[0].N.getGlobalBounds().intersects(Arrow1.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[1].resetRect();
											_BOOM[1][2].resetRect();
											b[0].N.setPosition(238.f, -500.f);  ///  <<<<<<<  ????? ?????? 1
											b[0].speed = rand() % 5 + 1;
											score += 2000;
											b[0].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[1].resetRect();
											_BOOM[1][1].resetRect();
											b[0].N.setPosition(238.f, -500.f);  ///  <<<<<<<  ????? ?????? 1
											b[0].speed = rand() % 5 + 1;
											score += 2000;
											b[0].N.setFillColor(sf::Color::Green);
										}
									}

								}
							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
						if (Arrow2.getGlobalBounds().contains(mouseCord))
						{
							if ((a[1].N.getPosition().y >= 700 && a[1].N.getPosition().y <= 1000) || (b[1].N.getPosition().y >= 700 && b[1].N.getPosition().y <= 1000)) // 634 - 694
							{
								LastPressed[1] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow2.setPosition(664.0f, 880.0f);
								Arrow2.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow2\n";
								if (a[1].N.getGlobalBounds().intersects(Arrow2.getGlobalBounds()))
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[2].resetRect();
										_BOOM[2][2].resetRect();
										a[1].N.setPosition(634.f, -500.f);
										score += 7500; hp += 100;
										a[1].speed = rand() % 4 + 1.5;
										Eff_PERFECT[2].setScale(1.f, 1.f);
										Eff_PERFECT[2].setPosition(724.f, 765.f); // start position +90 298
										effIDx[2] = 1;

									}
									else if (BonusTime == false)
									{
										if ((a[1].N.getPosition().y >= 845 && a[1].N.getPosition().y <= 865 || a[1].N.getPosition().y >= 800 && a[1].N.getPosition().y < 845))
										{
											if (a[1].N.getPosition().y >= 845 && a[1].N.getPosition().y <= 865) //////////////  Perfect  ////////////////
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[2].resetRect();
												_BOOM[2][2].resetRect();
												a[1].N.setPosition(634.f, -500.f);
												score += 7500; hp += 100;
												a[1].speed = rand() % 4 + 1;
												Eff_PERFECT[2].setScale(1.f, 1.f);
												Eff_PERFECT[2].setPosition(724.f, 765.f); // start position +90 298
												effIDx[2] = 1;
											}
											if (a[1].N.getPosition().y >= 800 && a[1].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[2].resetRect();
												_BOOM[2][3].resetRect();
												a[1].N.setPosition(634.f, -500.f);
												score += 5000; hp += 50;
												a[1].speed = rand() % 3 + 1;
												Eff_COOL[2].setScale(1.f, 1.f);
												Eff_COOL[2].setPosition(724.f, 765.f); // start position
												effIDx[2] = 2;
											}
										}
										else   ////////////  Good  ////////////   
										{
											Sgood++;
											_bubu[2].resetRect();
											_BOOM[2][4].resetRect();
											a[1].N.setPosition(634.f, -500.f);
											score += 1525; hp += 10;
											a[1].speed = rand() % 2 + 1;
											Eff_GOOD[2].setScale(1.f, 1.f);
											Eff_GOOD[2].setPosition(724.f, 765.f); // start position
											effIDx[2] = 3;
										}
									}
								}
								if (b[1].N.getGlobalBounds().intersects(Arrow2.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[2].resetRect();
											_BOOM[2][2].resetRect();
											b[1].N.setPosition(634.f, -100.f);  ///  <<<<<<<  ????? ?????? 2
											score += 2000;
											b[1].speed = rand() % 5 + 1;
											b[1].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[2].resetRect();
											_BOOM[2][1].resetRect();
											b[1].N.setPosition(634.f, -100.f);  ///  <<<<<<<  ????? ?????? 2
											score += 2000;
											b[1].speed = rand() % 5 + 1;
											b[1].N.setFillColor(sf::Color::Green);
										}
									}

								}
							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
						if (Arrow3.getGlobalBounds().contains(mouseCord))
						{
							if ((a[2].N.getPosition().y >= 700 && a[2].N.getPosition().y <= 1000) || (b[2].N.getPosition().y >= 700 && b[2].N.getPosition().y <= 1000)) //1030 - 1060
							{

								LastPressed[2] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow3.setPosition(1060.0f, 880.0f);
								Arrow3.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow3\n";

								if (a[2].N.getGlobalBounds().intersects(Arrow3.getGlobalBounds())) // 845 865   800 845
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[3].resetRect();
										_BOOM[3][2].resetRect();
										a[2].N.setPosition(1030.f, -500.f);
										score += 7500; hp += 100;
										a[2].speed = rand() % 4 + 1.5;
										Eff_PERFECT[3].setScale(1.f, 1.f);
										Eff_PERFECT[3].setPosition(1120.f, 765.f); // start position +90 298
										effIDx[3] = 1;

									}
									else if (BonusTime == false)
									{
										if (a[2].N.getPosition().y >= 845 && a[2].N.getPosition().y <= 865 || a[2].N.getPosition().y >= 800 && a[2].N.getPosition().y < 845)
										{
											if (a[2].N.getPosition().y >= 845 && a[2].N.getPosition().y <= 865) //////////////  Perfect  ////////////////
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[3].resetRect();
												_BOOM[3][2].resetRect();
												a[2].N.setPosition(1030.f, -500.f);
												score += 7500; hp += 100;
												a[2].speed = rand() % 4 + 1;
												Eff_PERFECT[3].setScale(1.f, 1.f);
												Eff_PERFECT[3].setPosition(1120.f, 765.f); // start position +90 298
												effIDx[3] = 1;
											}
											if (a[2].N.getPosition().y >= 800 && a[2].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[3].resetRect();
												_BOOM[3][3].resetRect();
												a[2].N.setPosition(1030.f, -500.f);
												score += 5000; hp += 50;
												a[2].speed = rand() % 3 + 1;
												Eff_COOL[3].setScale(1.f, 1.f);
												Eff_COOL[3].setPosition(1120.f, 765.f); // start position
												effIDx[3] = 2;
											}
										}
										else   ////////////  Good  ////////////   
										{
											Sgood++;
											_bubu[3].resetRect();
											_BOOM[3][4].resetRect();
											a[2].N.setPosition(1030.f, -500.f);
											score += 1525; hp += 10;
											a[2].speed = rand() % 2 + 1;
											Eff_GOOD[3].setScale(1.f, 1.f);
											Eff_GOOD[3].setPosition(1120.f, 765.f); // start position
											effIDx[3] = 3;
										}
									}
								}

								if (b[2].N.getGlobalBounds().intersects(Arrow3.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[3].resetRect();
											_BOOM[3][2].resetRect();
											b[2].N.setPosition(1030.f, -100.f);  ///  <<<<<<<  ????? ?????? 3
											score += 2000;
											b[2].speed = rand() % 5 + 1;
											b[2].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[3].resetRect();
											_BOOM[3][1].resetRect();
											b[2].N.setPosition(1030.f, -100.f);  ///  <<<<<<<  ????? ?????? 3
											score += 2000;
											b[2].speed = rand() % 5 + 1;
											b[2].N.setFillColor(sf::Color::Green);
										}
									}

								}
							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
						if (Arrow4.getGlobalBounds().contains(mouseCord))
						{
							if ((a[3].N.getPosition().y >= 700 && a[3].N.getPosition().y <= 1000) || (b[3].N.getPosition().y >= 700 && b[3].N.getPosition().y <= 1000)) //1426  - 1486
							{
								LastPressed[3] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow4.setPosition(1456.0f, 880.0f);
								Arrow4.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow4\n";

								if (a[3].N.getGlobalBounds().intersects(Arrow4.getGlobalBounds()))
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[4].resetRect();
										_BOOM[4][2].resetRect();
										a[3].N.setPosition(1426.f, -500.f);
										score += 7500; hp += 100;
										a[3].speed = rand() % 4 + 1.5;
										Eff_PERFECT[4].setScale(1.f, 1.f);
										Eff_PERFECT[4].setPosition(1516.f, 765.f); // start position +90 298
										effIDx[4] = 1;
									}
									else if (BonusTime == false)
									{
										if (a[3].N.getPosition().y >= 845 && a[3].N.getPosition().y <= 865 || a[3].N.getPosition().y >= 800 && a[3].N.getPosition().y < 845)
										{
											if (a[3].N.getPosition().y >= 845 && a[3].N.getPosition().y <= 865) //////////////  Perfect  ////////////////
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[4].resetRect();
												_BOOM[4][2].resetRect();
												a[3].N.setPosition(1426.f, -500.f);
												score += 7500; hp += 100;
												a[3].speed = rand() % 4 + 1;
												Eff_PERFECT[4].setScale(1.f, 1.f);
												Eff_PERFECT[4].setPosition(1516.f, 765.f); // start position +90 298
												effIDx[4] = 1;
											}
											if (a[3].N.getPosition().y >= 800 && a[3].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[4].resetRect();
												_BOOM[4][3].resetRect();
												a[3].N.setPosition(1426.f, -500.f);
												score += 5000; hp += 50;
												a[3].speed = rand() % 3 + 1;
												Eff_COOL[4].setScale(1.f, 1.f);
												Eff_COOL[4].setPosition(1516.f, 765.f); // start position
												effIDx[4] = 2;
											}
										}
										else   ////////////  Good  ////////////   
										{
											Sgood++;
											_bubu[4].resetRect();
											_BOOM[4][4].resetRect();
											a[3].N.setPosition(1426.f, -500.f);
											score += 1525; hp += 10;
											a[3].speed = rand() % 2 + 1;
											Eff_GOOD[4].setScale(1.f, 1.f);
											Eff_GOOD[4].setPosition(1516.f, 765.f); // start position
											effIDx[4] = 3;
										}
									}
								}
								if (b[3].N.getGlobalBounds().intersects(Arrow4.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[4].resetRect();
											_BOOM[4][2].resetRect();
											b[3].N.setPosition(1426.f, -100.f);  ///  <<<<<<<  ????? ?????? 4
											score += 2000;
											b[3].speed = rand() % 5 + 1;
											b[3].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[4].resetRect();
											_BOOM[4][1].resetRect();
											b[3].N.setPosition(1426.f, -100.f);  ///  <<<<<<<  ????? ?????? 4
											score += 2000;
											b[3].speed = rand() % 5 + 1;
											b[3].N.setFillColor(sf::Color::Green);
										}
									}

								}
							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
					}
					else
					{
						Arrow1.setPosition(238.0f, 865.0f);
						Arrow1.setScale(1.f, 1.f);

						Arrow2.setPosition(634.0f, 865.0f);
						Arrow2.setScale(1.f, 1.f);

						Arrow3.setPosition(1030.0f, 865.0f);
						Arrow3.setScale(1.f, 1.f);

						Arrow4.setPosition(1426.0f, 865.0f);
						Arrow4.setScale(1.f, 1.f);
					}
					////////////////////////////////////////////////    REC   ////////////////////////////////////////////
					if (event.type == sf::Event::EventType::KeyPressed)
					{
						if (event.key.code == sf::Keyboard::Numpad0)
						{
							recorder.start();
							cout << "RECORD\n";
						}
						if (event.key.code == sf::Keyboard::Numpad9)
						{
							cout << "REPLAY\n";
							recorder.stop();
							buffer = recorder.getBuffer();
							buffer.saveToFile("rec.ogg");
							sound.setBuffer(buffer);
							sound.play();
						}
						///////////////////////////////   UP   //////////////////////////////////////      // 238 634 1030 1426
						if (gv::worldClock.getElapsedTime() - LastPressed[0] > sf::seconds(0.125) && event.key.code == sf::Keyboard::Up)  // ?????? 0.1 ??
						{
							if (event.key.code == sf::Keyboard::Up && (a[0].N.getPosition().y >= 700 && a[0].N.getPosition().y <= 1000) || (b[0].N.getPosition().y >= 700 && b[0].N.getPosition().y <= 1000))
							{
								LastPressed[0] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow1.setPosition(268.0f, 880.0f);
								Arrow1.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow1\n";
								if (a[0].N.getGlobalBounds().intersects(Arrow1.getGlobalBounds()))
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[1].resetRect();
										_BOOM[1][2].resetRect();
										a[0].N.setPosition(238.f, -500.f);
										score += 7500;
										a[0].speed = rand() % 4 + 1.5;
										hp += 100; numhp = 100;
										Eff_PERFECT[1].setScale(1.f, 1.f);
										Eff_PERFECT[1].setPosition(328.f, 765.f); // start position +90 298
										effIDx[1] = 1;
									}
									else if (BonusTime == false)
									{
										if (a[0].N.getPosition().y >= 845 && a[0].N.getPosition().y <= 865 || a[0].N.getPosition().y >= 800 && a[0].N.getPosition().y < 845)
										{
											if (a[0].N.getPosition().y >= 845 && a[0].N.getPosition().y <= 865) //////////////  Perfect
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[1].resetRect();
												_BOOM[1][2].resetRect();
												a[0].N.setPosition(238.f, -500.f);
												score += 7500;
												a[0].speed = rand() % 4 + 1;
												hp += 100; //numhp = 100;
												Eff_PERFECT[1].setScale(1.f, 1.f);
												Eff_PERFECT[1].setPosition(328.f, 765.f); // start position +90 298
												effIDx[1] = 1;
											}
											if (a[0].N.getPosition().y >= 800 && a[0].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[1].resetRect();
												_BOOM[1][3].resetRect();
												a[0].N.setPosition(238.f, -500.f);
												score += 5000;
												a[0].speed = rand() % 3 + 1.5;
												hp += 50;
												Eff_COOL[1].setScale(1.f, 1.f);
												Eff_COOL[1].setPosition(328.f, 765.f); // start position
												effIDx[1] = 2;
											}
										}
										else    ////////////  Good  ////////////
										{
											Sgood++;
											_bubu[1].resetRect();
											_BOOM[1][4].resetRect();
											a[0].N.setPosition(238.f, -500.f);
											score += 1525;
											a[0].speed = rand() % 3 + 1;
											hp += 10;
											Eff_GOOD[1].setScale(1.f, 1.f);
											Eff_GOOD[1].setPosition(328.f, 765.f); // start position
											effIDx[1] = 3;
										}
									}

								}
								if (b[0].N.getGlobalBounds().intersects(Arrow1.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[1].resetRect();
											_BOOM[1][2].resetRect();
											b[0].N.setPosition(238.f, -500.f);  ///  <<<<<<<  ????? ?????? 1
											b[0].speed = rand() % 5 + 1;
											score += 2000;
											b[0].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[1].resetRect();
											_BOOM[1][1].resetRect();
											b[0].N.setPosition(238.f, -500.f);  ///  <<<<<<<  ????? ?????? 1
											b[0].speed = rand() % 5 + 1;
											score += 2000;
											b[0].N.setFillColor(sf::Color::Green);
										}
									}

								}
							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
						///////////////////////////////   DOWN  ////////////////////////////////////////
						if (gv::worldClock.getElapsedTime() - LastPressed[1] > sf::seconds(0.125) && event.key.code == sf::Keyboard::Down)
						{
							if (event.key.code == sf::Keyboard::Down && (a[1].N.getPosition().y >= 700 && a[1].N.getPosition().y <= 1000) || (b[1].N.getPosition().y >= 700 && b[1].N.getPosition().y <= 1000)) // 634 - 694
							{
								LastPressed[1] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow2.setPosition(664.0f, 880.0f);
								Arrow2.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow2\n";
								if (a[1].N.getGlobalBounds().intersects(Arrow2.getGlobalBounds()))
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[2].resetRect();
										_BOOM[2][2].resetRect();
										a[1].N.setPosition(634.f, -500.f);
										score += 7500; hp += 100;
										a[1].speed = rand() % 4 + 1.5;
										Eff_PERFECT[2].setScale(1.f, 1.f);
										Eff_PERFECT[2].setPosition(724.f, 765.f); // start position +90 298
										effIDx[2] = 1;

									}
									else if (BonusTime == false)
									{
										if ((a[1].N.getPosition().y >= 845 && a[1].N.getPosition().y <= 865 || a[1].N.getPosition().y >= 800 && a[1].N.getPosition().y < 845))
										{
											if (a[1].N.getPosition().y >= 845 && a[1].N.getPosition().y <= 865) //////////////  Perfect  ////////////////
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[2].resetRect();
												_BOOM[2][2].resetRect();
												a[1].N.setPosition(634.f, -500.f);
												score += 7500; hp += 100;
												a[1].speed = rand() % 4 + 1;
												Eff_PERFECT[2].setScale(1.f, 1.f);
												Eff_PERFECT[2].setPosition(724.f, 765.f); // start position +90 298
												effIDx[2] = 1;
											}
											if (a[1].N.getPosition().y >= 800 && a[1].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[2].resetRect();
												_BOOM[2][3].resetRect();
												a[1].N.setPosition(634.f, -500.f);
												score += 5000; hp += 50;
												a[1].speed = rand() % 3 + 1.5;
												Eff_COOL[2].setScale(1.f, 1.f);
												Eff_COOL[2].setPosition(724.f, 765.f); // start position
												effIDx[2] = 2;
											}
										}
										else   ////////////  Good  ////////////   
										{
											Sgood++;
											_bubu[2].resetRect();
											_BOOM[2][4].resetRect();
											a[1].N.setPosition(634.f, -500.f);
											score += 1525; hp += 10;
											a[1].speed = rand() % 3 + 1;
											Eff_GOOD[2].setScale(1.f, 1.f);
											Eff_GOOD[2].setPosition(724.f, 765.f); // start position
											effIDx[2] = 3;
										}
									}
								}
								if (b[1].N.getGlobalBounds().intersects(Arrow2.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[2].resetRect();
											_BOOM[2][2].resetRect();
											b[1].N.setPosition(634.f, -100.f);  ///  <<<<<<<  ????? ?????? 2
											score += 2000;
											b[1].speed = rand() % 5 + 1;
											b[1].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[2].resetRect();
											_BOOM[2][1].resetRect();
											b[1].N.setPosition(634.f, -100.f);  ///  <<<<<<<  ????? ?????? 2
											score += 2000;
											b[1].speed = rand() % 5 + 1;
											b[1].N.setFillColor(sf::Color::Green);
										}
									}

								}
							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
						///////////////////////////////   LEFT   ////////////////////////////////////////
						if (gv::worldClock.getElapsedTime() - LastPressed[2] > sf::seconds(0.125) && event.key.code == sf::Keyboard::Left)
						{
							if (event.key.code == sf::Keyboard::Left && (a[2].N.getPosition().y >= 700 && a[2].N.getPosition().y <= 1000) || (b[2].N.getPosition().y >= 700 && b[2].N.getPosition().y <= 1000)) //1030 - 1060
							{

								LastPressed[2] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow3.setPosition(1060.0f, 880.0f);
								Arrow3.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow3\n";

								if (a[2].N.getGlobalBounds().intersects(Arrow3.getGlobalBounds())) // 845 865   800 845
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[3].resetRect();
										_BOOM[3][2].resetRect();
										a[2].N.setPosition(1030.f, -500.f);
										score += 7500; hp += 100;
										a[2].speed = rand() % 4 + 1.5;
										Eff_PERFECT[3].setScale(1.f, 1.f);
										Eff_PERFECT[3].setPosition(1120.f, 765.f); // start position +90 298
										effIDx[3] = 1;

									}
									else if (BonusTime == false)
									{
										if (a[2].N.getPosition().y >= 845 && a[2].N.getPosition().y <= 865 || a[2].N.getPosition().y >= 800 && a[2].N.getPosition().y < 845)
										{
											if (a[2].N.getPosition().y >= 845 && a[2].N.getPosition().y <= 865) //////////////  Perfect  ////////////////
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[3].resetRect();
												_BOOM[3][2].resetRect();
												a[2].N.setPosition(1030.f, -500.f);
												score += 7500; hp += 100;
												a[2].speed = rand() % 4 + 1;
												Eff_PERFECT[3].setScale(1.f, 1.f);
												Eff_PERFECT[3].setPosition(1120.f, 765.f); // start position +90 298
												effIDx[3] = 1;
											}
											if (a[2].N.getPosition().y >= 800 && a[2].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[3].resetRect();
												_BOOM[3][3].resetRect();
												a[2].N.setPosition(1030.f, -500.f);
												score += 5000; hp += 50;
												a[2].speed = rand() % 3 + 1.5;
												Eff_COOL[3].setScale(1.f, 1.f);
												Eff_COOL[3].setPosition(1120.f, 765.f); // start position
												effIDx[3] = 2;
											}
										}
										else   ////////////  Good  ////////////   
										{
											Sgood++;
											_bubu[3].resetRect();
											_BOOM[3][4].resetRect();
											a[2].N.setPosition(1030.f, -500.f);
											score += 1525; hp += 10;
											a[2].speed = rand() % 3 + 1;
											Eff_GOOD[3].setScale(1.f, 1.f);
											Eff_GOOD[3].setPosition(1120.f, 765.f); // start position
											effIDx[3] = 3;
										}
									}
								}

								if (b[2].N.getGlobalBounds().intersects(Arrow3.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[3].resetRect();
											_BOOM[3][2].resetRect();
											b[2].N.setPosition(1030.f, -100.f);  ///  <<<<<<<  ????? ?????? 3
											score += 2000;
											b[2].speed = rand() % 5 + 1;
											b[2].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[3].resetRect();
											_BOOM[3][1].resetRect();
											b[2].N.setPosition(1030.f, -100.f);  ///  <<<<<<<  ????? ?????? 3
											score += 2000;
											b[2].speed = rand() % 5 + 1;
											b[2].N.setFillColor(sf::Color::Green);
										}
									}

								}
							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
						///////////////////////////////   RIGHT  ////////////////////////////////////////
						if (gv::worldClock.getElapsedTime() - LastPressed[3] > sf::seconds(0.125) && event.key.code == sf::Keyboard::Right)
						{
							if (event.key.code == sf::Keyboard::Right && (a[3].N.getPosition().y >= 700 && a[3].N.getPosition().y <= 1000) || (b[3].N.getPosition().y >= 700 && b[3].N.getPosition().y <= 1000)) //1426  - 1486
							{
								LastPressed[3] = gv::worldClock.getElapsedTime();
								sound3.play();
								Arrow4.setPosition(1456.0f, 880.0f);
								Arrow4.setScale(0.8f, 0.8f);
								system("cls");
								cout << "Arrow4\n";

								if (a[3].N.getGlobalBounds().intersects(Arrow4.getGlobalBounds()))
								{
									if (BonusTime == true)
									{
										Sperfect++;
										_bubu[4].resetRect();
										_BOOM[4][2].resetRect();
										a[3].N.setPosition(1426.f, -500.f);
										score += 7500; hp += 100;
										a[3].speed = rand() % 4 + 1.5;
										Eff_PERFECT[4].setScale(1.f, 1.f);
										Eff_PERFECT[4].setPosition(1516.f, 765.f); // start position +90 298
										effIDx[4] = 1;
									}
									else if (BonusTime == false)
									{
										if (a[3].N.getPosition().y >= 845 && a[3].N.getPosition().y <= 865 || a[3].N.getPosition().y >= 800 && a[3].N.getPosition().y < 845)
										{
											if (a[3].N.getPosition().y >= 845 && a[3].N.getPosition().y <= 865) //////////////  Perfect  ////////////////
											{
												Sperfect++;
												Catperfect += 1;
												_bubu[4].resetRect();
												_BOOM[4][2].resetRect();
												a[3].N.setPosition(1426.f, -500.f);
												score += 7500; hp += 100;
												a[3].speed = rand() % 4 + 1;
												Eff_PERFECT[4].setScale(1.f, 1.f);
												Eff_PERFECT[4].setPosition(1516.f, 765.f); // start position +90 298
												effIDx[4] = 1;
											}
											if (a[3].N.getPosition().y >= 800 && a[3].N.getPosition().y < 845)  ///////////  Cool   ///////////
											{
												Scool++;
												_bubu[4].resetRect();
												_BOOM[4][3].resetRect();
												a[3].N.setPosition(1426.f, -500.f);
												score += 5000; hp += 50;
												a[3].speed = rand() % 3 + 1.5;
												Eff_COOL[4].setScale(1.f, 1.f);
												Eff_COOL[4].setPosition(1516.f, 765.f); // start position
												effIDx[4] = 2;
											}
										}
										else   ////////////  Good  ////////////   
										{
											Sgood++;
											_bubu[4].resetRect();
											_BOOM[4][4].resetRect();
											a[3].N.setPosition(1426.f, -500.f);
											score += 1525; hp += 10;
											a[3].speed = rand() % 3 + 1;
											Eff_GOOD[4].setScale(1.f, 1.f);
											Eff_GOOD[4].setPosition(1516.f, 765.f); // start position
											effIDx[4] = 3;
										}
									}
								}
								if (b[3].N.getGlobalBounds().intersects(Arrow4.getGlobalBounds()))
								{
									if (BonusTime == true && numstr >= 10 || BonusTime == true && applego == true)
									{
										if (BonusTime == true && numstr >= 10)
										{
											Sperfect++;
											_bubu[4].resetRect();
											_BOOM[4][2].resetRect();
											b[3].N.setPosition(1426.f, -100.f);  ///  <<<<<<<  ????? ?????? 4
											score += 2000;
											b[3].speed = rand() % 5 + 1;
											b[3].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
										}
										if (BonusTime == true && applego == true)
										{
											Sperfect++;
											_bubu[4].resetRect();
											_BOOM[4][1].resetRect();
											b[3].N.setPosition(1426.f, -100.f);  ///  <<<<<<<  ????? ?????? 4
											score += 2000;
											b[3].speed = rand() % 5 + 1;
											b[3].N.setFillColor(sf::Color::Green);
										}
									}

								}

							}
							else
							{
								score -= 725; hp -= 10;
							}
						}
						////////////////////////////////////           Specail           //////////////////////////////// 
						if (event.key.code == sf::Keyboard::P)
						{
							Smiss = 2;
							score += 12534;
							hp += max;
							Sperfect += 157;
							Sgood += 65;
							Scool += 32;
							hpsp == false;
						}
						if (event.key.code == sf::Keyboard::Space)
						{
							CAT.setScale(1.2f, 1.2f);

							sound6.play(); sound6.setVolume(100);
							cout << "  Maow  \n";

							if (Catperfect >= 3 && BonusTime == false && BG3.getGlobalBounds().contains(mouseCord)) //MAX 4
							{
								STAR = true;
								BonusTime = true;
								numstr += 2;
								sound7.play();
								cock3.restart();
								CAT.setPosition(-500, 331);
								BG3.setFillColor(sf::Color::White);
							}

						}
						if (event.key.code == sf::Keyboard::X || SUS.getGlobalBounds().contains(mouseCord) || COK.getGlobalBounds().contains(mouseCord) || APP.getGlobalBounds().contains(mouseCord))
						{
							if (getsushi == true && SUS.getPosition().x >= 0 && SUS.getPosition().x <= 1900)
							{
								eff2.play();
								sound11.play();
								hp += 3000;
								Shushi = false;
								SUS.setPosition(-5000, 331);
							}
							if (getcookie == true && COK.getPosition().x >= 0 && COK.getPosition().x <= 1900)
							{
								sound11.play();
								score += 10000;
								cookieMovement = false;
								if (Cookie <= 2)
								{
									COK.setPosition(-500, 330);
								}
								else
								{
									COK.setPosition(-5000, 330);
								}

							}
							if (getapple == true && APP.getPosition().x >= 0 && APP.getPosition().x <= 1900)
							{
								gap++;
								Apple = false;
								getapple = false;
								applego = true;
								Smiss = 0; hp = max; Cookie = 0; BonusTime = true; cock3.restart(); hpsp = false;
								sound8.stop(); eff3.play(); sound11.play();
								CAT.setPosition(-500, 331); APP.setPosition(-500, 331);
							}
						}
						if (event.key.code == sf::Keyboard::Escape)
						{
							window.close();
							return 0;
							cout << "ESC\n";
						}


						if (event.key.code == sf::Keyboard::H)
						{
							bool pause = true, isExit = 0, wet = 0;
							sf::Texture PAUSE, bgpause, menu1, menu2, menu3;

							menu1.loadFromFile("B_play.png");
							sf::RectangleShape gomenu1(sf::Vector2f(500.f, 120.f));
							gomenu1.setPosition(365.f, 600.f); gomenu1.setTexture(&menu1); gomenu1.setOrigin(500.f / 2, 120.f / 2);

							menu2.loadFromFile("menu.png");
							sf::RectangleShape gomenu2(sf::Vector2f(396.255f, 128.681f));
							gomenu2.setPosition(962.426f, 1200.f); gomenu2.setTexture(&menu2); gomenu2.setOrigin(396.255f / 2, 128.681f / 2);

							menu3.loadFromFile("B_exit.png");
							sf::RectangleShape gomenu3(sf::Vector2f(500.f, 120.f));
							gomenu3.setPosition(1567.f, 600.f); gomenu3.setTexture(&menu3); gomenu3.setOrigin(500.f / 2, 120.f / 2);

							PAUSE.loadFromFile("pause.png");
							sf::RectangleShape PS(sf::Vector2f(76.f, 72.f));
							PS.setPosition(1844, 0); PS.setTexture(&PAUSE);

							bgpause.loadFromFile("bgps.png");
							sf::RectangleShape bgps(sf::Vector2f(1920.f, 1080.f)); bgps.setFillColor(sf::Color(255, 255, 255, oppa += 3));
							bgps.setPosition(0, 0); bgps.setTexture(&bgpause);

							while (pause == true)
							{
								sf::Event ev;
								while (window.pollEvent(ev) && PLAY == true)
								{
									sf::Vector2f mouseCord; mouseCord.x = float(sf::Mouse::getPosition(window).x); mouseCord.y = float(sf::Mouse::getPosition(window).y);

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (gomenu1.getGlobalBounds().contains(mouseCord))  /// continute
										{
											sound3.play();
											gomenu1.setPosition(365.f, 600.f);
											gomenu1.setScale(0.8f, 0.8f);
											Ap.pause();
											pause = false;
											isExit = true;
											if (pause == false)
											{
												A1.pause();
												wet = 1;
												system("cls");
												std::cout << "Backtogame\n";

											}
											if (wet == 1)
											{
												sf::sleep(sf::seconds(3));

												A1.play();
											}
										}
										if (gomenu2.getGlobalBounds().contains(mouseCord)) // go to  menu
										{
											Ap.stop();
											sound3.play();
											gomenu2.setPosition(962.426f, 600.f);
											gomenu2.setScale(0.8f, 0.8f);
											MENU = true;
											PLAY = false;
											isExit = true;

											//std::cout << "gotomenu\n";
										}
										if (gomenu3.getGlobalBounds().contains(mouseCord))
										{
											sound3.play();
											gomenu3.setPosition(1567.f, 600.f);
											gomenu3.setScale(0.8f, 0.8f);
											window.close();
											return 0;
											std::cout << "Arrow3\n";
										}

									}
									else
									{
										gomenu1.setPosition(365.f, 600.f);
										gomenu1.setScale(1.f, 1.f);

										gomenu2.setPosition(962.426f, 154.043f);
										gomenu2.setScale(1.f, 1.f);

										gomenu3.setPosition(1567.f, 600.f);
										gomenu3.setScale(1.f, 1.f);
									}

									if (ev.key.code == sf::Keyboard::G)
									{

									}
									if (ev.key.code == sf::Keyboard::X) /// unpause
									{
										numstr = 10;
									}
								}
								if (isExit == true)
								{

									break;
								}
								Ap.play();
								A1.pause();
								Ap.update();
								window.clear();
								window.draw(Ap);
								window.setMouseCursorVisible(true);
								window.draw(bgps);
								window.draw(PS);
								window.draw(gomenu1);
								window.draw(gomenu2);
								window.draw(gomenu3);
								window.display();
								cout << pause << "\n";
							}



						}

					}

					if (event.type == sf::Event::EventType::KeyReleased)
					{
						if (event.key.code == sf::Keyboard::Up)
						{
							Arrow1.setPosition(238.0f, 865.0f);
							Arrow1.setScale(1.f, 1.f);

						}
						if (event.key.code == sf::Keyboard::Down)
						{
							Arrow2.setPosition(634.0f, 865.0f);
							Arrow2.setScale(1.f, 1.f);

						}
						if (event.key.code == sf::Keyboard::Left)
						{
							Arrow3.setPosition(1030.0f, 865.0f);
							Arrow3.setScale(1.f, 1.f);
						}
						if (event.key.code == sf::Keyboard::Right)
						{
							Arrow4.setPosition(1426.0f, 865.0f);
							Arrow4.setScale(1.f, 1.f);
						}
						if (event.key.code == sf::Keyboard::Space)
						{
							CAT.setScale(1.f, 1.f);
						}
					}
				}

				for (int i = 1; i < 5; i++) {
					switch (effIDx[i]) {
					case -1:
						break;
					case 1:
						Float(Eff_PERFECT[i], i);
						break;
					case 2:
						Float(Eff_COOL[i], i);
						break;
					case 3:
						Float(Eff_GOOD[i], i);
						break;
					case 4:
						Float(Eff_MISS[i], i);
						break;
					}
				}

				//////////////////////////////////////////                    FAIL                       /////////////////////////////////////////////

				/////////////////////////////////////////

				if (a[0].N.getPosition().y < 955)
				{
					a[0].N.move(0, a[0].speed);

				}
				else
				{
					if (BonusTime == false)
					{
						Arrow1.setFillColor(Color::Red);
						redTime[1] = cock.getElapsedTime();
						sound4.play();
						score -= 1000;  hp -= numhp;
						numhp += 750;
						Eff_MISS[1].setScale(1.f, 1.f);
						Eff_MISS[1].setPosition(328.f, 765.f); // start position +90
						effIDx[1] = 4;
						Smiss++;
					}

					a[0].speed = rand() % 3 + 1;;
					a[0].N.setPosition(238.f, -500.f);
				}

				if (b[0].N.getPosition().y < 955)
				{

					b[0].N.move(0, b[0].speed);


				}
				else
				{
					if (BonusTime == false)
					{

						redTime[1] = cock.getElapsedTime();
					}
					b[0].speed = rand() % 2 + 1;
					b[0].N.setPosition(238.f, -1000.f);
					b[0].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
				}
				/////////////////////////////////////////////////////////////////////////////////////////

				if (a[1].N.getPosition().y < 955)
				{
					a[1].N.move(0, a[1].speed);
				}
				else
				{
					if (BonusTime == false)
					{
						Arrow2.setFillColor(Color::Red);
						redTime[2] = cock.getElapsedTime();
						sound4.play();
						score -= 1000;  hp -= 750;

						Eff_MISS[2].setScale(1.f, 1.f);
						Eff_MISS[2].setPosition(724.f, 765.f); // start position
						effIDx[2] = 4;
						Smiss++;
					}

					a[1].speed = rand() % 3 + 1;;
					a[1].N.setPosition({ 634,-500 });
				}
				if (b[1].N.getPosition().y < 955)
				{
					b[1].N.move(0, b[1].speed);
				}
				else
				{
					if (BonusTime == false)
					{

						redTime[2] = cock.getElapsedTime();



					}

					b[1].speed = rand() % 2 + 1;;
					b[1].N.setPosition(634.f, -1000.f);
					b[1].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
				}
				////////////////////////////////////////////////----------------------------------------------/////////////////////////////////////////////////////////////
				if (a[2].N.getPosition().y < 955)
				{
					a[2].N.move(0, a[2].speed);
				}
				else
				{
					if (BonusTime == false)
					{
						Arrow3.setFillColor(Color::Red);
						redTime[3] = cock.getElapsedTime();
						sound4.play();
						score -= 1000;  hp -= 750;

						Eff_MISS[3].setScale(1.f, 1.f);
						Eff_MISS[3].setPosition(1120.f, 765.f); // start position
						effIDx[3] = 4;
						Smiss++;
					}

					a[2].speed = rand() % 3 + 1;;
					a[2].N.setPosition({ 1030,-500 });
				}
				if (b[2].N.getPosition().y < 955)
				{
					b[2].N.move(0, b[2].speed);
				}
				else
				{
					if (BonusTime == false)
					{

						redTime[3] = cock.getElapsedTime();

					}

					b[2].speed = rand() % 2 + 1;;
					b[2].N.setPosition(1030.f, -1000.f);
					b[2].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
				}
				////////////////////////////////////////////-------------------------------------------------------/////////////////////////////////////////////
				if (a[3].N.getPosition().y < 955)
				{
					a[3].N.move(0, a[3].speed);
				}
				else
				{
					if (BonusTime == false)
					{
						Arrow4.setFillColor(Color::Red);
						redTime[4] = cock.getElapsedTime();
						sound4.play();
						score -= 1000;  hp -= 750;

						Eff_MISS[4].setScale(1.f, 1.f);
						Eff_MISS[4].setPosition(1516.f, 765.f); // start position
						effIDx[4] = 4;
						Smiss++;
					}

					a[3].speed = rand() % 3 + 1;;
					a[3].N.setPosition({ 1426, -500 });
				}
				if (b[3].N.getPosition().y < 955)
				{
					b[3].N.move(0, b[3].speed);
				}
				else
				{
					if (BonusTime == false)
					{

						redTime[4] = cock.getElapsedTime();

					}
					b[3].speed = rand() % 2 + 1;;
					b[3].N.setPosition(1426.f, -1000.f);
					b[3].N.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
				}
				sf::Time bonustime = cockBN.getElapsedTime();
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (BONUSTIME == true)
				{
					int TimeBou = bonustime.asSeconds();
					int a = -500;
					if (TimeBou - BonusBegin >= 10)
					{
						BONUSTIME = false;
						numstr = 0;
					}

				}
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (hpsp == true)
				{
					hp -= 0.0000175;
					if (hp <= 1000)
					{
						hpsp = false;
					}
					for (int j = 1; j < 5; j++)
					{
						a[j].speed += 0.000000000000175;
					}
				}

				if (hp <= 0)
				{
					A1.pause();
					sound9.play();

					LLOSE = true;
					cout << LLOSE << "\n";
				}

				if (A1.getStatus() == sfe::Stopped)
				{
					sound8.play();
					hsc(score1, input);
					WWIN = true;
				}

				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				A1.update();
				window.clear();
				window.draw(A1);
				std::stringstream ssPerfect, point, SCore;
				ssPerfect << "P: " << Sperfect << "  C: " << Scool << "  G: " << Sgood << "  M: " << Smiss;
				point << "PERFECT : " << Sperfect << "  COOL : " << Scool << "  GOOD : " << Sgood << "  MISS : " << Smiss;
				SCore << "SCORE : " << score;
				S.setString(SCore.str());
				P.setString(ssPerfect.str());
				p.setString(point.str());

				////////////////////////////////////////////////////////////////////////////////
				////////////////////////////////////////////////////////////////////////////////

				window.draw(BG3);

				window.setMouseCursor(cursor);
				window.setMouseCursorVisible(false);


				for (int i = 1; i <= 4; i++)
				{
					for (int j = 1; j <= 4; j++)
					{
						_BOOM[i][j].setRect();
						if (_BOOM[i][j].animation.nowW != -1)
							window.draw(_BOOM[i][j].body);
					}
					_bubu[i].setRect();
					_bubu[i].animation.nowW != -1;
					window.draw(_bubu[i].body);
				}

				window.draw(Arrow1);
				window.draw(Arrow2);
				window.draw(Arrow3);
				window.draw(Arrow4);


				if (BONUSTIME == true || applego == true)
				{
					window.draw(b[0].N);
					window.draw(b[1].N);
					window.draw(b[2].N);
					window.draw(b[3].N);
				}

				window.draw(a[0].N);
				window.draw(a[1].N);
				window.draw(a[2].N);
				window.draw(a[3].N);

				window.draw(ST);
				window.draw(BD);
				window.draw(HAT);
				window.draw(HAT1);
				window.draw(APP);
				window.draw(CAT);
				window.draw(SUS);
				window.draw(COK);

				if (mouse == true)
				{
					window.setMouseCursorVisible(true);
				}
				else
				{
					sf::Mouse::setPosition(sf::Vector2i(500, 1200));
				}

				if (STAR == true)
				{
					if (numstr == 2)
					{
						window.draw(star);
					}
					if (numstr == 4)
					{

						window.draw(star);
						window.draw(star1);
					}
					if (numstr == 6)
					{

						window.draw(star);
						window.draw(star1);
						window.draw(star2);
					}
					if (numstr == 8)
					{
						window.draw(star);
						window.draw(star1);
						window.draw(star2);
						window.draw(star3);
					}
					if (numstr == 10)
					{
						hpsp = true;
						numstr = 11;
						BonusBegin = bonustime.asSeconds();
					}
					if (numstr == 11)
					{
						BONUSTIME = true;
						window.draw(star);
						window.draw(star1);
						window.draw(star2);
						window.draw(star3);
						window.draw(star4);
					}
					if (numstr > 11)
					{
						numstr = 0;
					}

				}
				if (hp >= 17500)
				{
					hp = max;
				}
				if (hp <= 5000)
				{
					HAT1.setSize({ 0,0 });
					BG3.setFillColor(sf::Color::Red);
				}
				else
				{
					HAT1.setSize({ 105.f, 87.f });
					BG3.setFillColor(sf::Color::Black);
				}
				if (BonusTime == true)
				{
					if (BonusTime == true)
					{
						BG3.setFillColor(sf::Color::White);
					}
					if (applego == true)
					{
						BG3.setFillColor(sf::Color::Green);
					}
				}
				if (Catperfect == 3)
				{
					BG3.setFillColor(sf::Color::Cyan);
				}


				for (int i = 0; i < 5; i++)
				{
					window.draw(Eff_PERFECT[i]);
					window.draw(Eff_COOL[i]);
					window.draw(Eff_GOOD[i]);
					window.draw(Eff_MISS[i]);
				}

				window.draw(S);
				window.draw(P);

				while (LLOSE == true || WWIN == true)
				{
					sf::Texture l;
					l.loadFromFile("S.Lose.png");
					sf::RectangleShape LOSE(sf::Vector2f(1920, 1080));
					LOSE.setPosition(0, 0); LOSE.setTexture(&l);
					sf::Texture W;
					W.loadFromFile("S.Win.png");
					sf::RectangleShape WIN(sf::Vector2f(1920, 1080));
					WIN.setPosition(0, 0); WIN.setTexture(&W);
					sf::Texture BGLW;
					BGLW.loadFromFile("akb.jpg");
					sf::RectangleShape wl(sf::Vector2f(1920, 1080));
					wl.setPosition(0, 0); wl.setTexture(&BGLW);

					sf::Texture g1, g2, g3, g4, g5;
					g1.loadFromFile("fA (1).png");
					sf::RectangleShape A(sf::Vector2f(253.f, 353.f));
					A.setPosition(965, 835); A.setTexture(&g1); A.setOrigin(253 / 2.f, 353 / 2.f); A.setFillColor(sf::Color(255, 128, 0, 255));
					g2.loadFromFile("fA (2).png");
					sf::RectangleShape B(sf::Vector2f(253.f, 353.f));
					B.setPosition(965, 835); B.setTexture(&g2); B.setOrigin(253 / 2.f, 353 / 2.f); B.setFillColor(sf::Color(255, 128, 0, 255));
					g3.loadFromFile("fA (3).png");
					sf::RectangleShape C(sf::Vector2f(253.f, 353.f));
					C.setPosition(965, 835); C.setTexture(&g3); C.setOrigin(253 / 2.f, 353 / 2.f); C.setFillColor(sf::Color(255, 128, 0, 255));
					g4.loadFromFile("fA (4).png");
					sf::RectangleShape F(sf::Vector2f(253.f, 353.f));
					F.setPosition(965, 835); F.setTexture(&g4); F.setOrigin(253 / 2.f, 353 / 2.f); F.setFillColor(sf::Color(255, 128, 0, 255));
					g5.loadFromFile("fA (5).png");
					sf::RectangleShape SS(sf::Vector2f(253.f, 353.f));
					SS.setPosition(965, 835); SS.setTexture(&g5); SS.setOrigin(253 / 2.f, 353 / 2.f); SS.setFillColor(sf::Color(255, 128, 0, 255));

					sum = (Smiss * -2.75) / 5 + ((Sperfect * 25) / 275 + (Scool * 15) / 175 + (Sgood * 10) / 50 + (score / 200000) * 5);

					if (LLOSE == true)
					{
						window.draw(wl);
						window.draw(LOSE);
						window.draw(F);
						system("cls");
						printf("This is your score : %d\n", sum);
						window.draw(p);  // score
						window.display();

					}
					if (WWIN == true)
					{
						score1 = score;
						window.draw(wl);
						window.draw(WIN);

						if (sum < 70) { window.draw(F); }
						if (sum >= 70 && sum < 85) { window.draw(C); }
						if (sum >= 85 && sum < 100) { window.draw(B); }
						if (sum >= 100 && sum < 130) { window.draw(A); }
						if (sum >= 130) { window.draw(SS); }
						system("cls");
						printf("This is your score : %d\n", sum);
						window.draw(p);  // score
						window.display();
					}

					sf::Event LW;
					while (window.pollEvent(LW))
					{
						sf::Vector2f mouseCord;
						mouseCord.x = float(sf::Mouse::getPosition(window).x);
						mouseCord.y = float(sf::Mouse::getPosition(window).y);
						if (LW.key.code == sf::Keyboard::Enter || SS.getGlobalBounds().contains(mouseCord) || A.getGlobalBounds().contains(mouseCord) || B.getGlobalBounds().contains(mouseCord) || C.getGlobalBounds().contains(mouseCord) || F.getGlobalBounds().contains(mouseCord))
						{
							MENU = true;
							PLAY = false;
							LLOSE = false;
							WWIN = false;
						}
					}
				}
				window.display();

			}
			for (int i = 1; i <= 4; i++)
			{
				a[i].speed += 0.000000001725;
			}
		}

	}

	return 0;
}