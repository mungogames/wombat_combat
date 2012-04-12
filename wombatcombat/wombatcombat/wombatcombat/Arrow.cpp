/////////////////////////////////////////////
/// @brief Arrow class
/// Arrow that can be shot and follows the physics
/// 
/// @author Simon J
/// @date 03/18/2012 - 03/19/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

#include "Arrow.h"
#include "structs.h"
#include <iostream>

#define pi 3.14159265



/////////////////////////////////////////////
/// @brief Constructor
///
/// @param gc             Reference to the game container
/// @param damage         damage that the arrow gives to an entity
/// @param speed          x and y -axis speed of the arrow
/// @param pos            x and y -position of the arrow
/// @param side           direction to which the arrow flies
/////////////////////////////////////////////

Arrow::Arrow (GameContainer* gc, int damage, float shootSpeed, b2Vec2 pos, double radiant)
{
  
  float angle = radiant * (180/pi);
  
  cout << angle << endl;
    
  // Living Time defines the time in seconds until the arrow will be destroyed 
  // (relative to its creation)
  this->livingTime = 5;
  
  this->gc = gc;
    
  this->damage = damage;
  
  // Define the of the Arrow (sidePrefix changes wheather shooting left or right)
  this->speed.x =  cos(radiant) * shootSpeed;
  this->speed.y =  sin(radiant) * shootSpeed;
  
    
  this->arrowSensorData = new SensorData("arrow_sensor");
 
  // Body Definition (Box2D)
  b2BodyDef bodyDef; // Generates a new body definition which contains values of the Body
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(pos.x, pos.y);
  bodyDef.angle = radiant;
  
  // Creates Body in the World (Box2D)
  this->body = gc->getWorld()->CreateBody(&bodyDef);
  
  // Fixure (Box2D)
  b2PolygonShape arrowShape;
  arrowShape.SetAsBox(0.25, 0.05, b2Vec2(0,0), 0); // Sets the Arrow with halfsizes
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &arrowShape;
  fixtureDef.density = 0.67;
  fixtureDef.friction = 0.6;
  fixtureDef.userData = this->arrowSensorData;
  this->body->CreateFixture(&fixtureDef);
  
  // Sets the Render Object
  this->renderObj.setOrigin(0.25, 0.05); // Sets Position to the center of the render object
  this->renderObj.setPosition(pos.x, -pos.y);
  this->renderObj.setSize(sf::Vector2f(0.5, 0.1));
  this->renderObj.setFillColor(sf::Color::Cyan);
 
  this->body->ApplyLinearImpulse(this->speed, this->body->GetWorldCenter());
}



/////////////////////////////////////////////
/// @brief Deconstructor
///
/// Deletes every object that is referenced in the arrow object
/////////////////////////////////////////////

Arrow::~Arrow()
{
  this->body->DestroyFixture(this->body->GetFixtureList());
  this->gc->getWorld()->DestroyBody(this->body);
  delete this->arrowSensorData;
}



//@{
/////////////////////////////////////////////
/// @brief Getter
/////////////////////////////////////////////

b2Body* Arrow::getBody()
{
  return this->body;
}



/////////////////////////////////////////////
/// @brief Gets the lifetime position
///
/// Get the position of the livetime relative to the end of live
/// in percentage
/////////////////////////////////////////////

float Arrow::getLivingPos()
{
  
  float curTime = this->timer.getElapsedTime().asSeconds();
  return curTime / this->livingTime * 100;
}
/// @}



/////////////////////////////////////////////
/// @brief Updates the player
///
/// Updates all different values (especially of the rendering update)
/// like the current rotation and the position (from Box2D)
/////////////////////////////////////////////

void Arrow::update()
{
  float angle = this->body->GetAngle();
  
  this->renderObj.setPosition(this->body->GetPosition().x, -this->body->GetPosition().y);
  this->renderObj.setRotation(-(angle * (180/pi)));

} 



/////////////////////////////////////////////
/// @brief Renders the object
///
/// Draws the render object
/////////////////////////////////////////////

void Arrow::render()
{
  this->gc->getWindow()->draw(this->renderObj);
}
