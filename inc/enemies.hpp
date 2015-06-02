#ifndef enemies_h
#define enemies_h

#include "window.hpp"
#include "object.hpp"

class Enemy : public Object {
	public:
    Enemy(Window m, std::string s, int health);
		int getHealth();
		int getTargetX();
		int getTargetY();
		void setTargetX(int x);
		void setTargetY(int y);
	private:
		int health;
		int speed = 10;
		int targetX, targetY;
};

#endif
