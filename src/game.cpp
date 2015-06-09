#include "game.hpp"

Game::Game(Window m){

  Stan s(m, "img/stan-forward.png", 100, 100, 100, 100);
  S.push_back(s);

  for(int i=0;i<5;i++){
    Enemy e(m, "img/enemy-left.png");
    E.push_back(e);
  }
}

void Game::Place(Window m){

  //Collision Detection
  for(int i=0;i<E.size();i++){
    if(slashing && checkSlashCollision(E[i]) && checkFacing(E[i]))  // && distanceFromStan(E[i].getX(), E[i].getY()) < 100)
      E[i].setHealth(0);
    if( checkBolt(E[i]))
      E[i].setHealth(0);
    if(E[i].getHealth() == 0)
      E.erase(E.begin() + i);
    else
      E[i].Place();
  }

  updateBoltPos(m);

  for(int i=0; i<numbolts; ++i)
    B[i].Place();

  if(slashing)
    stanSlash(m,S);
  else if(unslashing)
    stanUnslash(m,S);
  else
    S[0].Place();

}

void Game::action(Window m, SDL_Event& e){

	switch(e.key.keysym.sym){
    case SDLK_w:{
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-forward.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY()-S[0].getSpeed());
      S.push_back(s);
      S[0].setDirection(1);
    }
    break;
    case SDLK_s:{
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-backward.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY()+S[0].getSpeed());
      S.push_back(s);
      S[0].setDirection(2);
    }
    break;
    case SDLK_a:{
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-left.png", S[0].getHealth(), S[0].getLight(), S[0].getX()-S[0].getSpeed(), S[0].getY());
      S.push_back(s);
      S[0].setDirection(3);
    }
    break;
    case SDLK_d:{
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-right.png", S[0].getHealth(), S[0].getLight(), S[0].getX()+S[0].getSpeed(), S[0].getY());
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

bool Game::checkSlashCollision(Enemy e){

  int eLeft = e.getX();
  int eRight = e.getX() + e.getWidth();
  int eTop = e.getY();
  int eBottom = e.getY() + e.getHeight();

  int stLeft = S[0].getX();
  int stRight = S[0].getX() + S[0].getWidth();
  int stTop = S[0].getY();
  int stBottom = S[0].getY() + S[0].getHeight();


  if(   ((eBottom+25) <= stTop))//  && (S[0].getDirection() != 1 )) //   slahing enemy above stanbottomA <= topB )
  {
    return false;
  }
  if(   ((eTop-25) >= stBottom))//  && (S[0].getDirection() != 2)) //topA >= bottomB ) // Slashin enemy below stan
  {
    return false;
  }
  if( ((eRight+25) <= stLeft))// && (S[0].getDirection() != 3)) //rightA <= leftB ) // Slashing enemy left
  {
    return false;
  }
  if( ((eLeft-25) >= stRight))// && (S[0].getDirection() != 4)) //leftA >= rightB )
  {
    return false;
  } //If none of the sides from A are outside B
  else
  {
    return true;
  }
}

double Game::distanceFromBolt(int x, int y){
  for(int i=0; i<B.size(); ++i){
    double distance = sqrt(pow(B[i].getX() - x, 2) + pow(B[0].getY() - y, 2));
    if(distance < 20){
      numbolts -= 1; B.erase(B.begin()+i);
      initx.erase(initx.begin()+i);
      inity.erase(inity.begin()+i);
      initdir.erase(initdir.begin()+i);
      boltcount.erase(boltcount.begin()+i);
    }
    return distance;
  }
  return 1000;
}

bool Game::checkBolt(Enemy e){
  int eLeft = e.getX();
  int eRight = e.getX() + e.getWidth();
  int eTop = e.getY();
  int eBottom = e.getY() + e.getHeight();

  int bLeft;
  int bRight;
  int bTop;
  int bBottom;

//mill street =


  for(int i=0; i<B.size(); ++i){

    bLeft = B[i].getX();
    bRight = B[i].getX() + B[i].getWidth();
    bTop = B[i].getY();
    bBottom = B[i].getY()  + B[i].getHeight();

    if( eBottom <= bTop) //bottomA <= topB )
    {
      continue;
    }
    if( eTop >= bBottom) //topA >= bottomB )
    {
      continue;
    }
    if( eRight <= bLeft) //rightA <= leftB )
    {
      continue;
    }
    if( eLeft >= bRight) //leftA >= rightB )
    {
      continue;
    } //If none of the sides from A are outside B
    else{
      numbolts -= 1; B.erase(B.begin()+i);
      initx.erase(initx.begin()+i);
      inity.erase(inity.begin()+i);
      initdir.erase(initdir.begin()+i);
      boltcount.erase(boltcount.begin()+i);
      return true;
    }
  }
  return false;
}

bool Game::checkFacing(Enemy e){
  switch(S[0].getDirection()){
    case 1: {
      if(abs(S[0].getX() - e.getX()) < 10 && (S[0].getY() - e.getY()) > 0)
        return true;
      else
        return false;
    }
    break;
    case 2: {
      if(abs(S[0].getX() - e.getX()) < 10 && (S[0].getY() - e.getY()) < 0)
        return true;
      else
        return false;
    }
    break;
    case 3: {
      if((S[0].getX() - e.getX()) > 0 && abs(S[0].getY() - e.getY()) < 10)
        return true;
      else
        return false;
    }
    break;
    case 4: {
      if((S[0].getX() - e.getX()) < 0 && abs(S[0].getY() - e.getY()) < 10)
        return true;
      else
        return false;
    }
    break;
  }
}


void Game::stanSlash(Window m,std::vector<Stan> S){

  switch(S[0].getDirection()){
      case 1: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-slash-up.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(1);
        slashing = 0;
        unslashing = 1;
      }
      break;
      case 2: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-slash-down.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(2);
        slashing = 0;
        unslashing = 1;
      }
      break;
      case 3: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-slash-left.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(3);
        slashing = 0;
        unslashing = 1;
      }
      break;
      case 4: {
        S.erase(S.begin());
        Stan s = Stan(m, "img/stan-slash-right.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
        S.push_back(s);
        S[0].Place();
        S[0].setDirection(4);
        slashing = 0;
        unslashing = 1;
      }
      break;
    }
}


void Game::stanUnslash(Window m, std::vector<Stan> S){

  switch(S[0].getDirection()){
    case 1: {
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-forward.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
      S.push_back(s);
      S[0].Place();
      S[0].setDirection(1);
      unslashing = 0;
    }
    break;
    case 2: {
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-backward.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
      S.push_back(s);
      S[0].Place();
      S[0].setDirection(2);
      unslashing = 0;
    }
    break;
    case 3: {
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-left.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
      S.push_back(s);
      S[0].Place();
      S[0].setDirection(3);
      unslashing = 0;
    }
    break;
    case 4: {
      S.erase(S.begin());
      Stan s = Stan(m, "img/stan-right.png", S[0].getHealth(), S[0].getLight(), S[0].getX(), S[0].getY());
      S.push_back(s);
      S[0].Place();
      S[0].setDirection(4);
      unslashing = 0;
    }
    break;
  }
}

void Game::updateBoltPos(Window m){
  for(int i=0; i<numbolts; ++i){
    if(boltcount[i] == 0){
      initdir.push_back(S[0].getDirection());// = direction;
      initx.push_back(S[0].getX());// = x;
      inity.push_back(S[0].getY());//[i] = y;
      switch(initdir[i]){
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
}
