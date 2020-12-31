#include "Game.h"

int main(int argc, char** ){
    bool DEBUG = true;
	// Program entry point.
	Game game(DEBUG);
	while(!game.GetWindow()->IsDone()){
		game.Update();
		game.Render();
		game.RestartClock();
	}
}
