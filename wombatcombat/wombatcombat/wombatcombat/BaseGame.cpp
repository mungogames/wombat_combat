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
	this->player = new Player(gc, 7, -7, 0.4f, 1.8f);
	this->camera = new Camera(gc, this->player, sf::Vector2f(4, -3), sf::Vector2f(30, 30*windowRatio));

	this->entry = new Terrain(gc, 17, 0, 0);
		this->entry->addPoint(0, -4, 10);
		this->entry->addPoint(1, 0, 0);
		this->entry->addPoint(2, 6,-4);
		this->entry->addPoint(3, 6,-7);
		this->entry->addPoint(4, 10,-7);
		this->entry->addPoint(5, 10,-11);
		this->entry->addPoint(6, 14.4,-11);
		this->entry->addPoint(7, 14.4,-9);
		this->entry->addPoint(8, 17,-9);
		this->entry->addPoint(9, 18,-9);
		this->entry->addPoint(10, 18,-8.5);
		this->entry->addPoint(11, 19,-8.5);
		this->entry->addPoint(12, 19,-8);
		this->entry->addPoint(13, 25,-8);
		this->entry->addPoint(14, 25,-80);
		this->entry->addPoint(15, 50,-80);
		this->entry->addPoint(16, 55,0);

	this->boulder = new DynBox(gc, 8,3, 3);
	  	this->boulder->addPoint(0,0,0);
	  	this->boulder->addPoint(1,-2,0);
	  	this->boulder->addPoint(2,-3,-1);
	  	this->boulder->addPoint(3,-3,-3);
	  	this->boulder->addPoint(4,-2,-4);
	  	this->boulder->addPoint(5,0,-4);
	  	this->boulder->addPoint(6,1,-3);
	  	this->boulder->addPoint(7,1,-1);

	this->box1 = new DynBox(gc, 4,23, 0);
	  	this->box1->addPoint(0,1,0);
	  	this->box1->addPoint(1,0,0);
	  	this->box1->addPoint(2,0,-1);
	  	this->box1->addPoint(3,1,-1);

	this->box2 = new DynBox(gc, 4,23, 1);
	  	this->box2->addPoint(0,1,0);
	  	this->box2->addPoint(1,0,0);
	  	this->box2->addPoint(2,0,-1);
	  	this->box2->addPoint(3,1,-1);

	this->box3 = new DynBox(gc, 4,23, 2);
	  	this->box3->addPoint(0,1,0);
	  	this->box3->addPoint(1,0,0);
	  	this->box3->addPoint(2,0,-1);
	  	this->box3->addPoint(3,1,-1);

  	this->boulder->generate();
  	this->box1->generate();
  	this->box2->generate();
  	this->box3->generate();
  	this->entry->generate();
}

// Update everything
void BaseGame::update()
{

  this->player->update(gc);
  this->camera->update();
  this->boulder->update(gc);
  this->box1->update(gc);
  this->box2->update(gc);
  this->box3->update(gc);
}

// Render everything
void BaseGame::render()
{

  /*
  for(int i = 0 ; i < this->platforms.size() ; i++)
    this->platforms.at(i)->render(this->gc->getWindow());
  */
  this->player->render(this->gc);
  this->boulder->render(this->gc);
  this->box1->render(this->gc);
  this->box2->render(this->gc);
  this->box3->render(this->gc);
  this->entry->render(this->gc);
}
