#include "bolt.hpp"

Bolt::Bolt(Window m, std::string s, int x, int y){
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	xPosition = x;
	yPosition = y;
}
