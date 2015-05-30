#ifndef stan_h
#define stan_h

#include "window.hpp"

class Stan
{
	public:
    Stan(Window m, std::string s);
		SDL_Texture* loadTexture(std::string path, Window main);
    void Place();
		void movement(SDL_Event& e);

	protected:
    int xPosition, yPosition; //Coordinates of entity on window
		int height, width; //Dimensions of image on window
		int degrees = 0;
		int speed = 20;
		SDL_Texture* texture;
		SDL_Renderer* renderer;
};

#endif
