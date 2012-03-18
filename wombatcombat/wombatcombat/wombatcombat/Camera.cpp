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
  
  this->currentZoom = 1;
  this->walkingZoom = 1;
  this->runningZoom = 1.4;
  this->zoomSpeed = 0.001;
  
  //View
  gc->setView(sf::View(center,size));  
  
}

void Camera::update()
{
  // X-Axis
  float viewportPosX = gc->view.getCenter().x - (gc->view.getSize().x/2);
  float goldenRatioX = (gc->view.getSize().x / 3);
  
  // Y-Axis
  float viewportPosY = gc->view.getCenter().y - (gc->view.getSize().y/2);
  float goldenRatioY = (gc->view.getSize().y / 4);
  
  // Positionate Camera X-Axis
  if (player->getPos().x < viewportPosX+goldenRatioX) {
    this->gc->view.move(player->getPos().x - (viewportPosX+goldenRatioX), 0);
  } else if (this->player->getPos().x > viewportPosX+goldenRatioX*2) {
    this->gc->view.move((player->getPos().x - (viewportPosX+goldenRatioX*2)), 0);
  }
  
  // Positionate Camera Y-Axis
  if (player->getPos().y != viewportPosY+goldenRatioY*3) 
    this->gc->view.move(0, - player->getPos().y - (viewportPosY+goldenRatioY*3));
    
  
  
  if (this->player->isMoving() && this->player->isRunning() && this->currentZoom < this->runningZoom)
  {
    this->currentZoom += this->zoomSpeed;
    this->gc->view.zoom(1+this->zoomSpeed);
  } 
  else if (this->currentZoom > this->walkingZoom)
  {
    this->currentZoom -= this->zoomSpeed;
    this->gc->view.zoom(1-this->zoomSpeed); 
  }
  
  sf::Vector2f playerOnScreen = sf::Vector2f();
  playerOnScreen.x = (this->player->getBody()->GetPosition().x - gc->getViewEdges().x) / gc->view.getSize().x * 100;
  playerOnScreen.y = -(this->player->getBody()->GetPosition().y + gc->getViewEdges().y) / gc->view.getSize().y * 100;
  
  this->gc->setPlayerOnScreen(playerOnScreen);
  

}