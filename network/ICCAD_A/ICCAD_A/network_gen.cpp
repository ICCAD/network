
#include "network_gen.h"

void network_generator::ambient_init(chip_data &chip){
	channel_layer_num = chip.layer_num - 1;
    vector < vector <double> > temp(101,vector <double> (101, channel_layer_num * 10000));
    heat_network = temp;
    vector < vector <int> > temp_liquid(101,vector <int> (101));
    for (int i=0; i<101; i+=2) {
        for (int j=0; j<101; j+=2) {
            temp_liquid[i][j] = -1;
        }
    }
    for (int i=0; i<channel_layer_num; i++) {
        liquid_network.push_back(temp_liquid);
    }
}

void network_generator::print_network(const char *output_file){
    ofstream fout(output_file);
    for (int i=0; i<liquid_network.size(); i++) {
        for (int j=0; j<101; j++) {
            for (int k=0; k<101; k++) {
                fout << liquid_network[i][j][k] << " " ;
            }
            fout << endl;
        }
        fout << endl;
    }
}

