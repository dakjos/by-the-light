#include "game.hpp"

Game::Game(Window m)
{
  Stan s(m, "img/stan-forward.png", 100, 100, 100, 100);
  S.push_back(s);
}

void Game::Place()
{
  S[0].Place();
}

void Game::movement(Window m, SDL_Event& e)
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
    }
}
