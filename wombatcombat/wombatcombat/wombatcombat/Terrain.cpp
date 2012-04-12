//  Terrain.cpp
//  wombatcombat
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MungoGames__. All rights reserved.
//

#include "Terrain.h"
#include "Helper.h"

Terrain::Terrain (GameContainer* gc, int pointCount, float posX, float posY)
{
  
  this->pointCount = pointCount;
  
  vectorf pos = Helper::vector2f(posX, posY);
  
  // Body Definition (Box2D)
  this->bodyDef = new b2BodyDef(); // Generates a new body definition which contains values of the Body
  this->bodyDef->position = pos.box2d;
  
  // Creates Body in the World (Box2D)
  this->body = gc->getWorld()->CreateBody(this->bodyDef);
  
  // Fixture (Box2D)
  this->chainVertices = new b2Vec2 [this->pointCount]; 
  this->renderVertices.setPrimitiveType(sf::LinesStrip);
  this->renderVertices.resize(this->pointCount);
}

void Terrain::addPoint (int index, float x, float y)
{
  vectorf pos = Helper::vector2f(x, y);
  this->chainVertices[index] = pos.box2d;
  this->renderVertices[index] = pos.sfml;
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
