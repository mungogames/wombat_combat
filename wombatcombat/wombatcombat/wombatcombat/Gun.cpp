/////////////////////////////////////////////
/// @brief Gun class
/// Gun that can shoot Arrows, has an attack power and
/// can be rotated by the position of the cursor
///
/// @author Simon J
/// @date 03/18/2012 - 03/19/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////


#define pi 3.14159265

#include "Gun.h"
#include "enums.h"
#include <iostream>


/////////////////////////////////////////////
/// @brief Constructor
///
/// @param gc             Reference to the game container
/// @param creatureData   Reference to the creature data
/// @param playerBody     Reference to the player body
/// @param attackPower    Attackpower of the weapon
/// @param shootSpeed     Speed of the Arrow
/////////////////////////////////////////////

Gun::Gun (GameContainer* gc, CreatureData* creatureData, b2Body* playerBody, int attackPower, float shootSpeed)
{
  this->gc = gc;
  this->mousePressReady = true;
  
  this->creatureData = creatureData;
  this->playerBody = playerBody;
  
  this->attackPower = attackPower;
  this->shootSpeed = shootSpeed;
  
  this->gunSize = b2Vec2(0.5, 0.2);
  
    this->weaponOffset = (this->creatureData->hitboxSize.x / 2);

  b2Vec2 playerPos = this->playerBody->GetPosition();
  
  this->renderObj = new sf::RectangleShape();
  this->renderObj->setPosition(sf::Vector2f( + this->weaponOffset, -playerPos.y));
  this->renderObj->setOrigin(0, this->gunSize.y/2);
  this->renderObj->setSize(sf::Vector2f(this->gunSize.x, this->gunSize.y));
}



/////////////////////////////////////////////
/// @brief Initiates an Attack
///
/// Overrides the attack() method of the base class.
/// Shoots an arrow.
/////////////////////////////////////////////

void Gun::attack()
{  
  this->mousePressReady = false;
  this->arrows.push_back(new Arrow(this->gc, 10, this->shootSpeed, this->arrowEmitter, radiant));
}



/////////////////////////////////////////////
/// @brief Updates the player
///
/// Updates all different values (especially of the rendering update)
/// like the current rotation of the gun or updating it's arrows
/////////////////////////////////////////////

void Gun::update()
{

  // Defines the new angle of the gun
  float weaponOffset;
  if (this->creatureData->lookingDirection == LEFT) {
    this->renderObj->setOrigin(this->gunSize.x, this->gunSize.y/2); // Sets the origin to the right edge of the gun
    this->anglePrefix = 180; // angle is positive
  } else {
    this->renderObj->setOrigin(0, this->gunSize.y/2); // Sets the origin to the left edge of the gun
    this->anglePrefix = 0; // angle is negative
  }

  // Sets the position on the render object
  this->renderObj->setPosition(this->playerBody->GetPosition().x + weaponOffset, -this->playerBody->GetPosition().y);
  
  // Defines the current mouse position
  sf::RenderWindow* window = this->gc->getWindow();
  sf::Vector2i mousePos = sf::Mouse::getPosition(*window); // current mouse position
  
  
  // Get and calculate the difference between the player and the mouse
  sf::Vector2f playerOnScreen = this->gc->getPlayerOnScreen();
  

  b2Vec2 mouseDiff = b2Vec2(playerOnScreen.x - mousePos.x, playerOnScreen.y - mousePos.y);
  // Calculate the angle between the mouse and the player
    
  this->radiant = pi - atan2(mouseDiff.y, mouseDiff.x);
  float angle = this->radiant * (180/pi);
  
  // Rotate the render object
  this->renderObj->setRotation((this->anglePrefix + angle) * (-1));
 
  // Updates the Position of the Arrow Emitter (Depending on the angle of the player to the cursor)
  this->arrowEmitter.x = this->playerBody->GetPosition().x + cos(this->radiant) * this->weaponOffset * 3;
  this->arrowEmitter.y = this->playerBody->GetPosition().y + sin(this->radiant) * this->weaponOffset * 3;
  
  
  
  
  
  // Attack on mousepress if ready (only one attack per click)
  if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
  {
    if (this->mousePressReady)
      this->attack();
  } else
    this->mousePressReady = true;

  
  // Updates all Arrows
  for (int i = 0 ; i < this->arrows.size() ; i++)
  {
    this->arrows.at(i)->update();
    if (this->arrows.at(i)->getLivingPos() >= 100) 
    {
      delete this->arrows.at(i);
      this->arrows.erase(this->arrows.begin()+i);
      i--;
    }
  }
  
}



/////////////////////////////////////////////
/// @brief Renders the object
///
/// Draws the render object and renders every arrow that was shot
/////////////////////////////////////////////

void Gun::render()
{
  this->gc->getWindow()->draw(*renderObj);
  // Render all Arrows
  for (int i = 0 ; i < arrows.size() ; i++)
    arrows.at(i)->render();
}
