#ifndef enemies_h
#define enemies_h

#include "window.hpp"
#include "object.hpp"

class Enemy : public Object {
	public:
    Enemy(Window m, std::string s);
		int getHealth();
		int getTargetX();
		int getTargetY();
		void setTargetX(int x);
		void setTargetY(int y);
		void setHealth(int x);
		void checkDirection(Enemy e);
	private:
		int health = 100;
		int speed = 10;
		int targetX, targetY;
};

#endif
