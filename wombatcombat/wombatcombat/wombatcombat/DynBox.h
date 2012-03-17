/* Rock.h
 *
 *  Created on: 17.03.2012
 *      Author: sk
 */

#ifndef wombatcombat_DynBox_h
#define wombatcombat_DynBox_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>

#include "GameContainer.h"

class DynOrb
{
	private:
	int pointCount;

	b2Vec2* chainVertices;
	b2PolygonShape* polygon;
	sf::ConvexShape* renderObj;

	b2BodyDef* bodyDef;
	b2Body* body;

	public:
	DynOrb (GameContainer* gc, int pointCount, float posX, float posY);
	void addPoint(int Index, float x, float y);
	void generate();
	void update(GameContainer* gc);
	void render(GameContainer* gc);
};

#endif /* wombatcombat_DynBox_h */
