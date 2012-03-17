//
//  GameLoop.cpp
//  movement_cpp
//
//  Created by Simon Jentsch on 05.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "BaseGame.h"
#include <iostream>

BaseGame::BaseGame(GameContainer* gc) 
{
	this->gc = gc;
  
	float windowRatio = (float)gc->getWindow()->getSize().y / (float)gc->getWindow()->getSize().x;
	this->player = new Player(gc, 60, 10, 0.4f, 1.8f);
	this->camera = new Camera(gc, this->player, sf::Vector2f(4, -3), sf::Vector2f(30, 30*windowRatio));

	this->terrain = new Terrain(gc, 7, 0, 0);
  this->terrain->addPoint(0, 40, 50);
  this->terrain->addPoint(1, 50, 0);
  this->terrain->addPoint(2, 90, 5);
  this->terrain->addPoint(3, 110, 10);
  this->terrain->addPoint(4, 120, 50);
  this->terrain->addPoint(5, 200, 45);
  this->terrain->addPoint(6, 250, 55);

  this->terrain->generate();
}

// Update everything
void BaseGame::update() 
{
  
  this->player->update(gc);
  this->camera->update();  
  
}


// Render everything
void BaseGame::render() 
{
  
  /*
  for(int i = 0 ; i < this->platforms.size() ; i++)
    this->platforms.at(i)->render(this->gc->getWindow());
  */
  this->player->render(this->gc);
  this->terrain->render(this->gc);
  
  
  
}
