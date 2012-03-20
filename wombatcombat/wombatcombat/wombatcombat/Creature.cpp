/////////////////////////////////////////////
/// @brief Creature Class
/// Base class for all sorts of creatures like the player, NPCs or Enemies
///
/// @author Simon J
/// @date 03/15/2012 - 03/18/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

#include <iostream>
#include "Creature.h"

/////////////////////////////////////////////
/// @brief Constructor
//
/// @param gc             Reference to the GameContainer
/// @param posX,feetPosY  Position of the player, Y-pos describes lower edge of the hitbox (in meters)
/// @param sizex,sizeY    Size of the hitbox in two directions (in meters)
/////////////////////////////////////////////

Creature::Creature (GameContainer* gc, float posX, float feetPosY, float sizeX, float sizeY)
{
  this->gc = gc;
  
  this->creatureData = new CreatureData();
  
  this->creatureData->name = "Creature";
  this->creatureData->hitboxSize = b2Vec2(sizeX, sizeY);

  // Body Definition (Box2D)
  b2BodyDef bodyDef; // Generates a new body definition which contains values of the Body
  bodyDef.type = b2_dynamicBody; // Sets type of Body to Dynamic (can move / be moved)
  bodyDef.userData = this->creatureData;
  bodyDef.position.Set(posX, feetPosY+sizeY/2);
  
  // Creates Body in the World (Box2D)
  this->body = gc->getWorld()->CreateBody(&bodyDef);
  this->body->SetFixedRotation(true); // Body always stands straight (no rotation through Box2D)
  
  // Fixure (Box2D)
  b2PolygonShape hitBox;
  hitBox.SetAsBox(sizeX/2, sizeY/2); // Sets the hitbox with halfsizes
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &hitBox;
  fixtureDef.density = 1.0f; // Density of water, and because a human is almost water, also of a human
  fixtureDef.friction = 1;
  this->body->CreateFixture(&fixtureDef);
  
  
  hitBox.SetAsBox(0.08, 0.1, b2Vec2(0,-(sizeY/2)), 0);
  fixtureDef.isSensor = true;
  this->footSensorData = new SensorData("foot_sensor");
  fixtureDef.userData = this->footSensorData;
  this->footSensorFixture = this->body->CreateFixture(&fixtureDef);
  
  
  // Sets the Render Object
  this->renderObj.setOrigin(sizeX/2, sizeY/2); // Sets Position to the center of the render object
  this->renderObj.setPosition(posX, feetPosY-sizeY/2);
  this->renderObj.setSize(sf::Vector2f(sizeX, sizeY));
  this->renderObj.setFillColor(sf::Color::Red);
}



//@{
/////////////////////////////////////////////
/// @brief Getter
/////////////////////////////////////////////

b2Vec2 Creature::getPos() 
{
  return this->body->GetPosition();
}

float Creature::getMinX() 
{
  return this->getPos().x - this->getSize().x/2;
}

float Creature::getMaxX() 
{
  return this->getPos().x + this->getSize().x/2;
}

float Creature::getMinY() 
{
  return this->getPos().y - this->getSize().y/2;
}

float Creature::getMaxY() 
{
  return this->getPos().y + this->getSize().y/2;
}

b2Vec2 Creature::getSize()
{
  return ((b2PolygonShape*) this->body->GetFixtureList()->GetShape())->m_vertices[0];
}

b2Vec2 Creature::getHalfSize() 
{
  b2Vec2 tempVector;
  tempVector.x = this->getSize().x / 2;
  tempVector.y = this->getSize().y / 2;
  return tempVector;
}

sf::RectangleShape Creature::getShape() 
{
  return this->renderObj;
}

b2Body* Creature::getBody()
{
  return this->body;
}

bool Creature::isOnGround() {
  if (this->footSensorData->contactCount > 0)
    return true;
  else
    return false;
}
//@}



//@{
/////////////////////////////////////////////
/// @brief Setter
/////////////////////////////////////////////

void Creature::setPos(float x, float y) 
{
  /* b2Vec2 newPos(x,y);
   this->body->SetTransform(newPos,this->body->GetAngle());
   */}

void Creature::setPos(string side, float value) 
{
  /*if (side == "x") {
   this->setPos(value, this->getPos().y);
   } else if (side == "y") {
   this->setPos(this->getPos().x, value);
   }*/
}


void Creature::setSize(float x, float y) 
{
  //this->size.x = x;
  //this->size.y = y;
}

void Creature::setSize(string side, float value) 
{
  /*if (side == "x") {
   this->size.x = value;
   } else if (side == "y") {
   this->size.y = value;
   }*/
}
//@}