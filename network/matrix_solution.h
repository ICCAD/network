//
//  matrix_solution.h
//  network
//
//  Created by 張志銘 on 2015/7/19.
//  Copyright (c) 2015年 cmchang. All rights reserved.
//

#ifndef __network__matrix_solution__
#define __network__matrix_solution__

#include <algorithm>
#include <stdio.h>

#include "network.h"


struct record_info{
    int num;
    int column;
    vector <int> row;
};

bool compare (record_info,record_info);

class matrix{
public:
    void get_num_channel(vector <node> *, vector <edge_info> *);
    void data_init();
    void DFS_edge(int, vector <node> *, vector <edge_info> *, vector <int> *, vector <int> *);
    void get_path(vector <node> *, vector <edge_info> *);
    void DFS_path(int, vector <node> *, vector <edge_info> *, vector <int> , vector <int> );
    int Gaussian_Elimination(vector < int > *);
    void check_matrix_Q();
    void initial_matrix(vector < int > *);
    void get_funtion(vector <node> *, vector <edge_info> *, long double);
    void initial_direction(vector <node> *, vector <edge_info> *);
    void get_pressure_drop(double, double, double, double, vector <edge_info> *);
private:
    vector < vector <long double> > all_function;
    vector < vector <long double> > matrix_Q;
    vector < vector <int> > member_channel;
    vector < pair < int,int > > channel_dir;
    vector < vector <int> > member_path;
    vector <int> store_func;
    // vector < int > equal_eq;
    int num_channel;
    int num_path;
    long double pressure_drop;
    int  node_func_num;
};





#endif /* defined(__network__matrix_solution__) */
