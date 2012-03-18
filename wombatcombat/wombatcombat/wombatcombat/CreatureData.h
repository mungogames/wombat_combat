//
//  PlayerData.h
//  notld_pt
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef notld_pt_PlayerData_h
#define notld_pt_PlayerData_h

#include <Box2D/Box2D.h>
#include <string>
#include "enums.h"
using namespace std;

class CreatureData
{
public:
  string name;
  b2Vec2 hitboxSize;
  Direction lookingDirection;
  
  CreatureData();
  
};


#endif
