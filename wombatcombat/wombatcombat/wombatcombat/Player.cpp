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
  this->movingSpeed = 6;
  this->runningSpeed = 15;
  this->jumpSpeed = 5;
  this->running = false;
  
  this->movingDirection = NONE;
  
  this->creatureData->name = "Gaylord";
  this->creatureData->hitboxSize = b2Vec2(sizeX, sizeY);
  
  this->weapon = new Gun(this->creatureData, this->body, 10, 10);
  
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
  if (this->isOnGround()) {
    this->movingDirection = direction;
    this->body->GetFixtureList()->SetFriction(0);
  }
}

void Player::stopMoving()
{
  this->movingDirection = NONE;
  this->body->GetFixtureList()->SetFriction(1);
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
  if (this->isOnGround())
  {
    float speed;
    if (this->running)
      speed = this->runningSpeed;
    else
      speed = this->movingSpeed;
    
    cout << this->body->GetMass() << endl;
    
    b2Vec2 vel = this->body->GetLinearVelocity();
    float desiredVel;
    switch ( this->movingDirection )
    {
      case LEFT:  desiredVel = max( vel.x - 0.8f, -speed); break;
      case RIGHT: desiredVel = b2Min( vel.x + 0.8f, speed ); break;
      default: desiredVel = vel.x * 0.98f; break;
    }
    float velChange = desiredVel - vel.x;
    float impulse = body->GetMass() * velChange;
    this->body->ApplyLinearImpulse( b2Vec2(impulse,0), this->body->GetWorldCenter() );
  }
  // Update Moving END
  
  
  
  // Update Render Position
  this->renderObj.setPosition(this->getPos().x, -this->getPos().y);
  this->weapon->update(gc);

}

void Player::render(GameContainer* gc)
{
  gc->getWindow()->draw(renderObj);
  this->weapon->render(gc);
}

