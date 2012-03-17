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

class BaseGame
{
  private:
	GameContainer* gc;
  
	Player* player;
	Camera* camera;
	Terrain* terrain;
	DynBox* rock1;
	DynBox* rock2;
  
  public:
  	  BaseGame(GameContainer* gc);
  	  void update();
  	  void render();
};

#endif
