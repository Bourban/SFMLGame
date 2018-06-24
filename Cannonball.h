#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Time.hpp>

class Cannonball : public sf::Sprite
{
public:
	Cannonball();
	Cannonball(sf::Vector2f pos, float rot, float vel);
	~Cannonball();

	void update(sf::Time delta);


private:

	sf::Vector2f getForwardVector();

	float velocity;
	const float MATH_PI = 3.14159265;


};

