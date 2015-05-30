#ifndef davorin_h
#define davorin_h

#include "window.hpp"

class Davorin
{
	public:
    Davorin(Window m, std::string s);
		SDL_Texture* loadTexture(std::string path, Window main);
    void Place();

	protected:
    int xPosition, yPosition; //Coordinates of entity on window
		int height, width; //Dimensions of image on window
		int degrees = 0;
		SDL_Texture* texture;
		SDL_Renderer* renderer;
};

#endif
