//
//  Camera.cpp
//  notld_pt
//
//  Created by Simon Jentsch on 15.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Camera.h"

Camera::Camera (GameContainer* gc, Player* player, sf::Vector2f center, sf::Vector2f size) 
{
  this->gc = gc;
  this->player = player;
  this->center = center;
  this->size = size;
  
  //View
  gc->setView(sf::View(center,size));  
  
}

void Camera::update()
{
  float viewportPosX = gc->view.getCenter().x - (gc->view.getSize().x/2);
  float goldenRatioX = (gc->view.getSize().x / 3);
  
  float viewportPosY = gc->view.getCenter().y - (gc->view.getSize().y/2);
  float goldenRatioY = (gc->view.getSize().y / 4);
  
  if (player->getPos().x < viewportPosX+goldenRatioX) {
    gc->view.move(player->getPos().x - (viewportPosX+goldenRatioX), 0);
  } else if (this->player->getPos().x > viewportPosX+goldenRatioX*2) {
    gc->view.move((player->getPos().x - (viewportPosX+goldenRatioX*2)), 0);
  }
  
  if (player->getPos().y != viewportPosY+goldenRatioY*3) 
    gc->view.move(0, - player->getPos().y - (viewportPosY+goldenRatioY*3));
    
  /*
  if (player->getPos().y < viewportPosY+goldenRatioY) {
    gc->view.Move(0, player->getPos().y - (viewportPosY+goldenRatioY*3));
  } else if (this->player->getPos().y > viewportPosY+goldenRatioY*3) {
    gc->view.Move(0, (player->getPos().y - (viewportPosY+goldenRatioY*3)));
  }
  */

}