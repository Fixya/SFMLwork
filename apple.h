#pragma once
#include "settings.h"

class Apple : public GameObject
{
public:
	Apple();
	void spawn();
	sf::Sprite& getSprite() { return sprite; }
	void update();
private:
	float speedx, speedy;
};
Apple::Apple() {
	texture.loadFromFile(APPLE_TEXTURE_FILE);
	sprite.setTexture(texture);
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);
}

void Apple::spawn()
{
	float appleWidth = sprite.getLocalBounds().width;
	float x = rand() % (int)(WINDOW_WIDTH - appleWidth);
	float y = rand() % (int)(WINDOW_HEIGHT / 2) -WINDOW_HEIGHT / 2;
	sprite.setPosition(x, y);
	sprite.move(speedx, speedy);
}

void Apple::update() {
	sprite.move(speedx, speedy);
	sf::Vector2f pos = sprite.getPosition();
	float appleWidth = sprite.getLocalBounds().width;
	if (pos.x < -appleWidth || pos.y > WINDOW_HEIGHT ||
		pos.x > WINDOW_WIDTH)
	{
		spawn();
	}
}

int getPoint() {
	return point; )