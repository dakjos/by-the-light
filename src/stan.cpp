#include "stan.hpp"

Stan::Stan(Window m, std::string s, int health, int light, int x, int y) //Constructor
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = health;
	light = light;
	xPosition = x;
	yPosition = y;
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
    	  case SDLK_w: yPosition-=speed; break;
        case SDLK_s: yPosition+=speed; break;
        case SDLK_a: xPosition-=speed; break;
        case SDLK_d: xPosition+=speed; break;
    }
}

int Stan::getHealth(){
	return health;
}

int Stan::getLight(){
	return light;
}

int Stan::getX(){
	return xPosition;
}

int Stan::getY(){
	return yPosition;
}

int Stan::getSpeed(){
	return speed;
}

void Stan::setDirection(int x){
	direction = x;
}

int Stan::getDirection(){
	return direction;
}
