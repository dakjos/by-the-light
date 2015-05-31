#ifndef stan_h
#define stan_h

#include "window.hpp"
#include "object.hpp"

class Stan : public Object {
	public:
    Stan(Window m, std::string s, int health, int light, int x, int y);
		int getHealth();
		int getLight();
		int getX();
		int getY();
		int getSpeed();
		void setDirection(int x);
		int getDirection();
	private:
		int health = 100;
		int light = 100;
		int speed = 20;
		int direction = 1; //1 - forward; 2 - backward; 3 - left; 4 - right;
};

#endif
