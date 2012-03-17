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
	this->bodyDef->position.Set(posX, posY);
	//Create Body in World
	this->body = gc->getWorld()->CreateBody(this->bodyDef);
	//Fixture
	this->chainVertices = new b2Vec2 [this->pointCount];
	//Erstellen des grafischen Objekts auf dem Box2D-Objekt
	this->renderVertices.setPrimitiveType(sf::LinesStrip);
	this->renderVertices.resize(this->pointCount);
}

void Terrain::addPoint(int index, float x, float y)
{
	this->chainVertices[index].Set(x, y);
	this->renderVertices[index] = sf::Vector2f(x, -y);
}

void Terrain::generate()
{
	this->chain = new b2ChainShape();
	this->chain->CreateChain(this->chainVertices, this->pointCount);
	this->body->CreateFixture(this->chain, 0);
}

void Terrain::render(GameContainer*gc)
{
	gc->getWindow()->draw(this->renderVertices);
}
