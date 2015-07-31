//
//  main.cpp
//  network
//
//  Created by 張志銘 on 2015/7/18.
//  Copyright (c) 2015年 cmchang. All rights reserved.
//

#include "chip_info.h"
#include "matrix_solution.h"
#include "network_gen.h"

#include <stdio.h>
#include <iostream>

using namespace std;


int main(const int argc, const char **argv){
	
	chip_data chip;
	if(chip.read(argv[1])){
		cout << "read file done" << endl;
	}
	
	network_generator network_a;
	network_a.ambient_init(chip);
	
	getchar();
	
	//getchar();
    vector <int> network_col(101,0);//
    vector < vector <int> > network(101,network_col);//
    vector <node> tempnode(0);
    vector <edge_info> edges(0);
    vector < int > equal_eq(0);
    double wc = 100,hc = 400,coolant_flow_rate = 42,unit_pressure_drop = 100;
    matrix matrix_a;
    
    //0:1:flow 2:inlet 3:outlet
  /*  network[0][3] = 3;
    network[1][10] = 3;
    network[10][9] = 3;
    network[10][1] = 2;
    network[5][0] = 2;
    for (int i = 1; i <= 3; i++) {
        network[i][3] = 1;
        network[i][7] = 1;
    }
    for (int j = 7; j < 10; j++) {
        network[1][j] = 1;
    }
    for (int j = 3; j <= 7; j++) {
        network[3][j] = 1;
    }
    for (int i = 3; i <= 5; i++) {
        network[i][5] = 1;
    }
    for (int j = 1; j <= 5; j++) {
        network[5][j] = 1;
    }
    for (int i = 5; i <= 7; i++) {
        network[i][3] = 1;
    }
    for (int j = 3; j <= 7; j++) {
        network[7][j] = 1;
    }
    for (int i = 7; i <= 9; i++) {
        network[i][5] = 1;
        network[i][7] = 1;
    }
    for (int j = 1; j <= 5; j++) {
        network[9][j] = 1;
    }
    for (int j = 7; j <= 9; j++) {
        network[9][j] = 1;
    }*/
     for (int j = 1; j < 101; j+=2) {
     network[0][j] = 3;
     }
     for (int i = 1; i < 75; i++) {
     for (int j = 1; j < 101; j+=2) {
     network[i][j] = 1;
     }
     }
     for (int j = 1; j < 100; j++) {
     network[75][j] = 1;
     }
     for (int i = 76; i < 101; i++) {
     network[i][51] = 1;
     }
     network[100][51] = 2;
    /////////////////////
    
    network_graph( &network, &tempnode, &edges);
    cout << "network_graph done!" << endl;
    //getchar();
    for (int i = 0; i < tempnode.size(); i++) {
        cout << "node_"<< tempnode[i].num << " x: " << tempnode[i].coordinate.first << " y: " << tempnode[i].coordinate.second << " type: " << tempnode[i].type << " edges:";
        for (int j = 0; j < tempnode[i].edges.size(); j++) {
            cout << tempnode[i].edges[j] << " " ;
        }
        cout << endl;
    }
    for (int i = 0; i < edges.size(); i++) {
        cout << "edge: " << i << " nodes: " << edges[i].nodes.first << " " << edges[i].nodes.second << "  " << edges[i].HV << "  length: " << edges[i].length << endl;
        //cout << "flow_rate: " << edges[i].flow_rate << endl;
    }
    matrix_a.get_num_channel(&tempnode, &edges);
    cout << "get_num_channel done!" << endl;
    //getchar();
    matrix_a.get_path(&tempnode, &edges);
    cout << "get_path done!" << endl;
    //getchar();
    matrix_a.initial_direction(&tempnode, &edges);
    cout << "initial_direction done!" << endl;
    //getchar();
    matrix_a.get_funtion( &tempnode, &edges, unit_pressure_drop);
    cout << "get_funtion done!" << endl;
    getchar();
    
    int check = -2;
    while ( check != -1){
        matrix_a.initial_matrix(&equal_eq);
        matrix_a.check_matrix_Q();
        check = matrix_a.Gaussian_Elimination(&equal_eq);
    }
    
    matrix_a.get_pressure_drop(wc, hc, coolant_flow_rate, unit_pressure_drop, &edges);
    return 0;
}

