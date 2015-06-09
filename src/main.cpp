#include "main.hpp"

int main(){
	Window main;
	Event e;
	bool alive = true;
	bool newgame = true;

	while(e.gRun() ){
		Game g(main);


		while(alive && newgame){
			while(e.Poll()){
				if(e.gEventType() == SDL_QUIT)
					e.off();
				else if(e.gEventType() == SDL_KEYDOWN)
				  g.action(main, e.gEvent());
			}

			main.Clear();
	    g.Place(main, main.getRenderer());
			g.badBehavior();

			main.Render();
			alive = g.checkLife();
			SDL_Delay(50);
		}
		newgame == true;
		alive = true;

	}
	main.Destroy();
	return 0;
}
