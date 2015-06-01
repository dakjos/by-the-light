#include "bolt.hpp"

Bolt::Bolt(Window m, std::string s, int x, int y){
	texture = loadTexture(s, m);
	renderer = m.getRenderer();

	xPosition = x;
	yPosition = y;
}

int Bolt::getX(){
	return xPosition;
}

int Bolt::getY(){
	return yPosition;
}

int Bolt::getBoltSpeed(){
	return speed;
}

void Bolt::setDirection(int x){
	direction = x;
}

int Bolt::getDirection(){
	return direction;
}
