#ifndef game_h
#define game_h

#include "window.hpp"
#include "event.hpp"
#include "stan.hpp"
#include "bolt.hpp"
#include "enemies.hpp"

class Game {
public:
  Game(Window m);
  void Place(Window m);
  void action(Window m, SDL_Event& e);
  void badBehavior();
  double distanceFromStan(int x, int y);
  double distanceFromBolt(int x, int y);
  bool checkBolt(Enemy e);
  bool checkFacing(Enemy e);
  void stanSlash(Window m, std::vector<Stan> S);
  void stanUnslash(Window m, std::vector<Stan> S);
  void updateBoltPos(Window m);

private:
  std::vector<Stan> S;
  std::vector<Bolt> B;
  std::vector<Enemy> E;
  bool slashing = 0;
  bool unslashing = 0;
  int badMove = 0;
  std::vector<int> boltcount;
  std::vector<int> initdir;
  std::vector<int> initx;
  std::vector<int> inity;
  int numbolts = 0;
};

#endif
