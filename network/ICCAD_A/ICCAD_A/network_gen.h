
#ifndef __network__gen__
#define __network__gen__

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>   
#include <time.h>
#include <iomanip>


#include "chip_info.h"
#include "matrix_solution.h"

using namespace std;

class network_generator{
public:
	void data_init(chip_data &);
	void find_network_sol();
	void network_init();
	bool network_gen();
	bool check_line(pair<int, int>, int, int);
	void choose_dir(pair<int, int> &, int, vector < vector <double> > *);
	void random_in_out_let(vector < pair <int, int> > &, vector < pair <int, int> > &);
	bool Is_close_center(pair <int, int>, int);
	void network_evolution();
	void print_heat_network(vector < vector <double> >);
    void print_liquid_network();
	void print_network();
private:
	int channel_layer;
	vector < vector <double> > init_heat_network;
	vector < vector < vector <int> > > liquid_network;
	vector < vector < vector <int> > > init_liquid_network;
	chip_data chip;
	double alpha;    /////weight of distance
	double beta;
};

void pout(pair <int, int>);








#endif