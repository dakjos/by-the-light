#include "main.hpp"

int main(){
	Window main;
  Game g(main);
	Event e;

	while(e.gRun()){
		while(e.Poll()){
			if(e.gEventType() == SDL_QUIT)
				e.off();
			else if(e.gEventType() == SDL_KEYDOWN)
			    g.action(main, e.gEvent());
		}

		main.Clear();
    g.Place(main);
		g.badBehavior();
		main.Render();
		SDL_Delay(50);
	}

	main.Destroy();
	return 0;
}
