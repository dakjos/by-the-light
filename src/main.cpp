#include "main.hpp"

int main()
{
	Window main;
  Stan s(main, "img/stan-forward.png");
	Event e;

	while(e.gRun())
	{
		while(e.Poll())
		{
			if(e.gEventType() == SDL_QUIT)
				e.off();
			else if(e.gEventType() == SDL_KEYDOWN)
			  s.movement(e.gEvent());
		}

		main.Clear();

    s.Place();

		main.Render();
	}

	main.Destroy();
	return 0;
}
