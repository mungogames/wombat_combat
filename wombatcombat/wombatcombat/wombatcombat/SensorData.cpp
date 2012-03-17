//
//  SensorData.cpp
//  notld_pt
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SensorData.h"

SensorData::SensorData(string name)
{
  this->name = name;
  this->contactCount = 0;
}