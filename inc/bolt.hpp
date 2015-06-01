#ifndef bolt_h
#define bolt_h

#include "window.hpp"
#include "object.hpp"

class Bolt : public Object{
  public:
    Bolt(Window m, std::string s, int x, int y);
};

#endif
