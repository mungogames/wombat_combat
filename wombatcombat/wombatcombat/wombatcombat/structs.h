//
//  structs.h
//  wombatcombat
//
//  Created by Simon Jentsch on 27.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef wombatcombat_structs_h
#define wombatcombat_structs_h

#include <Box2D/Box2D.h>
#include <SFML/System.hpp>

struct vectorf {
  b2Vec2 box2d;
  sf::Vector2f sfml;
};

struct vector2i {
  int x;
  int y;
};

#endif
