#include "enemies.hpp"

Enemy::Enemy(Window m, std::string s, int health){
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = health;
	xPosition = rand()%800;
	yPosition = rand()%1200;
}

int Enemy::getHealth(){
	return health;
}

int Enemy::getTargetX(){
	return targetX;
}

int Enemy::getTargetY(){
	return targetY;
}

void Enemy::setTargetX(int x){
	targetX = x;
}

void Enemy::setTargetY(int y){
	targetY = y;
}
