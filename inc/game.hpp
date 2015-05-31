#ifndef game_h
#define game_h

#include "window.hpp"
#include "event.hpp"
#include "stan.hpp"
#include "slash.hpp"

class Game
{
public:
  Game(Window m);
  void Place();
  void action(Window m, SDL_Event& e);

private:
  std::vector<Stan> S;
  std::vector<Slash> A;
};

#endif
