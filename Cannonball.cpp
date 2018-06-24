#include "Cannonball.h"



Cannonball::Cannonball()
{
}


Cannonball::Cannonball(sf::Vector2f pos, float rot, float vel)
{
	this->setPosition(pos);
	this->velocity = vel;
	this->setRotation(rot);


}


Cannonball::~Cannonball()
{
}

void Cannonball::update(sf::Time delta)
{
	this->move((this->getForwardVector().x * velocity) * delta.asSeconds(), (this->getForwardVector().y * velocity) * delta.asSeconds());

	//TODO:

	//if this.intersects... etc
	
	//delete when out of bounds

}

sf::Vector2f Cannonball::getForwardVector()
{
	//convert the rotation angle to radians then cos and sin it for X and Y values in a unit vector
	return sf::Vector2f(cos(this->getRotation()*MATH_PI / 180), sin(this->getRotation()*MATH_PI / 180));

	//TODO: Clamp this
}