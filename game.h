#pragma once
#include "settings.h"
#include "player.h"
#include <vector>
#include <list>

class Game {
public:
	Game() {
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
	}

	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
private:
	sf::RenderWindow window;
	//Player player;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void update() {
		//player.update();
	}

	void checkCollisions() {}

	void draw()
	{
		window.clear();
		window.display();
	}
};