#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>

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
	sf::RectangleShape myBackground(sf::Vector2f(windowX, windowY));
	myBackground.setPosition(sf::Vector2f(0, 0));
	sf::Color backgroundColor(60, 60, 60);
	myBackground.setFillColor(backgroundColor);

	//Object vector
	std::vector <eObject> vObject;
	vObject.push_back(eObject(rand() % 100 + 31, rand() % 100 + 31));
	
	//Player ball
	playerObject * player = new playerObject;

	sf::CircleShape myPlayer(player->width);
	myPlayer.setPosition(sf::Vector2f(player->x, player->y));
	sf::Color playerColor(244, 170, 66);
	myPlayer.setFillColor(playerColor);

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
		myPlayer.setPosition(sf::Vector2f(player->x, player->y));

		for (int i = 0; i < vObject.size(); i++) {
			if (player->x >= vObject[i].x && player->x <= vObject[i].x + vObject[i].width) {
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
			
			sf::RectangleShape upColumn(sf::Vector2f(vObject[i].width, vObject[i].upheight));
			upColumn.setFillColor(columnColor);
			upColumn.setPosition(sf::Vector2f(vObject[i].x, vObject[i].y1));

			sf::RectangleShape downColumn(sf::Vector2f(vObject[i].width, vObject[i].downheight));
			downColumn.setFillColor(columnColor);
			downColumn.setPosition(sf::Vector2f(vObject[i].x, vObject[i].y2-vObject[i].downheight));

			myWindow.draw(upColumn);
			myWindow.draw(downColumn);

			if (vObject[i].x < 0 - vObject[i].width-200) {
				vObject.erase(vObject.begin());
				player->score++;
				std::cout << player->score << std::endl;
			}
			if (vObject[vObject.size()-1].x < 600) {
				vObject.push_back(eObject(rand() % 100 + 31, rand() % 100 + 31));
			}
		}

		myWindow.draw(myPlayer);

		//Display window
		myWindow.display();
	}

	return 0;
}
