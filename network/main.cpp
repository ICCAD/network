//
//  main.cpp
//  network
//
//  Created by 張志銘 on 2015/7/18.
//  Copyright (c) 2015年 cmchang. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "network.h"
#include "matrix_solution.h"
using namespace std;

int main(const int argc, const char **argv){
    vector <int> network_col(11,0);//
    vector <double> flowrate_col(11,0);
    vector < vector <int> > network(11,network_col);//
    vector < vector <int> > direction(11,network_col);
    vector < vector <double> > flow_rate(11,flowrate_col);
    
    vector <node> tempnode(0);
    vector <edge_info> edges(0);
    vector < int > equal_eq(0);
    double wc = 100,hc = 400,coolant_flow_rate = 42,unit_pressure_drop = 100;
    matrix matrix_a;
    //cout << network.size() << " " << network[0].size() << 123123 << endl;
    //0: 1:flow 2:inlet 3:outlet
    network[0][3] = 3;
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
    }
    /* for (int j = 1; j < 101; j+=2) {
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
     network[100][51] = 2;*/
    /*for (int i = 1 ; i < network.size(); i+=2) {
        for (int j = 0; j < network[i].size(); j++) {
            network[i][j] = 1;
        }
    }
    for (int j = 1 ; j < network[0].size(); j+=2) {
        for (int i = 0; i < network.size(); i++) {
            network[i][j] = 1;
        }
    }
    for (int j = 1; j < network[0].size(); j+=2) {
        network[0][j] = 2;
        network[network.size()-1][j] = 2;
    }
    for (int i = 1; i < network[0].size(); i+=2) {
        network[i][0] = 3;
        network[i][network.size()-1] = 3;
    }*/
    /////////////////////
    network_reverse(&network);
    cout << network.size() << " " << network[0].size() << endl;
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
        cout << "edge: " << i << " nodes: " << edges[i].nodes.first << " " << edges[i].nodes.second << "  " << edges[i].HV << "  length: " << edges[i].length <<endl;
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
    matrix_a.fill_flow_rate(&tempnode ,&edges,&flow_rate);
    matrix_a.fill_direction(&tempnode ,&edges,&direction);
    matrix_a.write_output(argv[1],argv[2],&flow_rate,&direction);
    return 0;
}

