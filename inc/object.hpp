#ifndef object_h
#define object_h

#include "window.hpp"

class Object {
public:
	SDL_Texture* loadTexture(std::string path, Window main);
	void Place();
protected:
	int xPosition, yPosition, height, width;
	int degrees = 0;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
};

#endif
