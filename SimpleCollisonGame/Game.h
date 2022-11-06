#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include "Player.h"
#include "Ball.h"
class Game
{
private:
	
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	bool endGame;
	Player player;
	sf::Event sfmlEvent;
	std::vector<Ball> balls;
	float spawnTimer;
	float spawnTimerMax;
	unsigned maxBallsCount;
	unsigned points;

	sf::Font font;
	sf::Text text;
	sf::Text endGameText;
	//Private functions
	void initVariables();
	void initWindow();
	void poolEvent();
	void spawnBalls();
	void collision();
	void updateCollison();
	void renderText(sf::RenderTarget& target);
	void renderEndGameText(sf::RenderTarget& target);
	void initFont();
	void initText();
	void updateText();


public:

	//COnstructor /destructor
	Game();
	~Game();
	//Accessors
	bool getEndGame();


	//Functions
	

	bool running();
	

	void update();


	void render();

};

