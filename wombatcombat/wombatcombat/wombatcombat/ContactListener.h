//
//  ContactLister.h
//  notld_pt
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef notld_pt_ContactLister_h
#define notld_pt_ContactLister_h

#include <Box2D/Box2D.h>
#include <iostream>
#include "SensorData.h"

class ContactListener : public b2ContactListener
{
  void BeginContact(b2Contact* contact) {
    
    if (contact->GetFixtureA()->IsSensor())
    {
      ((SensorData*)contact->GetFixtureA()->GetUserData())->contactCount++;
    }
      
    if (contact->GetFixtureB()->IsSensor())
    {
      ((SensorData*)contact->GetFixtureB()->GetUserData())->contactCount++;
    }
      
  }
  
  void EndContact(b2Contact* contact) {
    
    if (contact->GetFixtureA()->IsSensor())
    {
      ((SensorData*)contact->GetFixtureA()->GetUserData())->contactCount--;
    }
    
    if (contact->GetFixtureB()->IsSensor())
    {
      ((SensorData*)contact->GetFixtureB()->GetUserData())->contactCount--;
    }

    
  }
};

#endif
