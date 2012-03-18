//
//  Arrow.cpp
//  wombatcombat
//
//  Created by Simon Jentsch on 17.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Arrow.h"

#define pi 3.14159265

Arrow::Arrow (GameContainer* gc, int damage, b2Vec2 speed, b2Vec2 pos, Direction side)
{
  
  this->livingTime = 5;
  
  this->gc = gc;
    
  this->damage = damage;
  this->speed = speed;
    
  this->arrowSensorData = new SensorData("arrow_sensor");
  
  float hyp = sqrt(pow(speed.y, 2) + pow(speed.x, 2));
  
  float radiant = sin(speed.y / hyp);
  radiant = (side == LEFT) ? -radiant : radiant; // If Player faces left, radiant is negated to calculate the right angle
  float angle = radiant  * (180/pi);  
  
  // Body Definition (Box2D)
  b2BodyDef bodyDef; // Generates a new body definition which contains values of the Body
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(pos.x, pos.y);
  
  // Creates Body in the World (Box2D)
  this->body = gc->getWorld()->CreateBody(&bodyDef);
  
  // Fixure (Box2D)
  b2PolygonShape arrowShape;
  arrowShape.SetAsBox(0.7, 0.1, b2Vec2(0,0), radiant); // Sets the Arrow with halfsizes
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &arrowShape;
  fixtureDef.density = 0.67;
  fixtureDef.friction = 0.6;
  fixtureDef.userData = this->arrowSensorData;
  this->body->CreateFixture(&fixtureDef);
  
  // Sets the Render Object
  this->renderObj.setOrigin(0.1/2, 0.05/2); // Sets Position to the center of the render object
  this->renderObj.setPosition(pos.x, -pos.y);
  this->renderObj.setSize(sf::Vector2f(0.7, 0.1));
  this->renderObj.setFillColor(sf::Color::Cyan);
 
  this->body->ApplyLinearImpulse(this->speed, this->body->GetWorldCenter());
}


// Deconstructor
Arrow::~Arrow()
{
  this->body->DestroyFixture(this->body->GetFixtureList());
  this->gc->getWorld()->DestroyBody(this->body);
  delete this->arrowSensorData;
}



b2Body* Arrow::getBody()
{
  return this->body;
}

float Arrow::getLivingPos()
{
  
  float curTime = this->timer.getElapsedTime().asSeconds();
  return curTime / this->livingTime * 100;
}

void Arrow::update()
{
  this->renderObj.setPosition(this->body->GetPosition().x, -this->body->GetPosition().y);
  this->renderObj.setRotation(-(this->body->GetAngle() * (180/pi)));
} 

void Arrow::render()
{
  this->gc->getWindow()->draw(this->renderObj);
}
