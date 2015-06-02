#include "game.hpp"

Game::Game(Window m){

  Stan s(m, "img/stan-forward.png", 100, 100, 100, 100);
  S.push_back(s);

  for(int i=0;i<5;i++){
    Enemy e(m, "img/enemy-left.png", 100);
    E.push_back(e);
  }
}

void Game::Place(Window m){
  //this probably needs a function
  int health = S[0].getHealth();
  int light = S[0].getLight();
  int speed = S[0].getSpeed();
  int x = S[0].getX();
  int y = S[0].getY();
  int direction = S[0].getDirection();

  for(int i=0;i<E.size();i++){
    E[i].Place();
  }

  if(boltshot){
    if(boltcount == 0){
      initdir = direction;
      initx = x;
      inity = y;
    }
    switch(initdir){
      case 1: {
        if(boltcount > 0)
          B.erase(B.begin());
        Bolt b = Bolt(m, "img/bolt_of_light_up.png", initdir, initx, inity, boltcount);
        B.push_back(b);
        B[0].Place();
        B[0].setDirection(1);
        boltshot = B[0].checkWindow();
      }
      break;
      case 2: {
        if(boltcount > 0)
          B.erase(B.begin());
        Bolt b = Bolt(m, "img/bolt_of_light_down.png", initdir, initx, inity, boltcount);
        B.push_back(b);
        B[0].Place();
        B[0].setDirection(2);
        boltshot = B[0].checkWindow();
      }
      break;
      case 3: {
      if(boltcount > 0)
          B.erase(B.begin());
        Bolt b = Bolt(m, "img/bolt_of_light_left.png", initdir, initx, inity,boltcount);
        B.push_back(b);
        B[0].Place();
        B[0].setDirection(3);
        boltshot = B[0].checkWindow();
      }
      break;
      case 4: {
        if(boltcount > 0)
          B.erase(B.begin());
        Bolt b = Bolt(m, "img/bolt_of_light_right.png", initdir, initx, inity, boltcount);
        B.push_back(b);
        B[0].Place();
        B[0].setDirection(4);
        boltshot = B[0].checkWindow();
      }
      break;
    }
    boltcount += 1;
  }
  else if(!boltshot){
    if(boltcount) {
      boltcount =0;
      initdir = 0;
      B.erase(B.begin());
    }
  }

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
        break;
        case SDLK_q:{
          boltshot = 1;
        }
        break;
    }
}

void Game::badBehavior(){
  badMove = badMove + 1;
  if(badMove%10 != 0)
    return;
  else {
    for(int i=0;i<E.size();i++){
      E[i].setTargetX(S[0].getX());
      E[i].setTargetY(S[0].getY());
    }

    for(int i=0;i<E.size();i++){
      if(E[i].getX()==E[i].getTargetX()){
    		if(E[i].getY()<E[i].getTargetY())
    			E[i].setYPosition(E[i].getY() + E[i].getSpeed());
    		else
          E[i].setYPosition(E[i].getY() - E[i].getSpeed());
    	}
  	  else if(E[i].getY()==E[i].getTargetY()){
  		  if(E[i].getX()<E[i].getTargetX())
          E[i].setXPosition(E[i].getX() + E[i].getSpeed());
  		  else
          E[i].setXPosition(E[i].getX() - E[i].getSpeed());
  	  }
  	  else if(E[i].getX()<E[i].getTargetX()){
  		  if(E[i].getY()<E[i].getTargetY()){
          E[i].setXPosition(E[i].getX() + E[i].getSpeed());
          E[i].setYPosition(E[i].getY() + E[i].getSpeed());
  		  }
  		  else{
          E[i].setXPosition(E[i].getX() + E[i].getSpeed());
          E[i].setYPosition(E[i].getY() - E[i].getSpeed());
  	  	}
  	  }
  	  else if(E[i].getX()>E[i].getTargetX()){
  		  if(E[i].getY()<E[i].getTargetY()){
          E[i].setXPosition(E[i].getX() - E[i].getSpeed());
          E[i].setYPosition(E[i].getY() + E[i].getSpeed());
  		  }
  		  else{
          E[i].setXPosition(E[i].getX() - E[i].getSpeed());
          E[i].setYPosition(E[i].getY() - E[i].getSpeed());
  		  }
  	  }
    }
  }
}
