/*Rock.cpp
 *
 * 	Created on: 17.03.2012
 * 	Author:sk
 */

#include "Rock.h"

Rock::Rock (GameContainer* gc, int pointCount, float posX, float posY)
{
	//pointCount Konstruktor in lokale Variable legen
	this->pointCount = pointCount;

	//Definitionen für Box2D
	//Body Definition
	this->bodyDef = new b2BodyDef();
	this->bodyDef->type = b2_dynamicBody;
	this->bodyDef->position.Set(posX, posY);
	//Create Body in World
	this->body = gc->getWorld()->CreateBody(this->bodyDef);
	//Fixture
	this->chainVertices = new b2Vec2 [this->pointCount];
	//Erstellen des grafischen Objekts auf dem Box2D-Objekt
	this->renderVertices.setPrimitiveType(sf::LinesStrip);
	this->renderVertices.resize(this->pointCount);
}

void Rock::addPoint(int index, float x, float y)
{
	this->chainVertices[index].Set(x, y);
	this->renderVertices[index] = sf::Vector2f(x, -y);
}

void Rock::generate()
{
	this->polyRock = new b2PolygonShape();
	this->polyRock->Set(this->chainVertices, this->pointCount);
	this->body->CreateFixture(this->polyRock, 0);
}

void Rock::render(GameContainer*gc)
{
	gc->getWindow()->draw(this->renderVertices);
}
