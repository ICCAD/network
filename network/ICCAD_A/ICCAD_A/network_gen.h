
#ifndef __network__gen__
#define __network__gen__

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

#include "chip_info.h"

using namespace std;

class network_generator{
public:
	void ambient_init(chip_data &);
    void print_network(const char *);
private:
	int channel_layer;
    vector < vector <double> > heat_network;
	vector < vector < vector <int> > > liquid_network;
	
	
};










#endif