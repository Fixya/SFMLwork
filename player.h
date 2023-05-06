#pragma once
#include "settings.h"
#include "game_object.h"
#include "Text.h"
#include "apple.h"

class Player : public GameObject
{
private:
	float speedx = 0;
	sf::Clock timer;
	TextObj pointText;
public:
	Player()
	{
		texture.loadFromFile(PLAYER_TEXTURE_FILE);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	}
	void update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			speedx = -PLAYER_SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			speedx = PLAYER_SPEED;
		}
		sprite.move(speedx, 0.f);
		pointText.update("Points: " + std::to_string(point));
	}

	void draw(sf::RenderWindow window)
	{
		window.draw(sprite);
		pointText.draw(window);
	}
};