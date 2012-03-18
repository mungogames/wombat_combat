//
//  Player.cpp
//  wombatcombat
//
//  Created by Simon Jentsch on 17.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Player.h"
#include "ControlHandler.h"
#include <iostream>

// Constructor

Player::Player(GameContainer* gc, float posX, float feetPosY, float sizeX, float sizeY) 
: Creature(gc, posX, feetPosY, sizeX, sizeY)
{    
  this->movingSpeed = 1.0f;
  this->runningSpeed = 3.5f;
  this->jumpSpeed = 3;
  this->running = false;
  
  this->movingDirection = NONE;
  
  this->creatureData->name = "Gaylord";
  this->creatureData->hitboxSize = b2Vec2(sizeX, sizeY);
  this->creatureData->lookingDirection = NONE;

  this->weapon = new Gun(this->creatureData, this->body, 10, 1.3);
  
}


// Getter

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


// Setter

void Player::setJumpSpeed(float jumpSpeed)
{
  this->jumpSpeed = jumpSpeed;
}

void Player::move(Direction direction) 
{
  this->movingDirection = direction;
}

void Player::stopMoving()
{
  this->movingDirection = NONE;
}

void Player::jump() 
{
  if (this->isOnGround())
  {
    //to change velocity by 10
    float impulse = this->body->GetMass() * this->jumpSpeed;
    this->body->ApplyLinearImpulse( b2Vec2(0,impulse), body->GetWorldCenter() );
  }
}

void Player::setRunning(bool running) 
{
  this->running = running;
}


// Update and render methods
void Player::update(GameContainer* gc)
{
  // Looking Direction
  if (true)
    this->creatureData->lookingDirection = gc->getMouseSide();
  
  // Player Control
  ControlHandler::player(this, sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::RShift, sf::Keyboard::Space);
  // Update Moving
  float speed;
  if (this->running)
    speed = this->runningSpeed;
  else
    speed = this->movingSpeed;
  
  b2Vec2 vel = this->body->GetLinearVelocity();
  float desiredVel;
  switch ( this->movingDirection )
  {
    case LEFT:  desiredVel = max( vel.x - 0.05f, -speed); break;
    case RIGHT: desiredVel = b2Min( vel.x + 0.05f, speed ); break;
    default: desiredVel = vel.x * 0.98f; break;
  }
  float velChange = desiredVel - vel.x;
  float impulse = body->GetMass() * velChange;
  this->body->ApplyLinearImpulse( b2Vec2(impulse,0), this->body->GetWorldCenter() );
  
  
  // Update Render Position
  this->renderObj.setPosition(this->getPos().x, -this->getPos().y);

  this->weapon->update(gc);

}

void Player::render(GameContainer* gc)
{
  gc->getWindow()->draw(renderObj);
  this->weapon->render(gc);
}

