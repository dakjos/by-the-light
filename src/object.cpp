#include "object.hpp"

SDL_Texture* Object::loadTexture(std::string path, Window main){
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	height = surface->h;
	width = surface->w;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(main.getRenderer(),surface);
	SDL_FreeSurface(surface);
	return texture;
}

void Object::Place(){
	SDL_Rect rect = {xPosition, yPosition, width, height};
	SDL_RenderCopyEx(renderer,texture,NULL,&rect,degrees,NULL,SDL_FLIP_NONE);
}

int Object::getX(){
	return xPosition;
}

int Object::getY(){
	return yPosition;
}

int Object::getWidth(){
	return width;
}

int Object::getHeight(){
	return height;
}

int Object::getSpeed(){
	return speed;
}

int Object::getDirection(){
	return direction;
}

void Object::setDirection(int x){
	direction = x;
}

void Object::setXPosition(int x){
	xPosition = x;
}

void Object::setYPosition(int y){
	yPosition = y;
}
