#include "Player.h"

	//Private functions
void Player::initVariable()
{
	this->playerSpeed = 5.f;
	this->hp = 10;

}

void Player::initShape()
{
	/*
	The function responsible for declaring the value of the object - the player
	*/
	this->shape.setPosition(sf::Vector2f(400, 500));
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Blue);
}

void Player::updateInput()
{
	/*
	 A function that responds to moving the player
	*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->shape.move(-playerSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->shape.move(playerSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->shape.move(0.f, -playerSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->shape.move(0.f, playerSpeed);
	}
}

void Player::updateWindowCollison(sf::RenderTarget& target)
{
	/*
	Checks that the shape of the player does not exceed the dimensions of the window
	*/

	if (this->shape.getGlobalBounds().left<=0.f	)
	{
		this->shape.setPosition(0.f, this->shape.getPosition().y);
	}
	if (this->shape.getGlobalBounds().left+this->shape.getGlobalBounds().width >= target.getSize().x)
	{
		this->shape.setPosition(target.getSize().x - this->shape.getGlobalBounds().width, this->shape.getPosition().y);
	}
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		this->shape.setPosition(this->shape.getPosition().x, 0.f );
	}
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target.getSize().y)
	{
		this->shape.setPosition(this->shape.getPosition().x, target.getSize().y - this->shape.getGlobalBounds().height);
	}
}



	//Constructor / destructor
Player::Player()
{
	this->initVariable();
	this->initShape();
}

Player::~Player()
{
}



	//Accessors
sf::RectangleShape Player::getShape()
{
	return this->shape;
}




int& Player::getHp()
{
	return this->hp;
}

//Functions


void Player::takeDamage(const int damage)
{
	this->hp -= damage;
}

void Player::getHealing(const int hp)
{
	this->hp += hp;
}

void Player::update(sf::RenderTarget & target)
{
	this->updateInput();
	this->updateWindowCollison(target);
}

void Player::render(sf::RenderTarget& target)
{
target.draw(this->shape);
}
