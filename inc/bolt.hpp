#ifndef bolt_h
#define bolt_h

#include "window.hpp"

class Bolt
{
public:
	Bolt(Window m, std::string s, int x, int y);
	SDL_Texture* loadTexture(std::string path, Window main);
	void Place();
protected:
	int xPosition, yPosition, height, width;
	int degrees = 0;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
};

#endif
