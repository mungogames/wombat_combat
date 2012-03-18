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
#include "DynBox.h"
#include "StatBox.h"

class BaseGame
{
  private:
	GameContainer* gc;
  
	Player* player;
	Camera* camera;
	Terrain* entry;
	DynBox* boulder;
	DynBox* box1;
	DynBox* box2;
	DynBox* box3;
	StatBox* platform1;
	StatBox* platform2;
	StatBox* platform3;
  
  public:
  	  BaseGame(GameContainer* gc);
  	  void update();
  	  void render();
};

#endif
