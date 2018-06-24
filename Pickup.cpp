#include "Pickup.h"
#include <math.h>


Pickup::Pickup()
{

	this->setPosition(sf::Vector2f(rand() % 1200 + 10, rand() % 700 + 10));

}


Pickup::~Pickup()
{
}

void Pickup::update(sf::Time delta)
{

}

void Pickup::checkCollision(sf::Sprite otherSprite)
{


}
