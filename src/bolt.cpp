#include "bolt.hpp"

Bolt::Bolt(Window m, std::string s, int x, int y){
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	xPosition = x;
	yPosition = y;
}

SDL_Texture* Bolt::loadTexture(std::string path, Window main)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	height = surface->h;
	width = surface->w;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(main.getRenderer(),surface);
	SDL_FreeSurface(surface);
	return texture;
}

void Bolt::Place()
{
	SDL_Rect rect = {xPosition, yPosition, width, height};
	SDL_RenderCopyEx(renderer,texture,NULL,&rect,degrees,NULL,SDL_FLIP_NONE);
}
