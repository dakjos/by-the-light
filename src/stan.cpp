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
