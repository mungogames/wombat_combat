//
//  Camera.h
//  notld_pt
//
//  Created by Simon Jentsch on 15.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef notld_pt_Camera_h
#define notld_pt_Camera_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Box2d/Box2d.h>
#include "GameContainer.h"
#include "Player.h"

class Camera {

private:
  sf::Vector2f center;
  sf::Vector2f size;
  GameContainer* gc;
  Player* player;
  
public:  
  Camera (GameContainer* gc, Player* player, sf::Vector2f center, sf::Vector2f size);
  void update ();
};


#endif
