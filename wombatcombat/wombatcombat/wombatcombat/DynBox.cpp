/*DynBox.cpp
 *
 * 	Created on: 17.03.2012
 * 	Author:sk
 */

#include "DynBox.h"
#include <iostream>
#define pi 3.14159265
using namespace std;

DynOrb::DynOrb (GameContainer* gc, int pointCount, float posX, float posY)
{
	//pointCount Konstruktor in lokale Variable legen
	this->pointCount = pointCount;


	//Definitionen für Box2D
	//Body Definition
	this->bodyDef = new b2BodyDef();
	this->bodyDef->type = b2_dynamicBody;
	this->bodyDef->fixedRotation = false;
	this->bodyDef->position.Set(posX, posY);
	//Create Body in World
	this->body = gc->getWorld()->CreateBody(this->bodyDef);
	//Fixture
	this->chainVertices = new b2Vec2 [this->pointCount];
	this->renderObj = new sf::ConvexShape(this->pointCount);
	this->renderObj->setPosition(sf::Vector2f(posX, -posY));
}

void DynOrb::addPoint(int index, float x, float y)
{
	this->chainVertices[index].Set(x, y);
	this->renderObj->setPoint(index, sf::Vector2f(x,-y));
}

void DynOrb::generate()
{
	this->polygon = new b2PolygonShape();
	this->polygon->Set(this->chainVertices, this->pointCount);
	this->body->CreateFixture(this->polygon, 1);
}

void DynOrb::update(GameContainer*gc)
{
	float xb = this->body->GetPosition().x;
	float yb = this->body->GetPosition().y;
	float32 ab = this->body->GetAngle();

	this->renderObj->setPosition(sf::Vector2f(xb,-yb));
	this->renderObj->setRotation(-(ab * (180/pi)));
	this->renderObj->setFillColor(sf::Color::Blue);
}

void DynOrb::render(GameContainer*gc)
{
	gc->getWindow()->draw(*renderObj);
}
