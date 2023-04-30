#include <iostream>
#include "Game.h"


int main() {
	//init game engine

	Game game;

	//Game loop
	while (game.running())
	{
		//Update
		game.update();

		//Render
		game.render();

		
	}

	//End of application
	return 0;
}