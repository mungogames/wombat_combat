//
//  ControlHandler.h
//  movement_cpp
//
//  Created by Simon Jentsch on 06.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef movement_cpp_ControlHandler_h
#define movement_cpp_ControlHandler_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"

class ControlHandler {
private:
  static bool jumpReady;
  
public:
  static void player (Player* player, sf::Keyboard::Key moveRight, sf::Keyboard::Key moveLeft, sf::Keyboard::Key runToggler, sf::Keyboard::Key jumpToggler);

  
  
};

#endif
