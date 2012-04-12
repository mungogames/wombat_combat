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

#include "PolyBox.h"
#include "Helper.h"

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
  
  vectorf pos = Helper::vector2f(posX, posY); // Vector2f object that contains values for sfml and box2d
  
	//Body Definition
	this->bodyDef = new b2BodyDef();
	this->bodyDef->type = type;
	this->bodyDef->fixedRotation = false;
  this->bodyDef->position = pos.box2d;
  
	//Create Body in World
	this->body = gc->getWorld()->CreateBody(this->bodyDef);
  
	//Fixtures
	this->chainVertices = new b2Vec2 [this->pointCount];
	this->renderObj = new sf::ConvexShape(this->pointCount);
	this->renderObj->setPosition(pos.sfml);
}



void PolyBox::addPoint(int index, float x, float y)
{
  vectorf pos = Helper::vector2f(x, y);
	this->chainVertices[index] = pos.box2d;
	this->renderObj->setPoint(index, pos.sfml);
}



void PolyBox::generate()
{
	this->polygon = new b2PolygonShape();
	this->polygon->Set(this->chainVertices, this->pointCount);
	this->body->CreateFixture(this->polygon, 1.5);
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
