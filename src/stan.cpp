#include "stan.hpp"

Stan::Stan(Window m, std::string s) //Constructor
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
  yPosition=rand()%800;
  xPosition=rand()%1200;
}

void Stan::Place()
{
	SDL_Rect rect = {xPosition, yPosition, width, height};
	SDL_RenderCopyEx(renderer,texture,NULL,&rect,degrees,NULL,SDL_FLIP_NONE);
}

SDL_Texture* Stan::loadTexture(std::string path, Window main)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	height = surface->h;
	width = surface->w;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(main.getRenderer(),surface);
	SDL_FreeSurface(surface);
	return texture;
}

void Stan::movement(SDL_Event& e)
{
	switch(e.key.keysym.sym)
    {
    	  case SDLK_UP: yPosition-=speed; break;
        case SDLK_DOWN: yPosition+=speed; break;
        case SDLK_LEFT: xPosition-=speed; break;
        case SDLK_RIGHT: xPosition+=speed; break;
    }
}
