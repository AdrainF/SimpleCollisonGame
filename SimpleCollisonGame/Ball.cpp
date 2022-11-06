#include "Ball.h"
	//Private functions
void Ball::initShape(sf::RenderWindow* window)
{
	/*
		* Set random size
		* Set max Windows bound 
		* set random colors
		* set random spawn positions
		
	*/
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color;

	switch (this->type)
	{
	case DEFAULT:
		color= sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		break;
	case DAMAGING:
		color = sf::Color::Red;
		this->shape.setOutlineThickness(2);
		this->shape.setOutlineColor(sf::Color::White);
		break;
	case HEALING:
		color = sf::Color::Green;
		this->shape.setOutlineThickness(2);
		this->shape.setOutlineColor(sf::Color::White);
		break;

	}



	this->shape.setFillColor(color);


	int x= window->getSize().x - this->shape.getGlobalBounds().width;
	int y= window->getSize().y - this->shape.getGlobalBounds().height;
	
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand() % x
			),
		static_cast<float>(rand() % y
			)
	)
	);
}

	//Constructor / destructor
Ball::Ball(sf::RenderWindow* window, int type)
	:type(type)
{
	this->initShape(window);
}

Ball::~Ball()
{
}


sf::CircleShape Ball::getShape()
{
	return this->shape;
}
	//Functions
void Ball::update()
{
}

void Ball::render(sf::RenderWindow& target)
{
	target.draw(this->shape);
}

int Ball::getType()
{
	return this->type;
}
