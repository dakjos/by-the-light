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

  for(int i=0; i<numbolts; ++i){
    if(boltcount[i] == 0){
      initdir.push_back(direction);// = direction;
      initx.push_back(x);// = x;
      inity.push_back(y);//[i] = y;
      switch(direction){
        case 1:{
          Bolt b = Bolt(m, "img/bolt_of_light_up.png", initdir[i], initx[i], inity[i], boltcount[i]);       B.push_back(b);
        }
        break;
        case 2:{
          Bolt b = Bolt(m, "img/bolt_of_light_down.png", initdir[i], initx[i], inity[i], boltcount[i]);       B.push_back(b);
        }
        break;
        case 3:{
          Bolt b = Bolt(m, "img/bolt_of_light_left.png", initdir[i], initx[i], inity[i], boltcount[i]);        B.push_back(b);
        }
        break;
        case 4:{
          Bolt b = Bolt(m, "img/bolt_of_light_right.png", initdir[i], initx[i], inity[i], boltcount[i]);          B.push_back(b);
        }
        break;
      }
    }
    switch(initdir[i]){
      case 1:{
        B[i].setYPosition(inity[i]-(boltcount[i]*B[i].getSpeed()));
      }
      break;
      case 2:{
        B[i].setYPosition(inity[i]+(boltcount[i]*B[i].getSpeed()));
      }
      break;
      case 3:{
        B[i].setXPosition(initx[i]-(boltcount[i]*B[i].getSpeed()));
      }
      break;
      case 4:{
        B[i].setXPosition(initx[i]+(boltcount[i]*B[i].getSpeed()));
      }
      break;
    }
    boltcount[i] += 1;
  }
  for(int i=0;i<numbolts;i++){
    if(!B[i].checkWindow()){
      numbolts -= 1; B.erase(B.begin()+i);
      initx.erase(initx.begin()+i);
      inity.erase(inity.begin()+i);
      initdir.erase(initdir.begin()+i);
      boltcount.erase(boltcount.begin()+i);
    }
  }
  for(int i=0; i<numbolts; ++i)
    B[i].Place();

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
          boltcount.push_back(0);
          numbolts += 1;
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
double Game::distanceFromStan(int x, int y){
  int stanX = S[0].getX();
  int stanY = S[0].getY();
  double distance = sqrt(pow(stanX - x, 2) + pow(stanY - y, 2));
  return distance;
}
