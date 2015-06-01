#include "enemies.hpp"

Enemy::Enemy(Window m, std::string s, int health, int x, int y){
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = health;
	xPosition = x;
	yPosition = y;
}

int Enemy::getHealth(){
	return health;
}
