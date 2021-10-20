//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include "FFT.h"
//
//using namespace std;
//using namespace sf;
//
//int mainoskc()
//{
//	RenderWindow window(VideoMode(900, 900,32), "Window");
//	string path;
//	cout << "Put an audio file in the Ressources folder (.wav will work, mp3 wont)" << endl;
//	/*cout << "Enter the file name (example.wav) : ";*/
//	/*cin >> path;
//	*/
//
//    //FFT fft("Ressources/" + path + "Sukinanda.wav", 16384);
//	//FFT fft("Ressources/" + path + "ja-ba-ja.wav", 16384);
//	FFT fft ("Ressources/" + path + "Natsuirono Mule.wav", 16384);
//	
//	Event event;
//	
//	while (window.isOpen())
//	{
//		while (window.pollEvent(event)) {}
//
//		fft.update();
//		window.clear();
//		fft.draw(window);
//		window.display();
//		
//	}
//
//	return 0;
//}