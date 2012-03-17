//  GameContainer.cpp
//  wombatcombat
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MungoGames__. All rights reserved.
//

#include <iostream>
#include "GameContainer.h"

GameContainer::GameContainer(sf::RenderWindow* window, b2World* world)
{
  this->window = window;
  this->world = world;
  this->cameraSpeed = 0.005f;
}


// Getter
sf::RenderWindow* GameContainer::getWindow()
{
  return this->window;
}

b2World* GameContainer::getWorld()
{
  return this->world;
}

float GameContainer::getViewCenterX()
{
  return this->view.getCenter().x;
}

// Setter
void GameContainer::setWindow(sf::RenderWindow* window)
{
  this->window = window;
}

void GameContainer::setView(sf::View view) {
  this->view = view;
  this->window->setView(this->view);
}

void GameContainer::setViewCenterX(float x) 
{
  this->view.setCenter(x, this->view.getCenter().y);
  this->window->setView(this->view);
}
