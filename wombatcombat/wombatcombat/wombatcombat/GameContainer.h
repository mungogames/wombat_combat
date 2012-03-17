//  GameContainer.h
//  wombatcombat
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MungoGames__. All rights reserved.
//

#ifndef wombatcombat_GameContainer_h
#define wombatcombat_GameContainer_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Box2D/Box2D.h>

class GameContainer {
  
private:
  sf::RenderWindow* window;
  b2World* world;
  
public:
  sf::View view;
  
public:
  GameContainer(sf::RenderWindow* window, b2World* world);
  
  
  // Getter
  sf::RenderWindow* getWindow();
  b2World* getWorld();
  float getViewCenterX();
  
  // Setter
  void setWindow(sf::RenderWindow* window);
  void setView(sf::View view);
  void setViewCenterX(float x);
  
};

#endif
