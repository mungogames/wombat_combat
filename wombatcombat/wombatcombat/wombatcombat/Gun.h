//
//  Bow.h
//  wombatcombat
//
//  Created by Simon Jentsch on 17.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef wombatcombat_Gun_h
#define wombatcombat_Gun_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>

#include "GameContainer.h"
#include "CreatureData.h"
#include "Arrow.h"

class Gun
{
  
private:
  CreatureData* creatureData;
  b2Body* playerBody;
  
  int attackPower;
  float shootSpeed;
    
  b2Vec2 gunSize;
  float weaponOffset;
  
  b2PolygonShape* bowShape;
  
  vector<Arrow*> arrows;
  
  bool mousePressReady;
  
  // Object
  sf::RectangleShape* renderObj;
  
  
public:
  Gun (CreatureData* creatureData, b2Body* playerBody, int attackPower, float shootSpeed);
  
  void attack();
  
  void update(GameContainer* gc);
  void render(GameContainer* gc);
};

#endif
