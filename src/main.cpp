#include "main.hpp"

int main()
{
	Window main;
  Davorin d(main, "img/DS.png");
	Event e;

	while(e.gRun())
	{
		while(e.Poll())
		{
			if(e.gEventType() == SDL_QUIT)
				e.off();
			else if(e.gEventType() == SDL_KEYDOWN)
			  d.movement(e.gEvent());
		}

		main.Clear();

    d.Place();

		main.Render();
	}

	main.Destroy();
	return 0;
}
