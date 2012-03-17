
//
//  Terain.cpp
//  wombatcombat
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Terrain.h"

Terrain::Terrain (GameContainer* gc, int pointCount, float posX, float posY)
{
  
  this->pointCount = pointCount;
  
  // Ground Body
  
  
  // Body Definition (Box2D)
  this->bodyDef = new b2BodyDef(); // Generates a new body definition which contains values of the Body
  this->bodyDef->position.Set(posX, posY);
  
  // Creates Body in the World (Box2D)
  this->body = gc->getWorld()->CreateBody(this->bodyDef);
  
  // Fixture (Box2D)
  this->chainVertices = new b2Vec2 [this->pointCount]; 
  this->renderVertices.setPrimitiveType(sf::LinesStrip);
  this->renderVertices.resize(this->pointCount);
}

void Terrain::addPoint (int index, float x, float y)
{
  this->chainVertices[index].Set(x, y);
  this->renderVertices[index] = sf::Vector2f(x, -y);
}

void Terrain::generate ()
{
  this->chain = new b2ChainShape(); 
  this->chain->CreateChain(this->chainVertices, this->pointCount);
  this->body->CreateFixture(this->chain, 0);  
}


void Terrain::render (GameContainer* gc)
{
  gc->getWindow()->draw(this->renderVertices);
}