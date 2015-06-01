#include "game.hpp"

Game::Game(Window m){
  Stan s(m, "img/stan-forward.png", 100, 100, 100, 100);
  S.push_back(s);
}

void Game::Place(Window m){
  //this probably needs a function
  int health = S[0].getHealth();
  int light = S[0].getLight();
  int speed = S[0].getSpeed();
  int x = S[0].getX();
  int y = S[0].getY();
  int direction = S[0].getDirection();
  //test lol
  if(slashing){
    switch(direction){
        case 1: {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-slash-up.png", health, light, x, y);
          S.push_back(s);
          S[0].Place();
          S[0].setDirection(1);
          slashing = 0;
          unslashing = 1;
        }
        break;
        case 2: {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-slash-down.png", health, light, x, y);
          S.push_back(s);
          S[0].Place();
          S[0].setDirection(2);
          slashing = 0;
          unslashing = 1;
        }
        break;
        case 3: {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-slash-left.png", health, light, x, y);
          S.push_back(s);
          S[0].Place();
          S[0].setDirection(3);
          slashing = 0;
          unslashing = 1;
        }
        break;
        case 4: {
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-slash-right.png", health, light, x, y);
          S.push_back(s);
          S[0].Place();
          S[0].setDirection(4);
          slashing = 0;
          unslashing = 1;
        }
        break;
      }
    }
  else if(unslashing){
    switch(direction){
      case 1: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-forward.png", health, light, x, y);
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(1);
        unslashing = 0;
      }
      break;
      case 2: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-backward.png", health, light, x, y);
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(2);
        unslashing = 0;
      }
      break;
      case 3: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-left.png", health, light, x, y);
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(3);
        unslashing = 0;
      }
      break;
      case 4: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-right.png", health, light, x, y);
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(4);
        unslashing = 0;
      }
      break;
    }
  }
  else
    S[0].Place();
}

void Game::action(Window m, SDL_Event& e){
  //see? here it is again
  int health = S[0].getHealth();
  int light = S[0].getLight();
  int speed = S[0].getSpeed();
  int x = S[0].getX();
  int y = S[0].getY();
  int direction = S[0].getDirection();

	switch(e.key.keysym.sym){
        case SDLK_w:{
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-forward.png", health, light, x, y-speed);
          S.push_back(s);
          S[0].setDirection(1);
        }
        break;

        case SDLK_s:{
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-backward.png", health, light, x, y+speed);
          S.push_back(s);
          S[0].setDirection(2);
        }
        break;

        case SDLK_a:{
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-left.png", health, light, x-speed, y);
          S.push_back(s);
          S[0].setDirection(3);
        }
        break;

        case SDLK_d:{
          S.erase(S.begin());
          Stan s = Stan(m, "img/stan-right.png", health, light, x+speed, y);
          S.push_back(s);
          S[0].setDirection(4);
        }
        break;

        case SDLK_e:{
          slashing = 1;
        }
        case SDLK_1:{
          boltshot = 1;
        }
        break;
    }
}
