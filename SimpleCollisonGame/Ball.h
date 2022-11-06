#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum ballsType
{
	DEFAULT = 0,
	HEALING,
	DAMAGING,
	NROFTYPES
};

class Ball
{
private:
	//Variable
	sf::CircleShape shape;
	int type;

	//Private functions
	void initShape(sf::RenderWindow* window);
public:

	//Constructor / destructor
	Ball(sf::RenderWindow* window, int type);
	~Ball();


	//Accessors
	sf::CircleShape getShape();

	//Functions

	void update();
	void render(sf::RenderWindow& target);
	int getType();


};

