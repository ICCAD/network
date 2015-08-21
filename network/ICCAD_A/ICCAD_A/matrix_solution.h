//
//  matrix_solution.h
//  network
//
//  Created by 張志銘 on 2015/7/19.
//  Copyright (c) 2015年 cmchang. All rights reserved.
// 

#ifndef __network__matrix_solution__
#define __network__matrix_solution__

#include <stdio.h>
#include "network.h"
#include <algorithm>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
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
    void get_path(vector <node> *, vector <edge_info> * );
    void DFS_path(int, vector <node> *, vector <edge_info> *, vector <int> , vector <int> );
    int Gaussian_Elimination();//vector < int > *
    void check_matrix_Q();
    void initial_matrix();//vector < int > *
    void get_funtion(vector <node> *, vector <edge_info> *, long double);
    void initial_direction(vector <node> *, vector <edge_info> *);
    void get_inlet_Q(vector <edge_info> *);
    void get_pressure_drop(double, double, double, double,long double, long double);
    void fill_flow_rate(vector <node> *, vector <edge_info> *,vector < vector <long double> > *, vector < vector <int> > *);
    void fill_direction(vector <node> *, vector <edge_info> *, vector < vector <int> >*);
    //void write_output(const char *, const char *, vector < vector <double> > *, vector < vector <int> >*);
    void write_output(int *, vector < vector <int> > *, vector <node> *, vector < vector <long double> > *, vector < vector <int> >*, vector < vector <int> >*);
    long double inlet_Q;
    void check_sol();
    void spice_input(int *,vector <node> *,long double);
private:
    vector < vector <long double> > all_function;
    vector < vector <long double> > matrix_Q;
    vector < vector <int> > member_channel;
    vector < pair < int,int > > channel_dir;
    vector < vector <int> > member_path;
    vector <int> store_func;
    vector <long double> sol_Q;
    vector <int> functions;
    vector <long double> channel_length;
    int num_channel;
    int num_path;
    long double pressure_drop;
    int  node_func_num;
};





#endif /* defined(__network__matrix_solution__) */
