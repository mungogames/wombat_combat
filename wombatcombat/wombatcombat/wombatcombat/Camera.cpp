/////////////////////////////////////////////
/// @brief Camera class
/// Camera that can move relative to the player, zooming depending on 
/// the movement speed or defining the position of the player on the screen
///
/// @author Simon J
/// @date 03/15/2012 - 03/18/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////



#include <iostream>
#include "Camera.h"

/////////////////////////////////////////////
/// @brief Constructor
//
/// @param gc             Reference to the GameContainer
/// @param player         Reference to the Player (to interact with him)
/// @param center         Center of the viewport (in meters)
/// @param size           Size of the viewport (in meters)
/////////////////////////////////////////////

Camera::Camera (GameContainer* gc, Player* player, sf::Vector2f center, sf::Vector2f size) 
{
  // Parameter to Attribute
  this->gc = gc;
  this->player = player;
  this->center = center;
  this->size = size;
  
  // Static values
  this->currentZoom = 1.0f;
  this->walkingZoom = 1.0f;
  this->runningZoom = 1.4f;
  this->zoomSpeed = 0.001;
  
  //View
  gc->setView(sf::View(center,size));  
  
}



/////////////////////////////////////////////
/// @brief Updates the camera
///
/// Updates all different values (especially of the rendering object)
/// like camera positioning, zooming and defining the position of the 
/// player on the screen (in percent)
/////////////////////////////////////////////

void Camera::update()
{
  // X-Axis
  float viewportPosX = gc->view.getCenter().x - (gc->view.getSize().x / 2);
  float goldenRatioX = (gc->view.getSize().x / 3);
  
  // Y-Axis
  float viewportPosY = gc->view.getCenter().y - (gc->view.getSize().y / 2);
  float goldenRatioY = (gc->view.getSize().y / 4);
  
  
  
  // Positionate Camera X-Axis when the player is on the left or right side of the screen
  if (player->getPos().x < viewportPosX+goldenRatioX)
    this->gc->view.move(player->getPos().x - (viewportPosX+goldenRatioX), 0);
  else if (this->player->getPos().x > viewportPosX+goldenRatioX * 2)
    this->gc->view.move((player->getPos().x - (viewportPosX+goldenRatioX * 2)), 0);
  
  // Positionate Camera Y-Axis with a fixed position to the player
  if (player->getPos().y != viewportPosY+goldenRatioY*3) 
    this->gc->view.move(0, - player->getPos().y - (viewportPosY+goldenRatioY*3));
    
  
  
  // Zooming depending on the moving speed
  if (this->player->isMoving() && this->player->isRunning() && this->currentZoom <= this->runningZoom)
  {
    this->currentZoom += this->zoomSpeed * gc->getDelta().asMilliseconds();
    this->gc->view.zoom(1+this->zoomSpeed * gc->getDelta().asMilliseconds());
  } 
  else if (this->player->isMoving() && !this->player->isRunning() && this->currentZoom >= this->walkingZoom)
  {
    this->currentZoom -= this->zoomSpeed * gc->getDelta().asMilliseconds();
    this->gc->view.zoom(1-this->zoomSpeed * gc->getDelta().asMilliseconds()); 
  }
  else if (!this->player->isMoving() && this->currentZoom >= this->walkingZoom)
  {
    this->currentZoom -= this->zoomSpeed * gc->getDelta().asMilliseconds();
    this->gc->view.zoom(1-this->zoomSpeed * gc->getDelta().asMilliseconds()); 
  }
  
  
  
  //Defining the position of the player on the screen (in percent)
  sf::Vector2f playerOnScreen = sf::Vector2f();
  playerOnScreen.x = (this->player->getBody()->GetPosition().x - gc->getViewEdges().x) / gc->view.getSize().x * 100;
  playerOnScreen.y = -(this->player->getBody()->GetPosition().y + gc->getViewEdges().y) / gc->view.getSize().y * 100;
  this->gc->setPlayerOnScreen(playerOnScreen);
  

}