//
//  Bow.cpp
//  wombatcombat
//
//  Created by Simon Jentsch on 17.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#define pi 3.14159265

#include "Gun.h"
#include <iostream>
#include "enums.h"

Gun::Gun (CreatureData* creatureData, b2Body* playerBody, int attackPower, float shootSpeed)
{
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

void Gun::attack()
{
  
}

void Gun::update(GameContainer* gc)
{
    
  float weaponOffset;
  float anglePrefix;
  if (this->creatureData->lookingDirection == LEFT) {
    weaponOffset = -(this->weaponOffset);
    this->renderObj->setOrigin(this->gunSize.x, this->gunSize.y/2);
    anglePrefix = 1;
  } else {
    weaponOffset = this->weaponOffset;
    this->renderObj->setOrigin(0, this->gunSize.y/2);
    anglePrefix = -1;
  }
    
  
  this->renderObj->setPosition(this->playerBody->GetPosition().x + weaponOffset, -this->playerBody->GetPosition().y);
  
  sf::RenderWindow* window = gc->getWindow();
  sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
  
  sf::Vector2f playerOnScreen = gc->getPlayerOnScreen();
  
  b2Vec2 mouseDiff = b2Vec2(playerOnScreen.x - mousePos.x, playerOnScreen.y - mousePos.y);
  
  float hyp = sqrt(pow(mouseDiff.y, 2) + pow(mouseDiff.x, 2));
  
  float radiant = sin(mouseDiff.y / hyp);
  float angle = radiant * (180/pi);
  
  this->renderObj->setRotation(anglePrefix * angle);
  
  if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
  {
    if (this->mousePressReady)
    {
      this->mousePressReady = false;
      b2Vec2 newArrowSpeed;
      newArrowSpeed.x = -anglePrefix * cos(radiant)*this->shootSpeed;
      newArrowSpeed.y = sin(radiant)*this->shootSpeed;
      arrows.push_back(new Arrow(gc, 10, newArrowSpeed, b2Vec2(this->playerBody->GetPosition().x + (weaponOffset * 2), this->playerBody->GetPosition().y), this->creatureData->lookingDirection));
    }
  }
  else
  {
    this->mousePressReady = true;
  }
  
  // Updates all Arrows
  for (int i = 0 ; i < this->arrows.size() ; i++)
  {
    this->arrows.at(i)->update();
    if (this->arrows.at(i)->getLivingPos() >= 100) {
      delete this->arrows.at(i);
      this->arrows.erase(this->arrows.begin()+i);
      i--;
    }
  }
    
}




void Gun::render(GameContainer* gc)
{
  gc->getWindow()->draw(*renderObj);
  // Render all Arrows
  for (int i = 0 ; i < arrows.size() ; i++)
  {
    arrows.at(i)->render();
  }
}