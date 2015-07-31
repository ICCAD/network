
#include "network_gen.h"

void network_generator::ambient_init(chip_data &chip){
	channel_layer = chip.layer_num - 1;
	network.resize(channel_layer);
	cout << network.size();
	
	
	
}