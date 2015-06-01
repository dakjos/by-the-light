#ifndef bolt_h
#define bolt_h

#include "window.hpp"
#include "object.hpp"

class Bolt : public Object{
  public:
    Bolt(Window m, std::string s, int x, int y);
    int getSpeed();
		void setDirection(int x);
		int getDirection();
    int getX();
    int getY();
    int getBoltSpeed();



  private:
    int speed = 20;
    int direction = 1;



};

#endif
