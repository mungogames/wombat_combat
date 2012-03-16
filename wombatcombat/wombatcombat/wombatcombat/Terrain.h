//  Terrain.h
//  wombatcombat
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MungoGames__. All rights reserved.
//

#ifndef wombatcombat_Terrain_h
#define wombatcombat_Terrain_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Box2D/Box2D.h>

#include "GameContainer.h"

class Terrain
{
  
private:
  int pointCount;
  
  b2Vec2* chainVertices;
  sf::VertexArray renderVertices;  
  
  b2BodyDef* bodyDef;
  b2Body* body;
  
  b2ChainShape* chain;
  
public:
  Terrain (GameContainer* gc, int pointCount, float posX, float posY);
  void addPoint(int index, float x, float y);
  void generate();
  
  void render(GameContainer* gc);
};

#endif
