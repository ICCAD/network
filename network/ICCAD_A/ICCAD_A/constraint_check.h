//
//  constraint_check.h
//  network
//
//  Created by 張志銘 on 2015/7/29.
//  Copyright (c) 2015年 cmchang. All rights reserved.
//

#ifndef __constraint_check__
#define __constraint_check__

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

string read_teperature(const char *, vector < vector <double> > *);

bool check_MAX_temperature(vector < vector <double> >, double);

bool check_teperature_gradient(vector < vector <double> >, double);


#endif /* defined(__network__constraint_check__) */
