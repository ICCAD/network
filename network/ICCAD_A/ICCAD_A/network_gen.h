
#ifndef __network__gen__
#define __network__gen__

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>   
#include <time.h>
#include <iomanip>


#include "chip_info.h"

using namespace std;

class network_generator{
public:
	void data_init(chip_data &);
	void find_network_sol();
	void network_init();
	bool network_gen(int);
	void cool_down(pair<int, int>, double);
	bool check_line(pair<int, int>, int, int);
	void choose_next_inlet(pair<int, int> &, vector <int>);
	int choose_dir(pair<int, int>, int, int);
	void print_heat_network();
    void print_liquid_network();
private:
	int channel_layer;
    vector < vector <double> > heat_network;
	vector < vector <double> > init_heat_network;
	vector < vector < vector <int> > > liquid_network;
	vector < vector < vector <int> > > init_liquid_network;
	chip_data chip;
	double alpha;    /////weight of distance
	
};










#endif