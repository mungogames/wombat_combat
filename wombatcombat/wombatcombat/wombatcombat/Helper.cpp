/////////////////////////////////////////////
/// @brief Helper class
/// A set of helpful functions like vector2f
///
/// @author Simon J
/// @date 03/27/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

#include <iostream>
#include "Helper.h"
#include "structs.h"



/////////////////////////////////////////////
/// @brief Vector2f object for Box2D and SFML
///
/// A simple container method that inhabits a struct.
/// Sets the vector2f values for Box2D and SFML (with negativ y-axis)
///
/// @param x,y     Coordinates of the Vector
/////////////////////////////////////////////

vectorf Helper::vector2f(float x, float y)
{
  vectorf output;
  output.sfml = sf::Vector2f(x,-y);
  output.box2d = b2Vec2(x,y);
  return output;
}