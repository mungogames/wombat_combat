/////////////////////////////////////////////
/// @brief PolyBox class
/// Creates a dynamic or static box, that can be defined by
/// a Polygon via the edge points.
///
/// @author Simon K
/// @author Simon J
/// @date 03/17/2012 - 03/21/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

#ifndef wombatcombat_DynBox_h
#define wombatcombat_DynBox_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>

#include "GameContainer.h"

class PolyBox
{
	private:
  GameContainer* gc;
	int pointCount;

	b2Vec2* chainVertices;
	b2PolygonShape* polygon;
	sf::ConvexShape* renderObj;

	b2BodyDef* bodyDef;
	b2Body* body;

	public:
  PolyBox (GameContainer* gc, int pointCount, float posX, float posY);
	PolyBox (GameContainer* gc, int pointCount, float posX, float posY, b2BodyType type);
	void Constructor (GameContainer* gc, int pointCount, float posX, float posY, b2BodyType type);
  void addPoint(int Index, float x, float y);
	void generate();
  
  // Setter
  void setColor(sf::Color color);
  
	void update();
	void render();
};

#endif /* wombatcombat_DynBox_h */
