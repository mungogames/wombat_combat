/////////////////////////////////////////////
/// @brief Creature Class
/// Base class for all sorts of creatures like the player, NPCs or Enemies
///
/// @author Simon J
/// @date 03/15/2012 - 03/18/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

#ifndef wombatcombat_Creature_h
#define wombatcombat_Creature_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include <string>

#include "CreatureData.h"
#include "SensorData.h"
#include "GameContainer.h"

using namespace std;


class Creature 
{
  
protected:  
  GameContainer* gc;
  
  CreatureData* creatureData;
  SensorData* footSensorData;
  
  b2Body* body;
  sf::RectangleShape renderObj;
  
  b2Fixture* footSensorFixture;
  
public:
  Creature (GameContainer* gc, float posX, float feetPosY, float sizeX, float sizeY);
  
  // Getter
  b2Vec2 getPos();
  float getMinX();
  float getMaxX();
  float getMinY();
  float getMaxY();
  b2Vec2 getSize();
  b2Vec2 getHalfSize();
  sf::RectangleShape getShape();
  bool isOnGround();
  b2Body* getBody();
  
  // Setter
  void setPos(float x, float y);
  void setPos(string side, float value);
  void setSize(float x, float y);
  void setSize(string side, float value);
  
  
};

#endif
