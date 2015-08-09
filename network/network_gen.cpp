
#include "network_gen.h"

void network_generator::ambient_init(chip_data &chip){
	channel_layer = chip.layer_num - 1;
	network.resize(channel_layer);
    vector < vector <double> > temp(101,vector <double> (101));
    for (int i=0; i<network.size(); i++) {
        network.push_back(temp);
    }
	cout << network.size();
	
	
	
}

void network_generator::heat_diffusion(block a, int network_layer){
    double mid_x = (a.lx + a.width) / 2;
    double mid_y = (a.ly + a.length) / 2;
    double power = a.power;
    for (int i=0; i<network[network_layer].size(); i++) {
        ;
    }
    
    
}