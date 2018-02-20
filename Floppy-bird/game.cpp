#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
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
	sf::Color backgroundColor(255, 255, 255);
	myBackground.setFillColor(backgroundColor);

	//Player ball
	int playerWidth, playerHeight;
	playerWidth = playerHeight = 30;

	int playerX, playerY;
	playerX = 100;
	playerY = 200;

	float gravity = 8;

	sf::CircleShape myPlayer(playerWidth, playerHeight);
	myPlayer.setPosition(sf::Vector2f(playerX, playerY));
	sf::Color playerColor(200, 0, 0);
	myPlayer.setFillColor(playerColor);
	
	
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
		playerY += gravity;
		myPlayer.setPosition(sf::Vector2f(playerX, playerY));

		//Draw elements
		myWindow.draw(myBackground);
		myWindow.draw(myPlayer);

		//Display window
		myWindow.display();
	}

	return 0;
}
