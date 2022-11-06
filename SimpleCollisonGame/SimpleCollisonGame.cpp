#include <iostream>
#include "Game.h"

int main()
{


	//Initialize random seed
	srand(static_cast<float>(time(0)));
    
	//Objects
	Game game;

	//Game loop

	while (game.running()==true)
	{

	//Update game objects


		game.update();
	


	//Render game objects
		game.render();
	}



	//End game
    return 0;

}

