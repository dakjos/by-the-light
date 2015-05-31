#include "game.hpp"

Game::Game(Window m)
{
  Stan s(m, "img/stan-forward.png", 100, 100, 100, 100);
  Slash a(m, "img/front_slash.png",100,100);
  S.push_back(s);
  A.push_back(a);
}

void Game::Place()
{
  S[0].Place();
  if(attacking){
    A[0].Place();
    sleep(2);
    attacking = 0;
  }
}

void Game::action(Window m, SDL_Event& e)
{
  int health = S[0].getHealth();
  int light = S[0].getLight();
  int speed = S[0].getSpeed();
  int x = S[0].getX();
  int y = S[0].getY();

	switch(e.key.keysym.sym)
    {
    	  case SDLK_w:
        {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-forward.png", health, light, x, y-speed);
          S.push_back(s);
        }
          break;

        case SDLK_s:
        {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-backward.png", health, light, x, y+speed);
          S.push_back(s);
        }
          break;

        case SDLK_a:
        {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-left.png", health, light, x-speed, y);
          S.push_back(s);
        }
          break;

        case SDLK_d:
        {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-right.png", health, light, x+speed, y);
          S.push_back(s);
        }
          break;

        case SDLK_e:
        {
          attacking = 1;
          A.erase(A.begin());
          Slash a = Slash(m, "img/front_slash.png", x, y);
          A.push_back(a);
        }
          break;
    }
}