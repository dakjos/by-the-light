#include "main.hpp"

int main()
{
	Window main;
	Event e;

	while(e.gRun())
	{
		while(e.Poll())
		{
			if(e.gEventType() == SDL_QUIT)
				e.off();
			//else if(e.gEventType() == SDL_KEYDOWN)
			//	eventHandle(e.gEvent());
		}

		main.Clear();

    //stuffm goes here

		main.Render();
	}

	main.Destroy();
	return 0;
}
