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

#ifndef notld_pt_Camera_h
#define notld_pt_Camera_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Box2D/Box2D.h>
#include "GameContainer.h"
#include "Player.h"

class Camera {

private:
  
  // Private attributes
  sf::Vector2f center;
  sf::Vector2f size;
  GameContainer* gc;
  Player* player;
  
  float currentZoom;
  float walkingZoom;
  float runningZoom;
  float zoomSpeed;
  
public:  
  Camera (GameContainer* gc, Player* player, sf::Vector2f center, sf::Vector2f size);
  void update ();
};


#endif
