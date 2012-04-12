/////////////////////////////////////////////
/// @brief Base Game Class
/// Basic loop with an update and a render method to make the
/// source code clearer
/// 
/// @author Simon J
/// @author Simon K
/// @date 03/05/2012 - 03/19/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

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

	this->boulder = new PolyBox(gc, 8, 3, 3);
	  	this->boulder->addPoint(0,0,0);
	  	this->boulder->addPoint(1,-2,0);
	  	this->boulder->addPoint(2,-3,-1);
	  	this->boulder->addPoint(3,-3,-3);
	  	this->boulder->addPoint(4,-2,-4);
	  	this->boulder->addPoint(5,0,-4);
	  	this->boulder->addPoint(6,1,-3);
	  	this->boulder->addPoint(7,1,-1);

	this->box1 = new PolyBox(gc, 4,23, 0);
	  	this->box1->addPoint(0,1,0);
	  	this->box1->addPoint(1,0,0);
	  	this->box1->addPoint(2,0,-1);
	  	this->box1->addPoint(3,1,-1);

	this->box2 = new PolyBox(gc, 4,23, 1);
	  	this->box2->addPoint(0,1,0);
	  	this->box2->addPoint(1,0,0);
	  	this->box2->addPoint(2,0,-1);
	  	this->box2->addPoint(3,1,-1);

	this->box3 = new PolyBox(gc, 4,23, 2);
	  	this->box3->addPoint(0,1,0);
	  	this->box3->addPoint(1,0,0);
	  	this->box3->addPoint(2,0,-1);
	  	this->box3->addPoint(3,1,-1);

	this->platform1 = new PolyBox(gc, 4,37, -23, b2_staticBody);
      this->platform1->setColor(sf::Color::Yellow);
	  	this->platform1->addPoint(0,0,0);
	  	this->platform1->addPoint(1,-5,0);
	  	this->platform1->addPoint(2,-5,-1);
	  	this->platform1->addPoint(3,0,-1);

	this->platform2 = new PolyBox(gc, 4,52, -47, b2_staticBody);
      this->platform2->setColor(sf::Color::Yellow);
	  	this->platform2->addPoint(0,0,0);
	  	this->platform2->addPoint(1,-5,0);
	  	this->platform2->addPoint(2,-5,-1);
	  	this->platform2->addPoint(3,0,-1);

	this->platform3 = new PolyBox(gc, 4,37, -67, b2_staticBody);
      this->platform3->setColor(sf::Color::Yellow);
	  	this->platform3->addPoint(0,0,0);
	  	this->platform3->addPoint(1,-5,0);
	  	this->platform3->addPoint(2,-5,-1);
	  	this->platform3->addPoint(3,0,-1);

  	this->boulder->generate();
  	this->box1->generate();
  	this->box2->generate();
  	this->box3->generate();
  	this->platform1->generate();
  	this->platform2->generate();
  	this->platform3->generate();
  	this->entry->generate();
}

// Update everything
void BaseGame::update()
{

  this->player->update();
  this->camera->update();
  this->boulder->update();
  this->box1->update();
  this->box2->update();
  this->box3->update();
}

// Render everything
void BaseGame::render()
{

  /*
  for(int i = 0 ; i < this->platforms.size() ; i++)
    this->platforms.at(i)->render(this->gc->getWindow());
  */
  this->player->render();
  this->boulder->render();
  this->box1->render();
  this->box2->render();
  this->box3->render();
  this->platform1->render();
  this->platform2->render();
  this->platform3->render();
  this->entry->render(this->gc);
}
