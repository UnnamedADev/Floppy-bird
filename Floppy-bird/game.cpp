#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <string>

#include "object.h"

int main() {
	//SRAND
	srand(time(NULL));

	//Window informations
	int windowX = 800;
	int windowY = 600;

	//Settings
	sf::ContextSettings mySettings;
	mySettings.antialiasingLevel = 8;

	sf::RenderWindow myWindow(sf::VideoMode(windowX, windowY), "Floppy bird", sf::Style::Default, mySettings);
	myWindow.setFramerateLimit(60);

	//Background
	sf::Texture bcktexture;
	bcktexture.loadFromFile("background.png");
	sf::Sprite myBackground;
	myBackground.setTexture(bcktexture);
	myBackground.setPosition(0, 0);
	myBackground.setScale(1, 1);


	//Object vector
	std::vector <eObject> vObject;
	vObject.push_back(eObject(rand() % 100 + 31, rand() % 100 + 31));
	
	//Player ball
	playerObject * player = new playerObject;

	sf::Texture birdtexture;
	birdtexture.loadFromFile("bird.png");

	sf::Sprite myPlayer;
	myPlayer.setTexture(birdtexture);
	myPlayer.setPosition(200, 200);
	myPlayer.setScale(1,1);

	//Column
	sf::Texture mctexture;
	mctexture.loadFromFile("pipe.png");
	mctexture.setRepeated(true);

	sf::Sprite myCol;
	myCol.setTexture(mctexture);
	myCol.setScale(1, 1);

	//Music
	sf::Music myMusic;
	if (!myMusic.openFromFile("music.ogg")) {
		std::cout << "music error" << std::endl;
	}
	myMusic.setPosition(0, 0,0);
	myMusic.setVolume(50);
	myMusic.setLoop(true);
	myMusic.play();

	//Text
	sf::Font myFont;
	myFont.loadFromFile("arial.ttf");

	sf::Text myText;
	myText.setFont(myFont);
	myText.setCharacterSize(24);
	myText.setPosition(15, 15);

	std::string msg = std::to_string(player->score);
	myText.setString("Score: "+msg);

	double gravity = 8;
	
	while (myWindow.isOpen()) {
		//Clear window
		myWindow.clear();

		//Window events
		sf::Event myEvent;
		while (myWindow.pollEvent(myEvent)) {
			if (myEvent.type == sf::Event::Closed) {
				myWindow.close();
			}
			if (myEvent.type == sf::Event::KeyPressed) {
				switch (myEvent.key.code) {
				case 71:
					break;
				case 72:
					break;
				case 73:
					break;
				case 74:
					break;
				case 57:
					gravity = -15;
					break;
				}
			}
				
		}
		//Calculate positions, stats etc.
		if (gravity < 8) {
			gravity += 0.8;
		}
		if (gravity >= 8) {
			gravity += 0.2;
		}
		player->y += gravity;
		if (player->y < 0) {
			player->y = 0;
			gravity = std::abs(gravity);
		}
		myPlayer.setPosition(player->x, player->y);

		for (int i = 0; i < vObject.size(); i++) {
			if (player->x >= vObject[i].x && player->x <= vObject[i].x + vObject[i].width || player->x + player->width >= vObject[i].x && player->x + player->width <= vObject[i].x + vObject[i].width) {

				if (player->y <= vObject[i].y1 + vObject[i].upheight) {
					myWindow.close();
				}
				if (player->y + player->height >= vObject[i].y2 - vObject[i].downheight) {
					myWindow.close();
				}
			}

		}

		//Draw elements
		myWindow.draw(myBackground);

		sf::Color columnColor(0, 200, 0);
		for (int i = 0; i < vObject.size(); i++) {

			vObject[i].x += vObject[i].xv;
			
			myCol.setTextureRect(sf::IntRect(0,0,vObject[i].width,vObject[i].upheight));
			myCol.setPosition(vObject[i].x, vObject[i].y1);
			myWindow.draw(myCol);

			myCol.setTextureRect(sf::IntRect(0, 0, vObject[i].width, vObject[i].downheight));
			myCol.setPosition(vObject[i].x, vObject[i].y2-vObject[i].downheight);
			myWindow.draw(myCol);

			if (vObject[i].x == player->x) {
				player->score++;
				std::string msg = std::to_string(player->score);
				myText.setString("Score: " + msg);
			}
			if (vObject[i].x < 0 - vObject[i].width-200) {
				vObject.erase(vObject.begin());
			}
			if (vObject[vObject.size()-1].x < 600) {
				vObject.push_back(eObject(rand() % 100 + 31, rand() % 100 + 31));
			}
		}

		myWindow.draw(myPlayer);
		myWindow.draw(myText);
		//Display window
		myWindow.display();
	}

	return 0;
}
