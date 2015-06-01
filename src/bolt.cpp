#include "bolt.hpp"

Bolt::Bolt(Window m, std::string s, int sdirection, int x, int y, int boltcount){
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	setDirection(sdirection);
	xPosition = x + (boltcount * getXspeed());
	yPosition = y + (boltcount * getYspeed());
	onscreen = checkWindow();
}

int Bolt::checkWindow(){
  if((xPosition < 0 || yPosition < 0 ) || (xPosition > 1280 || yPosition > 800))
    return 0;
  else
    return 1;
}


int Bolt::getYspeed(){
	if(getDirection() == 1)
		return -getSpeed();
	if(getDirection() == 2)
		return getSpeed();
	return 0;
}

int Bolt::getXspeed(){
	if(getDirection() == 3)
		return -getSpeed();
	if(getDirection() == 4)
		return getSpeed();
	return 0;
}
