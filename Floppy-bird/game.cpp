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
	sf::CircleShape myPlayer(100);
	myPlayer.setPosition(sf::Vector2f(100, 100));
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
				
		}

		
		myWindow.draw(myBackground);
		myWindow.draw(myPlayer);

		//Display window
		myWindow.display();
	}

	return 0;
}
