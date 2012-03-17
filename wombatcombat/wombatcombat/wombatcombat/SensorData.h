//
//  SensorData.h
//  notld_pt
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef notld_pt_SensorData_h
#define notld_pt_SensorData_h

#include <string>
using namespace std;

class SensorData
{
public:
  string name;
  int contactCount;
  
  SensorData(string name);
  
};

#endif
