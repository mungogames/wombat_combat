/*PolyBox.cpp
 *
 * 	Created on: 17.03.2012
 * 	Author:sk
 */

#include "PolyBox.h"
#include <iostream>
#define pi 3.14159265
using namespace std;

PolyBox::PolyBox (GameContainer* gc, int pointCount, float posX, float posY)
{
  this->Constructor(gc, pointCount, posX, posY, b2_dynamicBody);
}


PolyBox::PolyBox (GameContainer* gc, int pointCount, float posX, float posY, b2BodyType type)
{
	this->Constructor(gc, pointCount, posX, posY, type);
}

void PolyBox::Constructor(GameContainer *gc, int pointCount, float posX, float posY, b2BodyType type)
{
  this->gc = gc;
  
  //pointCount Konstruktor in lokale Variable legen
	this->pointCount = pointCount;
  
	//Definitionen für Box2D
	//Body Definition
	this->bodyDef = new b2BodyDef();
	this->bodyDef->type = type;
	this->bodyDef->fixedRotation = false;
	this->bodyDef->position.Set(posX, posY);
	//Create Body in World
	this->body = gc->getWorld()->CreateBody(this->bodyDef);
	//Fixture
	this->chainVertices = new b2Vec2 [this->pointCount];
	this->renderObj = new sf::ConvexShape(this->pointCount);
	this->renderObj->setPosition(sf::Vector2f(posX, -posY));
}



void PolyBox::addPoint(int index, float x, float y)
{
	this->chainVertices[index].Set(x, y);
	this->renderObj->setPoint(index, sf::Vector2f(x,-y));
}



void PolyBox::generate()
{
	this->polygon = new b2PolygonShape();
	this->polygon->Set(this->chainVertices, this->pointCount);
	this->body->CreateFixture(this->polygon, 1.0);
}



void PolyBox::setColor(sf::Color color)
{
  this->renderObj->setFillColor(color);
}



void PolyBox::update()
{
	float xb = this->body->GetPosition().x;
	float yb = this->body->GetPosition().y;
	float32 ab = this->body->GetAngle();

	this->renderObj->setPosition(sf::Vector2f(xb,-yb));
	this->renderObj->setRotation(-(ab * (180/pi)));
	this->renderObj->setFillColor(sf::Color::Blue);
}

void PolyBox::render()
{
	gc->getWindow()->draw(*renderObj);
}
