#ifndef enemies_h
#define enemies_h

#include "window.hpp"
#include "object.hpp"

class Enemy : public Object {
	public:
    Enemy(Window m, std::string s, int health, int x, int y);
		int getHealth();
	private:
		int health;
};

#endif
