#include "Game.h"
	
	//Private functions
void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBallsCount = 10;

}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(videoMode, "Simple Collison Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::poolEvent()
{

	/*
	Checking if end button or "Esc" is pressed
	*/
	while (this->window->pollEvent(sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Key::Escape)
			{
				this->window->close();
				break;
			}

		}

	}

}

void Game::spawnBalls()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->balls.size() < this->maxBallsCount)
		{
			this->balls.push_back(Ball(window,rand()%ballsType::NROFTYPES));
			this->spawnTimer = 0.f;
		}



	}
}

void Game::updateCollison()
{

	/*
	* Destroys the balls when they collide with the player
	* Verifies the type of ball and on this basis adds points, HP points or damages the player
	*/

	for (size_t i=0; i<this->balls.size();i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->balls[i].getShape().getGlobalBounds()))
		{
			switch (balls[i].getType())
			{
			case DEFAULT:
			
			this->balls.erase(balls.begin() + i);
			this->points += 1;

			std::cout << "Points: " << this->points<<"\n";
			break;

			case DAMAGING:
				this->balls.erase(balls.begin() + i);
				this->player.takeDamage(10);
				if (this->player.getHp() <= 0)
				{
					this->endGame = true;
				}

				break;

			case HEALING:
				this->balls.erase(balls.begin() + i);
				this->player.getHp()+=1;
				
				break;
			}
		}
	}

}

void Game::renderText(sf::RenderTarget& target)
{
	
	target.draw(this->text);


}

void Game::renderEndGameText(sf::RenderTarget& target)
{

	target.draw(this->endGameText);
}

void Game::initFont()
{
	if (!this->font.loadFromFile("Fonts//Dosis-Light.ttf"))
	{
		std::cout << "ERROR::GAME:INITFONTS ";
	}
}

void Game::initText()
{
	this->text.setFont(font);
	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::White);

	this->endGameText.setFont(font);
	this->endGameText.setPosition(sf::Vector2f(300.f, 200.f));
	this->endGameText.setCharacterSize(50);
	this->endGameText.setFillColor(sf::Color::Red);
	
}

void Game::updateText()
{

	//Builds a string displayed on the window
	std::stringstream ss;
	ss << "Points: " << this->points<<"\n"
		<<"HP: "<<this->player.getHp();
	this->text.setString(ss.str());

	this->endGameText.setString("YOU ARE DEAD!!");
}

//COnstructor /destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
}

Game::~Game()
{
}

bool Game::getEndGame()
{
	return this->endGame;
}

//Functions
bool Game::running()
{
	return this->window->isOpen();
}


void Game::update()
{
	this->spawnBalls();
	this->updateCollison();
	this->updateText();
}

void Game::render()
{
	this->poolEvent();
	this->window->clear();
	if (!this->getEndGame())
	{
		this->player.update(*this->window);
		
	}
	else
	{
		this->renderEndGameText(*this->window);
	}
	
	this->player.render(*this->window);
	//loop through all balls vector objects
	for (auto& i : this->balls	)
	{
		i.render(*this->window);
	}

	this->renderText(*this->window);
	this->window->display();


}
