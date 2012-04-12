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
  GameContainer* gc;
  CreatureData* creatureData;
  b2Body* playerBody;
  
  int attackPower;
  float shootSpeed;
  
  
  int anglePrefix;
  float radiant;
    
  b2Vec2 gunSize;
  float weaponOffset;
  b2Vec2 arrowEmitter;
  
  b2PolygonShape* bowShape;
  
  vector<Arrow*> arrows;
  
  bool mousePressReady;
  
  // Object
  sf::RectangleShape* renderObj;
  
  
public:
  Gun (GameContainer* gc, CreatureData* creatureData, b2Body* playerBody, int attackPower, float shootSpeed);
  
  void attack();
  
  void update();
  void render();
};

#endif
