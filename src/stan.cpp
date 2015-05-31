#include "stan.hpp"

Stan::Stan(Window m, std::string s, int health, int light, int x, int y){
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = health;
	light = light;
	xPosition = x;
	yPosition = y;
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
