#pragma once

#include <math.h>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "PlayerControls.h"



class Player : public sf::Sprite
{
public:
	Player();
	Player(PlayerControls pcontrols, sf::Vector2f ppos, float prot);
	~Player();

	void update(sf::Time delta);
	//Inherits from sprite, no draw() needed
	
	bool hasFiredLeft() const;
	bool hasFiredRight() const;

	sf::FloatRect boundingBox = this->getLocalBounds();

private:
	PlayerControls controls;

	sf::Vector2f getForwardVector();

	//required to send projectiles in the correct direction -- Exactly the same as getForwardVector but add or subtract 90 from the sfml rotation value
	sf::Vector2f getLeftVector();
	sf::Vector2f getRightVector();

	void handleInputs(sf::Time delta);

	

	//Firing logic
	bool firedRight = false;
	bool firedLeft = false;

	const float MATH_PI = 3.14159265;

	//movement functions
	void accelerate(float delta);
	void decelerate(float delta);
	void turnLeft(float delta);
	void turnRight(float delta);

	//actual firing logic in game -- instanciating bullet objects needs to be done in the main game class
	void fireLeft();
	void fireRight();

	//Movement variables
	float currSpeed = 0.0f;
	float maxSpeed = 100.f;
	float accelerationRate = 10.0f;
	float turnRate = 50.0f;

};
