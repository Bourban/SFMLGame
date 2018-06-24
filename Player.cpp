#include "Player.h"
#include "Game.h"
#include <iostream>



Player::Player()
{
	this->setPosition(sf::Vector2f(512, 512));
	//this->setOrigin(sf::Vector2f(this->boundingBox.height / 2, this->boundingBox.width / 2));
	this->setOrigin(sf::Vector2f(76, 33));
}

Player::Player(PlayerControls pcontrols, sf::Vector2f ppos, float prot)
{
	this->controls = pcontrols;
	this->setPosition(ppos);
	this->setRotation(prot);
}


Player::~Player()
{
}

void Player::update(sf::Time delta)
{
	this->firedLeft = false;
	this->firedRight = false;

	this->handleInputs(delta);

	this->move((this->getForwardVector().x * currSpeed) * delta.asSeconds(), (this->getForwardVector().y * currSpeed) * delta.asSeconds());

	boundingBox = this->getGlobalBounds();

}

bool Player::hasFiredLeft() const
{
	return this->firedLeft;
}

bool Player::hasFiredRight() const
{
	return this->firedRight;
}


void Player::accelerate(float delta)
{
	this->currSpeed += accelerationRate * delta;
	if(this->currSpeed >= this->maxSpeed)
	{
		this->currSpeed = this->maxSpeed;
	}
}

void Player::decelerate(float delta)
{
	this->currSpeed -= accelerationRate * delta;
	if (this->currSpeed <= 0)
	{
		this->currSpeed = 0;
	}

}

void Player::turnLeft(float delta)
{
	//TODO: Probably multiply this by some function of currSpeed, boats shouldn't pivot on the spot?
	this->rotate(-(this->turnRate) * delta);
}

void Player::turnRight(float delta)
{
	//TODO: Probably multiply this by some function of currSpeed, boats shouldn't pivot on the spot?
	this->rotate(this->turnRate * delta);
}

void Player::fireLeft()
{
	this->firedLeft = true;

}

void Player::fireRight()
{
	this->firedRight = true;

}


sf::Vector2f Player::getForwardVector()
{
	//convert the rotation angle to radians then cos and sin it for X and Y values in a unit vector
	return sf::Vector2f(cos(this->getRotation()*MATH_PI / 180), sin(this->getRotation()*MATH_PI / 180));

	//TODO: Clamp this
}

sf::Vector2f Player::getLeftVector()
{
	return sf::Vector2f(cos((this->getRotation() -90.0f)*MATH_PI / 180), sin((this->getRotation() - 90.0f)*MATH_PI / 180));
}

sf::Vector2f Player::getRightVector()
{
	return sf::Vector2f(cos((this->getRotation() + 90.0f)*MATH_PI / 180), sin((this->getRotation() + 90.0f)*MATH_PI / 180));
}

void Player::handleInputs(sf::Time delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->turnLeft(delta.asSeconds());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->turnRight(delta.asSeconds());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->accelerate(delta.asSeconds());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->decelerate(delta.asSeconds());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		this->fireLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		this->fireRight();
	}
}

