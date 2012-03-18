//
//  Arrow.h
//  wombatcombat
//
//  Created by Simon Jentsch on 17.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef wombatcombat_Arrow_h
#define wombatcombat_Arrow_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include "SensorData.h"
#include "GameContainer.h"
#include "enums.h"

class Arrow 
{
private:
  
  GameContainer* gc;
  
  sf::Clock timer;
  float livingTime;
  
  int damage;
  b2Vec2 speed;
  
  b2Body* body;
  sf::RectangleShape renderObj;
  
  SensorData* arrowSensorData;
  
  
public:
  Arrow(GameContainer* gc, int damage, b2Vec2 speed, b2Vec2 pos, Direction side);
  ~Arrow();
  
  b2Body* getBody();
  float getLivingPos();
  
  void update();
  void render();
  
};

#endif
