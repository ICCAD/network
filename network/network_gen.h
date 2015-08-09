
#ifndef __network__gen__
#define __network__gen__

#include <stdio.h>
#include <vector>
#include <iostream>

#include "chip_info.h"

using namespace std;

class network_generator{
public:
	void ambient_init(chip_data &);
    void heat_diffusion(block,int);
private:
	int channel_layer;
	vector < vector < vector <double> > > network;
	
	
};










#endif