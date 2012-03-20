//
//  GameLoop.h
//  movement_cpp
//
//  Created by Simon Jentsch on 05.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef movement_cpp_GameLoop_h
#define movement_cpp_GameLoop_h

#include "Player.h"
#include "GameContainer.h"
#include "Terrain.h"
#include "Camera.h"
#include "PolyBox.h"

class BaseGame
{
  private:
	GameContainer* gc;
  
	Player* player;
	Camera* camera;
	Terrain* entry;
	PolyBox* boulder;
	PolyBox* box1;
	PolyBox* box2;
	PolyBox* box3;
	PolyBox* platform1;
	PolyBox* platform2;
	PolyBox* platform3;
  
  public:
  	  BaseGame(GameContainer* gc);
  	  void update();
  	  void render();
};

#endif
