//
//  main.cpp
//  ICCAD_A
//
//  Created by 張志銘 on 2015/8/7.
//  Copyright (c) 2015年 cmchang. All rights reserved.
//

#include "chip_info.h"
#include "matrix_solution.h"
#include "network_gen.h"

#include <stdio.h>
#include <iostream>

using namespace std;


int main(const int argc, const char **argv){ //
	
    srand (time(NULL));
    chip_data chip;
    if(chip.read(argv[1])){
        cout << "read file done" << endl;
    }
    
    network_generator network_a;
    network_a.data_init(chip);
	//network_a.find_network_sol();
	
	network_a.network_init();
	network_a.loading_liquid_network(argv[2]);
	network_a.network_evolution();
    
    getchar();
    
    
    int network_num = 2;
    long double total_Q = 0;
    vector <int> network_col(101,0);
    vector < vector <int> > single_network(101,network_col);
    vector < vector < vector <int> > > network(network_num,single_network);
    vector <int> channel_info_col(101,-1);
    vector < vector <int> > single_channel_info(101,channel_info_col);
    vector < vector < vector <int> > > channel_info(network_num,single_channel_info);
    vector <long double> flowrate_col(101,0);
    vector < vector <long double> > single_flow_rate(101,flowrate_col);
    vector < vector < vector <long double> > > flow_rate(network_num,single_flow_rate);
    vector < vector < vector <int> > > direction(network_num,single_network);
   
    vector < matrix > matrix_a(network_num);
    vector < vector <node> > tempnode(network_num);
    vector < vector <edge_info> > edges(network_num);
    vector < vector < int > > equal_eq(network_num);
    double wc = 100,hc = 400,l = 100,coolant_flow_rate = 42;//,unit_pressure_drop = 100.0 * pow (10.0, 12.0) / 60;
    long double unit_pressure_drop;
    unit_pressure_drop = 100.0 * pow (10.0, 12.0) / 60;
    //0:no_flow 1:flow 2:inlet 3:outlet
    for (int j = 1; j < 101; j+=2) {
        network[1][0][j] = 3;
    }
    for (int i = 1; i < 75; i++) {
        for (int j = 1; j < 101; j+=2) {
            network[1][i][j] = 1;
        }
    }
    for (int j = 1; j < 100; j++) {
        network[1][75][j] = 1;
    }
    for (int i = 76; i < 101; i++) {
        network[1][i][51] = 1;
    }
    network[1][100][51] = 2;
    
    //////////////////////
   /* for (int j = 1; j < 101; j+=2) {
        network[0][0][j] = 3;
        for (int i = 1; i < 101; i++) {
            network[0][i][j] = 1;
        }
        network[0][100][j] = 2;
    }*/
    
    for (int j = 1; j < 101; j+=2) {
        network[0][0][j] = 3;
        for (int i = 1; i < 101; i++) {
            network[0][i][j] = 1;
        }
        network[0][100][j] = 2;
    }
    /////////////////////
    
    for (int i = 0; i < network_num; i++) {
        cout << "network_num " << i << endl;
        //network_reverse(&network[i]);
        network_graph( &network[i], &tempnode[i], &edges[i]);
        cout << "network_graph done!" << endl;
        //getchar();
       /* for (int j = 0; j < tempnode[i].size(); j++) {
            cout << "node_"<< tempnode[i][j].num << " x: " << tempnode[i][j].coordinate.first << " y: " << tempnode[i][j].coordinate.second << " type: " << tempnode[i][j].type << " edges:";
            for (int k = 0; k < tempnode[i][j].edges.size(); k++) {
                cout << tempnode[i][j].edges[k] << " " ;
            }
            cout << endl;
        }
        for (int j = 0; j < edges[i].size(); j++) {
            cout << "edge: " << j << " nodes: " << edges[i][j].nodes.first << " " << edges[i][j].nodes.second << "  " << edges[i][j].HV << "  length: " << edges[i][j].length << endl;
        }*/
        
        matrix_a[i].get_num_channel(&tempnode[i], &edges[i]);
        cout << "get_num_channel done!" << endl;
        matrix_a[i].get_path(&tempnode[i], &edges[i]);
        cout << "get_path done!" << endl;
        matrix_a[i].initial_direction(&tempnode[i], &edges[i]);
        cout << "initial_direction done!" << endl;
        matrix_a[i].get_funtion( &tempnode[i], &edges[i], unit_pressure_drop);
        cout << "get_funtion done!" << endl;
        getchar();
        
        int check = -2;
        while ( check != -1){
            matrix_a[i].initial_matrix(); //&equal_eq[i]
            matrix_a[i].check_matrix_Q();
            check = matrix_a[i].Gaussian_Elimination();//&equal_eq[i]
        }
        
        matrix_a[i].get_inlet_Q(&tempnode[i]);
    }
    cout << endl << endl << endl;
    for (int i = 0; i < network_num; i++) {
        total_Q += matrix_a[i].inlet_Q;
        cout << i << " " << "total_Q " << total_Q << "\t" ;
    }
    for (int i = 0; i < network_num; i++) {
        cout << "network_num " << i << endl;
        matrix_a[i].get_pressure_drop(wc, hc, l, coolant_flow_rate, unit_pressure_drop, total_Q);
        matrix_a[i].fill_flow_rate(&tempnode[i] ,&edges[i],&flow_rate[i],&channel_info[i]);
        matrix_a[i].fill_direction(&tempnode[i] ,&edges[i],&direction[i]);
        matrix_a[i].write_output(&i,&network[i], &tempnode[i],&flow_rate[i],&direction[i],&channel_info[i]);
    }
    
    return 0;
}

