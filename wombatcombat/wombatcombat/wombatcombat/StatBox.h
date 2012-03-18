/* Rock.h
 *
 *  Created on: 17.03.2012
 *      Author: sk
 */

#ifndef wombatcombat_StatBox_h
#define wombatcombat_StatBox_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>

#include "GameContainer.h"

class StatBox
{
	private:
	int pointCount;

	b2Vec2* chainVertices;
	b2PolygonShape* polygon;
	sf::ConvexShape* renderObj;

	b2BodyDef* bodyDef;
	b2Body* body;

	public:
	StatBox (GameContainer* gc, int pointCount, float posX, float posY);
	void addPoint(int Index, float x, float y);
	void generate();
	void render(GameContainer* gc);
};

#endif /* wombatcombat_StatBox_h */
