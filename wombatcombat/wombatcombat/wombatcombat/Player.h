//
//  Player.h
//  wombatcombat
//
//  Created by Simon Jentsch on 17.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef wombatcombat_Player_h
#define wombatcombat_Player_h

#include "enums.h"
#include "GameContainer.h"
#include "Creature.h"
#include "CreatureData.h"

using namespace std;

class Player: public Creature 
{
  //Parameters 
private:  
  float movingSpeed;
  float runningSpeed;
  Direction movingDirection;
  
  float jumpSpeed;
  
  bool running;
  
public:
  // Constructor
  Player(GameContainer* gc, float posX, float posY, float sizeX, float sizeY);
  
  // Getter
  Direction getMovingDirection();
  float getJumpSpeed();
  bool isRunning();
  bool isMoving();
  
  //Setter
  void setJumpSpeed(float jumpSpeed);
  void move(Direction direction);
  void stopMoving();
  void jump();
  void setRunning(bool running);
  
  //Update and render methods
  void update(GameContainer* gc);
  void render(GameContainer* gc);

  ///BORIS BEGIN

  ///BORIS END

};



#endif
