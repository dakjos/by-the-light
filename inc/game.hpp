#ifndef game_h
#define game_h

#include "window.hpp"
#include "event.hpp"
#include "stan.hpp"

class Game {
public:
  Game(Window m);
  void Place(Window m);
  void action(Window m, SDL_Event& e);
private:
  std::vector<Stan> S;
  bool slashing = 0;
  bool unslashing = 0;
};

#endif
