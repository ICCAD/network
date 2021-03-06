//
//  network.h
//  network
//
//  Created by 張志銘 on 2015/7/18.
//  Copyright (c) 2015年 cmchang. All rights reserved.
// 

#ifndef network_network_h
#define network_network_h
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct edge_info{
	double length;
	pair < int , int > nodes;
    int channel;
	char HV; //H V N
};

struct node{
    int num;
	//type: c:corner b:branch i:inlet o:outlet I:coolant inlet O:coolant outlet
	char type;
    pair < int ,int > coordinate; // (x,y)
	vector <int> edges;
};

void network_graph( vector < vector <int> > *, vector <node> * , vector <edge_info> *);

void network_reverse (vector < vector <int> > *);
#endif
