/////////////////////////////////////////////
/// @brief Player class
///
/// @author Simon
/// @version 0.2
/// @date 2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////




#include "Player.h"
#include "ControlHandler.h"
#include <iostream>

/////////////////////////////////////////////
/// @brief Constructor
//
/// @param gc             Reference to the GameContainer
/// @param posX,feetPosY  Position of the player, Y-pos describes lower edge of the hitbox
/// @param sizex,sizeY    Size of the hitbox in two directions
/////////////////////////////////////////////

Player::Player(GameContainer* gc, float posX, float feetPosY, float sizeX, float sizeY) 
: Creature(gc, posX, feetPosY, sizeX, sizeY)
{    
  this->gc = gc;
  
  this->movingSpeed = 6;
  this->runningSpeed = 15;
  this->jumpSpeed = 5;
  this->running = false;
  
  this->movingDirection = NONE;
  
  this->creatureData->name = "Gaylord";
  this->creatureData->hitboxSize = b2Vec2(sizeX, sizeY);
  
  this->weapon = new Gun(this->creatureData, this->body, 10, 10);
  
}


//@{
/////////////////////////////////////////////
/// @brief Getter
/////////////////////////////////////////////

Direction Player::getMovingDirection() 
{
  return this->movingDirection;
}

float Player::getJumpSpeed() 
{
  return this->jumpSpeed;
}

bool Player::isRunning()
{
  return this->running;
}

bool Player::isMoving()
{
  return (this->movingDirection == RIGHT || this->movingDirection == LEFT);
}
//@}


//@{
/////////////////////////////////////////////
/// @brief Setter
/////////////////////////////////////////////

void Player::setJumpSpeed(float jumpSpeed)
{
  this->jumpSpeed = jumpSpeed;
}

void Player::stopMoving()
{
  this->movingDirection = NONE;
  this->body->GetFixtureList()->SetFriction(1);
}

void Player::setRunning(bool running) 
{
  this->running = running;
}
//@}



/////////////////////////////////////////////
/// @brief Moves the player in the defined direction
///
/// Speed is defined depending on whether the player is walking,
/// running or sticking on a wall
///
/// @param gc             Reference to the GameContainer
/////////////////////////////////////////////

void Player::move(Direction direction) 
{
  this->movingDirection = direction;
  this->body->GetFixtureList()->SetFriction(0);
}



/////////////////////////////////////////////
/// @brief Let the player jump
///
/// Player can only jump if he is on the ground (no jump mid-air)
/// Jump force is defined with the mass of the player
/////////////////////////////////////////////

void Player::jump() 
{
  if (this->isOnGround())
  {
    //to change velocity by 10
    float impulse = this->body->GetMass() * this->jumpSpeed;
    this->body->ApplyLinearImpulse( b2Vec2(0,impulse), body->GetWorldCenter() );
  }
}



/////////////////////////////////////////////
/// @brief Updates the player
///
/// Updates all different values (especially of the rendering update)
/// like input, looking direction depending on the mouse position,
/// moving depending on the speed of the player (walking, running, ...)
/////////////////////////////////////////////

void Player::update()
{
  
  // Looking Direction BEGIN
  if (gc->getMouseSide() == NONE)
    this->creatureData->lookingDirection = this->creatureData->lookingDirection;
  else
    this->creatureData->lookingDirection = gc->getMouseSide();
  // Looking Direction END
  
  
  // Player Control BEGIN
  ControlHandler::player(this, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::LShift, sf::Keyboard::Space);
  // Player Control END
  
  // Update Moving BEGIN
  b2Vec2 vel = this->body->GetLinearVelocity();
  float speed;  
  if (!this->isOnGround() && vel.x == 0)
    speed = 0;
  else if (this->running)
    speed = this->runningSpeed;
  else
    speed = this->movingSpeed;
  
  float desiredVel;
  switch ( this->movingDirection )
  {
    case LEFT:  desiredVel = max( vel.x - 0.8f, -speed); break;
    case RIGHT: desiredVel = b2Min( vel.x + 0.8f, speed); break;
    default: desiredVel = vel.x * 0.98f; break;
  }
  float velChange = desiredVel - vel.x;
  float impulse = body->GetMass() * velChange;
  this->body->ApplyLinearImpulse( b2Vec2(impulse,0), this->body->GetWorldCenter() );
  // Update Moving END
  
  
  
  // Update Render Position
  this->renderObj.setPosition(this->getPos().x, -this->getPos().y);
  this->weapon->update(gc);

}



/////////////////////////////////////////////
/// @brief Renders the object
///
/// Draws the render object and calls the render method of the weapon
/////////////////////////////////////////////

void Player::render()
{
  gc->getWindow()->draw(renderObj);
  this->weapon->render(this->gc);
}

