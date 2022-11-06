#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Player
{
private:
	//Variables
	sf::RectangleShape shape;
	float playerSpeed;
	int maxHp;
	int hp;
	
	//Private functions
	void initVariable();
	void initShape();
	void updateInput();
	void updateWindowCollison(sf::RenderTarget & target);

	
	
public:
	//Constructor / destructor
	Player();
	~Player();


	//Accessors
	sf::RectangleShape getShape();
	int& getHp();
	//Functions
	void takeDamage(const int damage);
	void getHealing(const int hp);

	void update(sf::RenderTarget & target);
	void render(sf::RenderTarget& target);

};

