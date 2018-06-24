#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>


class Pickup : sf::Sprite
{
public:
	Pickup();
	~Pickup();

	void update(sf::Time delta);

private:
	void checkCollision(sf::Sprite otherSprite);

};

