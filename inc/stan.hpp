#ifndef stan_h
#define stan_h

#include "window.hpp"
#include "object.hpp"

class Stan : public Object {
	public:
    Stan(Window m, std::string s, int health, int light, int x, int y);
		int getHealth();
		int getLight();
	private:
		int health = 100;
		int light = 100;
};

#endif
