#ifndef bolt_h
#define bolt_h

#include "window.hpp"
#include "object.hpp"

class Bolt : public Object{
  public:
    Bolt(Window m, std::string s, int sdirection, int x, int y, int boltcount);
    int checkWindow();
    int getXspeed();
    int getYspeed();
  private:
    int onscreen = 1;
};

#endif
