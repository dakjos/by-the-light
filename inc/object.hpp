#ifndef object_h
#define object_h

#include "window.hpp"

class Object {
public:
	SDL_Texture* loadTexture(std::string path, Window main);
	void Place();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getSpeed();
	int getDirection();
	void setDirection(int x);
	void setXPosition(int x);
	void setYPosition(int y);

protected:
	int xPosition, yPosition, height, width;
	int degrees = 0;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
private:
	int speed = 20;
	int direction = 1; //1: up, 2: down, 3: left, 4: right
};

#endif
