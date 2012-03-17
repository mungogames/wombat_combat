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
	this->renderObj = new sf::ConvexShape();
	this->renderObj->setPointCount(this->pointCount);
	this->renderObj->setPosition(posX, posY);
}

void Rock::addPoint(int index, float x, float y)
{
	this->chainVertices[index].Set(x, y);
	this->renderObj->setPoint(index, sf::Vector2f(x,y));
}

void Rock::generate()
{
	this->polygon = new b2PolygonShape();
	this->polygon->Set(this->chainVertices, this->pointCount);
	this->body->CreateFixture(this->polygon, 1);
}

void Rock::render(GameContainer*gc)
{
	gc->getWindow()->draw(this->renderObj);
}
