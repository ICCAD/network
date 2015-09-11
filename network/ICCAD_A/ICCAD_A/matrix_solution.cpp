//
//  matrix_solution.cpp
//  network
//
//  Created by ±i§Ó»Ê on 2015/7/19.
//  Copyright (c) 2015¦~ cmchang. All rights reserved.
//

#include "matrix_solution.h"

void matrix::get_num_channel(vector <node> *temp_node, vector <edge_info> *temp_edge){
    num_channel = 0;
    vector <int> record_edge((*temp_edge).size());
    vector <int> temp_edge_member;
    long double temp_length;
    for (int i = 0; i < (*temp_node).size(); i++) {
        if((*temp_node)[i].type != 'c' && (*temp_node)[i].type != 'I' && (*temp_node)[i].type != 'O'){
            DFS_edge(i, temp_node, temp_edge, &temp_edge_member, &record_edge);
        }
        
    }
    for (int i = 0; i < (*temp_edge).size() ; i++){
        (*temp_edge)[i].channel = -1;
    }
    for( int i = 0; i < member_channel.size(); i++){
        //cout << "channel_" << i << ": " ;
        for (int j = 0; j < member_channel[i].size(); j++) {
            (*temp_edge)[member_channel[i][j]].channel = i;
           // cout << member_channel[i][j] << " ";
        }
        //cout << endl;
    }
    cout << "num_channel: " << num_channel << endl;
  /*  for (int i = 0; i < (*temp_edge).size(); i++){
        cout << "edge_" << i << ": channel_" << (*temp_edge)[i].channel << endl;
    }*/
    ////////channel length//////
    for (int j = 0; j < num_channel; j++) {
        temp_length = 0;
        for (int k = 0; k < member_channel[j].size(); k++) {
            temp_length += (*temp_edge)[member_channel[j][k]].length;
        }
        channel_length.push_back(temp_length);
    }
    cout << "channel_length " << endl;
    for (int i = 0; i < channel_length.size(); i++) {
        cout << channel_length[i] << " ";
    }
    cout << endl;
    ////////
}

void matrix::DFS_edge(int nodex, vector <node> *temp_node, vector <edge_info> *temp_edge, vector <int> *temp_edge_member, vector <int> *record_edge){
    for (int i = 0; i < (*temp_node)[nodex].edges.size(); i++) {
        if ((*record_edge)[(*temp_node)[nodex].edges[i]] != 1){
            if ( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first != nodex) {
                if ( (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type == 'c' ){
                    (*record_edge)[(*temp_node)[nodex].edges[i]] = 1;
                    (*temp_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    DFS_edge( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first, temp_node, temp_edge, temp_edge_member, record_edge);
                }
                else if ((*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type != 'I' && (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type != 'O'){
                    (*record_edge)[(*temp_node)[nodex].edges[i]] = 1;
                    (*temp_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    member_channel.push_back((*temp_edge_member));
                    (*temp_edge_member).clear();
                    num_channel++;
                    DFS_edge( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first, temp_node, temp_edge, temp_edge_member, record_edge);
                }
            }
            else if ( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second != nodex) {
                if ( (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second].type == 'c' ){
                    (*record_edge)[(*temp_node)[nodex].edges[i]] = 1;
                    (*temp_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    DFS_edge( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second, temp_node, temp_edge, temp_edge_member, record_edge);
                }
                else if((*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type != 'I' && (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type != 'O'){
                    (*record_edge)[(*temp_node)[nodex].edges[i]] = 1;
                    (*temp_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    member_channel.push_back((*temp_edge_member));
                    (*temp_edge_member).clear();
                    num_channel++;
                    DFS_edge( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second, temp_node, temp_edge, temp_edge_member, record_edge);
                }
            }
        }
    }
}

void matrix::initial_direction(vector <node> *temp_node , vector <edge_info> *temp_edge){
    pair <int, int> dir;
    for (int i = 0 ; i < member_channel.size(); i++) {
        if (member_channel[i].size() >= 2) {
            if ((*temp_edge)[member_channel[i][0]].nodes.first != (*temp_edge)[member_channel[i][1]].nodes.first && (*temp_edge)[member_channel[i][0]].nodes.first != (*temp_edge)[member_channel[i][1]].nodes.second) {
                dir.first = (*temp_edge)[member_channel[i][0]].nodes.first;
            }
            else if((*temp_edge)[member_channel[i][0]].nodes.second != (*temp_edge)[member_channel[i][1]].nodes.first && (*temp_edge)[member_channel[i][0]].nodes.second != (*temp_edge)[member_channel[i][1]].nodes.second){
                dir.first = (*temp_edge)[member_channel[i][0]].nodes.second;
            }
            
            if ((*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.first != (*temp_edge)[member_channel[i][member_channel[i].size()-2]].nodes.first && (*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.first != (*temp_edge)[member_channel[i][member_channel[i].size()-2]].nodes.second) {
                dir.second = (*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.first;
            }
            else if((*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.second != (*temp_edge)[member_channel[i][member_channel[i].size()-2]].nodes.first && (*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.second != (*temp_edge)[member_channel[i][member_channel[i].size()-2]].nodes.second){
                dir.second = (*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.second;
            }
        }
        else {
            dir.first = (*temp_edge)[member_channel[i][0]].nodes.first;
            dir.second = (*temp_edge)[member_channel[i][0]].nodes.second;
        }
        channel_dir.push_back(dir);
    }
   /* cout << "\nflow_direction"<< endl;
    for (int i = 0; i < channel_dir.size(); i++) {
        cout << "channel_" << i << " in: " <<channel_dir[i].first << " out: " << channel_dir[i].second << endl;
    }*/
}

void matrix::write_spice_input(int *i,vector <node> *temp_node,long double unit_pressure_drop){
    ostringstream oss;
    string output_spice;
    oss.str("");
    oss <<  "spice_" << *i << ".txt";
    output_spice = oss.str();
    ofstream spice_out(output_spice.c_str());
    spice_out << endl;
    spice_out << "Vi  V 0 " << unit_pressure_drop << endl;
    for (int i = 0; i < channel_length.size(); i++) {
        if ((*temp_node)[channel_dir[i].first].type == 'i') {
            if ((*temp_node)[channel_dir[i].second].type == 'o') {
                spice_out << "R" << i << "  V 0 "<< channel_length[i] << endl;
            }
            else{
                spice_out << "R" << i << "  V net" << (*temp_node)[channel_dir[i].second].num << " " << channel_length[i] << endl;
            }
        }
        else if((*temp_node)[channel_dir[i].second].type == 'i'){
            if ((*temp_node)[channel_dir[i].first].type == 'o') {
                spice_out << "R" << i << "  0 V "<< channel_length[i] << endl;
            }
            else{
                spice_out << "R" << i << "  net" << (*temp_node)[channel_dir[i].first].num << " V " << channel_length[i] << endl;
            }
        }
        else{
            if ((*temp_node)[channel_dir[i].first].type == 'o') {
                spice_out << "R" << i << "  0 net" << (*temp_node)[channel_dir[i].second].num << " " << channel_length[i] << endl;
            }
            else if((*temp_node)[channel_dir[i].second].type == 'o'){
                spice_out << "R" << i << "  net" << (*temp_node)[channel_dir[i].first].num << " 0 " << channel_length[i] << endl;
            }
            else{
                spice_out << "R" << i << "  net" << (*temp_node)[channel_dir[i].first].num << " net" << (*temp_node)[channel_dir[i].second].num << " " << channel_length[i] << endl;
            }
        }
    }
    spice_out << ".op" << endl << endl;
    spice_out << ".end" << endl;
}

void  matrix::read_spice_result(int *i){
    string temp;
    long double Q;
    vector <long double> temp_Q;
    stringstream ss;
    ostringstream oss;
    string spice_test;
    oss.str("");
    oss <<  "test_" << *i << ".txt";
    spice_test = oss.str();
    //cout << spice_test << endl;
    ifstream fin(spice_test.c_str());
    while (matrix_Q.size() != channel_length.size()) {
        fin >> temp;
        if (temp == "resistors") {
            //cout << temp << endl;
            while ( matrix_Q.size() != channel_length.size()) {
                fin >> temp;
                if (temp == "current") {
                    while (!fin.eof()){
                        fin >> temp;
                        if (temp == "power") {
                            break;
                        }
                        else{
                            ss.str("");
                            ss.clear();
                            if (temp[temp.length()-1] > 57) {
                                for (int i = 0; i < temp.length()-1; i++) {
                                    ss << temp[i];
                                }
                                ss >> Q;
                                
                                if(temp[temp.length()-1] == 'm'){
                                    Q *= pow (10.0, -3.0);
                                }
                                else if(temp[temp.length()-1] == 'u'){
                                    Q *= pow (10.0, -6.0);
                                }
                                else if(temp[temp.length()-1] == 'n'){
                                    Q *= pow (10.0, -9.0);
                                }
                                else if(temp[temp.length()-1] == 'p'){
                                    Q *= pow (10.0, -12.0);
                                }
                            }
                            else{
                                ss << temp;
                                ss >> Q;
                            }
                            temp_Q.push_back(Q);
                            matrix_Q.push_back(temp_Q);
                            temp_Q.clear();
                        }
                    }
                }
            }
        }
    }
    cout << "\nmatrix_Q" << endl;
    for (int i = 0; i < matrix_Q.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < matrix_Q[i].size(); j++) {
            cout << matrix_Q[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix::get_inlet_Q(vector <node> *temp_node){
    inlet_Q = 0;
    vector <int> inlet_channel;
    
    for (int i = 0; i < channel_length.size(); i++) {
        if ((*temp_node)[channel_dir[i].first].type == 'i' || (*temp_node)[channel_dir[i].second].type == 'i'){
            inlet_channel.push_back(i);
        }
    }
    cout << "\ninlet_channel: ";
    for (int i = 0; i < inlet_channel.size(); i++) {
        cout << inlet_channel[i] << " ";
        if (matrix_Q[inlet_channel[i]][matrix_Q[0].size()-1] < 0) {
            inlet_Q -= matrix_Q[inlet_channel[i]][matrix_Q[0].size()-1];
            
        }
        else {
            inlet_Q += matrix_Q[inlet_channel[i]][matrix_Q[0].size()-1];
        }
    }
    cout << "\ninlet_Q: " << inlet_Q << endl;
}

void matrix::get_pressure_drop(double wc, double hc, double l, double coolant_flow_rate,long double unit_pressure_drop ,long double total_Q){
    double k,dh,Ac,n;
    dh = (2 * wc * hc) / (wc + hc);
    Ac = wc * hc;
    k = 0.02848 / (dh * dh * Ac);
    
    cout << "coolant_flow_rate: " << coolant_flow_rate << endl;
    n = (coolant_flow_rate * pow (10.0, 12.0) / 60) / total_Q;
    cout << "sol_Q: " << endl;
    for (int i = 0; i < matrix_Q.size(); i++) {
        cout << i << ": ";
        sol_Q.push_back( n * matrix_Q[i][matrix_Q[0].size()-1] );
        cout << sol_Q[sol_Q.size()-1] << endl;
    }
    pressure_drop = k * l * unit_pressure_drop * n;
    cout << "\npressure_drop: " << pressure_drop  << " (pa)" << endl;
}

void matrix::fill_flow_rate(vector <node> *temp_node , vector <edge_info> *temp_edge, vector < vector <long double> > *flow_rate, vector < vector <int> > *channel_info){ //
    for (int i = 0; i < num_channel; i++) {
        for (int j = 0; j < member_channel[i].size(); j++) {
            if ((*temp_edge)[member_channel[i][j]].HV == 'H') {
                for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.first; k++) {
                    if (sol_Q[i]>=0) {
                        (*flow_rate)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][k] = sol_Q[i];
                    }
                    else{
                        (*flow_rate)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][k] = (-1)*sol_Q[i];
                    }
                    
                    (*channel_info)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][k] = (*temp_edge)[member_channel[i][j]].channel;
                }
            }
            else {
                for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.second; k++) {
                    if (sol_Q[i]>=0) {
                        (*flow_rate)[k][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = sol_Q[i];
                    }
                    else{
                        (*flow_rate)[k][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = (-1)*sol_Q[i];
                    }
                    
                    (*channel_info)[k][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = (*temp_edge)[member_channel[i][j]].channel;
                }
            }
        }
    }
    
    for (int i = 0; i < (*temp_node).size(); i++) {
        if ((*temp_node)[i].type == 'b') {
            //cout <<(*temp_node)[i].num << " " << (*temp_node)[i].edges.size() << endl;
            (*flow_rate)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] = 0;
            for (int j = 0; j < (*temp_node)[i].edges.size(); j++) {
                //cout << (*temp_edge)[(*temp_node)[i].edges[j]].channel << " " << channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].first << " " << channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].second << endl;
                if ( channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].first == (*temp_node)[i].num) {
                    if (sol_Q[(*temp_edge)[(*temp_node)[i].edges[j]].channel] < 0) {
                        (*flow_rate)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] -= sol_Q[(*temp_edge)[(*temp_node)[i].edges[j]].channel];
                        //cout << "-" << (*temp_edge)[(*temp_node)[i].edges[j]].channel << endl;
                    }
                }
                if (channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].second == (*temp_node)[i].num){
                    if (sol_Q[(*temp_edge)[(*temp_node)[i].edges[j]].channel] >= 0) {
                        (*flow_rate)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += sol_Q[(*temp_edge)[(*temp_node)[i].edges[j]].channel];
                        //cout << "+" << (*temp_edge)[(*temp_node)[i].edges[j]].channel << endl;
                    }
                }
            }
            //cout<< endl << endl;
        }
    }
    
   /* cout << "flow_rate:" << endl;
    for (int i = 0; i < (*flow_rate).size(); i++) {
        for (int j = 0; j < (*flow_rate)[i].size(); j++) {
            cout << (*flow_rate)[i][j] << "\t";
        }
        cout << endl;
    }
    */
}

void matrix::fill_direction(vector <node> *temp_node , vector <edge_info> *temp_edge, vector < vector <int> > *direction){
    int current_edge;
    int current_node;
    for (int i = 0; i < num_channel; i++) {
        if (sol_Q[i] >= 0) {
            current_node = channel_dir[i].first;
        }
        else{
            current_node = channel_dir[i].second;
        }
        
       // cout << "current_node " << current_node << " ";
       
        current_edge = -1;
        if ( (*temp_edge)[member_channel[i][0]].nodes.first == current_node || (*temp_edge)[member_channel[i][0]].nodes.second == current_node){
            current_edge = 0;
        }
        else if ((*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.first == current_node || (*temp_edge)[member_channel[i][member_channel[i].size()-1]].nodes.second == current_node){
            current_edge = member_channel[i].size()-1;
        }
        
       // cout << "current_edge " << current_edge << endl;
        // 1234: EWSN  1248:ESWN
        if (current_edge == 0) {
            for (int j = 0; j < member_channel[i].size(); j++) {
                if ((*temp_edge)[member_channel[i][j]].HV == 'H') {
                    if (current_node == (*temp_edge)[member_channel[i][j]].nodes.first) {
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first+1; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.first; k++) {
                            
                            (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][k] = 1;
                            
                            if (j == 0){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 1;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.second;
                    }
                    else if (current_node == (*temp_edge)[member_channel[i][j]].nodes.second){
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.first-1; k++) {
                           
                            (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][k] = 4;//2;
                            if (j == 0){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.first] = 4;//2;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.first;
                    }
                }
                else { //V
                    if (current_node == (*temp_edge)[member_channel[i][j]].nodes.first) {
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second+1; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.second; k++) {
                           
                            (*direction)[k][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 8;//4;
                            if (j == 0){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 8;//4;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.second;
                    }
                    else if (current_node == (*temp_edge)[member_channel[i][j]].nodes.second){
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.second-1; k++) {
                           
                            (*direction)[k][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 2;//3;
                            if (j == 0){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 2;//3;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.first;
                    }
                }
            }
        }
        else {
            for (int j = member_channel[i].size()-1 ; j >= 0; j--) {
                if ((*temp_edge)[member_channel[i][j]].HV == 'H') {
                    if (current_node == (*temp_edge)[member_channel[i][j]].nodes.first) {
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first+1; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.first; k++) {
                          
                            (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][k] = 1;
                            
                            if (j == member_channel[i].size()-1){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 1;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.second;
                    }
                    else if (current_node == (*temp_edge)[member_channel[i][j]].nodes.second){
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.first-1; k++) {
                           
                            (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][k] = 4;//2;
                            if (j == member_channel[i].size()-1){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.first] = 4;//2;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.first;
                    }
                }
                else { //V
                    if (current_node == (*temp_edge)[member_channel[i][j]].nodes.first) {
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second+1; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.second; k++) {
                           
                            (*direction)[k][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 8;//4;
                            if (j == member_channel[i].size()-1){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 8;//4;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.second;
                    }
                    else if (current_node == (*temp_edge)[member_channel[i][j]].nodes.second){
                        for (int k = (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.second; k <= (*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.second-1; k++) {
                           
                            (*direction)[k][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 2;//3;
                            if (j == member_channel[i].size()-1){
                                (*direction)[(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.second].coordinate.second][(*temp_node)[(*temp_edge)[member_channel[i][j]].nodes.first].coordinate.first] = 2;//3;
                            }
                        }
                        current_node = (*temp_edge)[member_channel[i][j]].nodes.first;
                    }
                }
            }
        }
    }
  ////// 1248:ESWN
    for (int i = 0; i < (*temp_node).size(); i++) {
        if ((*temp_node)[i].type == 'b') {
            (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] = 0;
            for (int j = 0; j < (*temp_node)[i].edges.size(); j++) {
                if ( channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].first == (*temp_node)[i].num) {
                    if (sol_Q[(*temp_edge)[(*temp_node)[i].edges[j]].channel] < 0) {
                        if ((*temp_edge)[(*temp_node)[i].edges[j]].HV == 'H') {
                            if ((*temp_edge)[(*temp_node)[i].edges[j]].nodes.first == (*temp_node)[i].num ) {
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 4;
                            }
                            else{
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 1;
                            }
                        }
                        else{ //V
                            if ((*temp_edge)[(*temp_node)[i].edges[j]].nodes.first == (*temp_node)[i].num ) {
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 2;
                            }
                            else{
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 8;
                            }
                        }
                    }
                }
                else if (channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].second == (*temp_node)[i].num){
                    if (sol_Q[(*temp_edge)[(*temp_node)[i].edges[j]].channel] >= 0) {
                        if ((*temp_edge)[(*temp_node)[i].edges[j]].HV == 'H') {
                            if ((*temp_edge)[(*temp_node)[i].edges[j]].nodes.first == (*temp_node)[i].num ) {
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 4;
                            }
                            else{
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 1;
                            }
                        }
                        else{ //V
                            if ((*temp_edge)[(*temp_node)[i].edges[j]].nodes.first == (*temp_node)[i].num ) {
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 2;
                            }
                            else{
                                (*direction)[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] += 8;
                            }
                        }
                    }
                }
            }
        }
    }
    ////
    /*cout << "\ndirection:" << endl;
    for (int i = 0; i < (*direction).size(); i++) {
        for (int j = 0; j < (*direction)[i].size(); j++) {
            cout << (*direction)[i][j] << "\t";
        }
        cout << endl; 
    }*/
}

void matrix::write_output(int *i, vector < vector <int> > *network, vector <node> *temp_node, vector < vector <long double> > *flow_rate, vector < vector <int> > *direction, vector < vector <int> > *channel_info){//const char *output_flow, const char *output_direction,
    vector <int> network_col(101,0);
    vector < vector <int> > single_network(101,network_col);
    ostringstream oss;
    string output_network,output_flow,output_direction,output_channel_info,output_node,num;
    oss.str("");
    oss <<  "flowrate_" << *i;
    output_flow = oss.str();
    oss.str("");
    oss <<  "direction_" << *i;
    output_direction = oss.str();
    oss.str("");
    oss <<  "network_" << *i;
    output_network = oss.str();
    oss.str("");
    oss <<  "channel_info_" << *i;
    output_channel_info = oss.str();
    oss.str("");
    oss <<  "node_info_" << *i;
    output_node = oss.str();
    cout << output_network << " " << output_flow << " " << output_direction << " " << output_channel_info << " " << output_node <<endl;
    ofstream network_out(output_network.c_str());
    ofstream flowrate_out(output_flow.c_str());
    ofstream direction_out(output_direction.c_str());
    ofstream channel_info_out(output_channel_info.c_str());
    ofstream node_info_out(output_node.c_str());
    /////// flowrate direction channel
    for (int i = 0; i < (*flow_rate).size(); i++) {
        for (int j = 0; j < (*flow_rate)[i].size(); j++) {
            flowrate_out << setw(10) << (*flow_rate)[i][j] << "\t";
            direction_out << (*direction)[i][j] << " ";
            channel_info_out << setw(2) << (*channel_info)[i][j] << " ";
        }
        flowrate_out << endl;
        direction_out << endl;
        channel_info_out << endl;
    }

    channel_info_out << endl;
    channel_info_out << "channel_length :" << endl;
    //cout << "channel_length.size" << channel_length.size() << " " << "num_channel" << num_channel << endl;
    for (int i = 0; i < channel_length.size(); i++) {
        channel_info_out << i << ": " << channel_length[i] << endl;
    }
    ///// network
    single_network = (*network);
    for (int i = 0; i < (*temp_node).size(); i++) {
        if ((*temp_node)[i].type == 'b' || (*temp_node)[i].type == 'c') {
            single_network[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] = 4;
        }
    }
   
    for (int i = 0; i < single_network.size(); i++) {
        for (int j = 0; j < single_network[i].size(); j++) {
            network_out << single_network[i][j] << " ";
        }
        network_out << endl;
    }
    ///// node
    single_network = (*network);
    for (int i = 0; i < (*temp_node).size(); i++) {
        if ((*temp_node)[i].type == 'b') {
            single_network[(*temp_node)[i].coordinate.second][(*temp_node)[i].coordinate.first] = (*temp_node)[i].num;
        }
    }
    
    for (int i = 0; i < single_network.size(); i++) {
        for (int j = 0; j < single_network[i].size(); j++) {
            node_info_out << setw(2) << single_network[i][j] << " ";
        }
        node_info_out << endl;
    }
}














///////////////
void matrix::get_path(vector <node> *temp_node, vector <edge_info> *temp_edge){
    num_path = 0;
    vector <int> path_edge_member;
    vector <int> record_node((*temp_edge).size()-2);
    for (int i = 0; i < (*temp_node).size(); i++) {
        if((*temp_node)[i].type == 'i'){
            //cout << (*temp_node)[i].num << endl;
            record_node.resize((*temp_edge).size()-2,0);
            DFS_path(i, temp_node, temp_edge, path_edge_member, record_node);
            // cout << "path done" << endl;
        }
    }
    /*   for( int i = 0; i < member_path.size(); i++){
     cout << "path_" << i << ": " ;
     for (int j = 0; j < member_path[i].size(); j++) {
     cout << member_path[i][j] << " ";
     }
     cout << endl;
     }*/
    cout << "num_path: " << num_path << endl;
}

void matrix::DFS_path(int nodex, vector <node> *temp_node, vector <edge_info> *temp_edge, vector <int> path_edge_member, vector <int> record_node){//
    record_node [nodex] = 1;
    for (int i = 0; i < (*temp_node)[nodex].edges.size(); i++) {
        if ( record_node[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first] != 1 || record_node[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second] != 1 ){
            if ( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first != nodex) {
                if ( (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type != 'o' && (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type != 'I' && (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type != 'O' ){
                    record_node [(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first] = 1;
                    (path_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    DFS_path( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first, temp_node, temp_edge, path_edge_member, record_node);//
                    (path_edge_member).erase ((path_edge_member).begin()+(path_edge_member).size()-1);
                }
                else if ( (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first].type == 'o' ){
                    record_node [(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.first] = 1;
                    (path_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    member_path.push_back((path_edge_member));
                    num_path++;
                    (path_edge_member).erase ((path_edge_member).begin()+(path_edge_member).size()-1);
                }
            }
            else if ( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second != nodex) {
                if ( (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second].type != 'o' && (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second].type != 'I' && (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second].type != 'O' ){
                    record_node [(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second] = 1;
                    (path_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    DFS_path( (*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second, temp_node, temp_edge, path_edge_member, record_node);//
                    (path_edge_member).erase ((path_edge_member).begin()+(path_edge_member).size()-1);
                }
                else if ( (*temp_node)[(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second].type == 'o' ){
                    record_node [(*temp_edge)[(*temp_node)[nodex].edges[i]].nodes.second] = 1;
                    (path_edge_member).push_back((*temp_node)[nodex].edges[i]);
                    member_path.push_back((path_edge_member));
                    num_path++;
                    (path_edge_member).erase ((path_edge_member).begin()+(path_edge_member).size()-1);
                }
            }
        }
    }
}

void matrix::get_funtion(vector <node> *temp_node , vector <edge_info> *temp_edge, long double unit_pressure_drop ){
    vector <long double> temp_row(num_channel+1,0);
    vector <int> path_channel(num_channel,0);
    long double temp_length = 0;
    vector <int> channels;
    ofstream fout("all_functions.txt");
    
    for (int i = 0; i < (*temp_node).size(); i++) { //node
        if ((*temp_node)[i].type == 'b'){
            //  cout << "node_" << i << endl;
            for (int j = 0; j < (*temp_node)[i].edges.size(); j++) {
                if (channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].first== (*temp_node)[i].num) {
                    temp_row[ (*temp_edge)[(*temp_node)[i].edges[j]].channel ] = -1;
                }
                else if (channel_dir[(*temp_edge)[(*temp_node)[i].edges[j]].channel].second == (*temp_node)[i].num){
                    temp_row[ (*temp_edge)[(*temp_node)[i].edges[j]].channel ] = 1;
                }
            }
            all_function.push_back(temp_row);
            temp_row.clear();
            temp_row.resize(num_channel+1);
        }
    }
    
    cout << "\nbranch: " << endl;
    node_func_num = all_function.size();/////////////////
    cout << "node_function num " << node_func_num << endl;
    cout << "node_func done!" << endl;
    /*for (int i = 0; i < all_function.size(); i++) {
     for (int j = 0 ; j < all_function[i].size() ; j++) {
     cout << all_function[i][j] << " " ;
     }
     cout << endl;
     }*/
    //getchar();
    
    
    for (int i = 0; i < member_path.size() ; i++) { //path
        path_channel.clear();
        path_channel.resize(num_channel,0);
        channels.clear();
        for (int j = 0; j < member_path[i].size(); j++) {
            if (channels.size() == 0 || channels[channels.size()-1]!= (*temp_edge)[member_path[i][j]].channel) {
                channels.push_back((*temp_edge)[member_path[i][j]].channel);
            }
        }
        /*cout << "path_" << i << " channels ";
         for (int j = 0; j < channels.size(); j++) {
         cout << channels[j] << " " ;
         }
         cout << endl;
         getchar();*/
        ///////
        for (int j = 0; j < channels.size(); j++) {
            if ( channels.size() >= 2) {
                if ( j != channels.size()-1) {
                    if (channel_dir[channels[j]].first != channel_dir[channels[j+1]].first && channel_dir[channels[j]].first != channel_dir[channels[j+1]].second) {
                        path_channel[channels[j]] = 1;
                    }
                    else if(channel_dir[channels[j]].second != channel_dir[channels[j+1]].first && channel_dir[channels[j]].second != channel_dir[channels[j+1]].second){
                        path_channel[channels[j]] = -1;
                    }
                }
                else{
                    if (channel_dir[channels[j]].first != channel_dir[channels[j-1]].first && channel_dir[channels[j]].first != channel_dir[channels[j-1]].second) {
                        path_channel[channels[j]] = -1;
                    }
                    else if(channel_dir[channels[j]].second != channel_dir[channels[j-1]].first && channel_dir[channels[j]].second != channel_dir[channels[j-1]].second){
                        path_channel[channels[j]] = 1;
                    }
                }
            }
            else {
                if ((*temp_node)[channel_dir[channels[j]].first].type == 'i') {
                    path_channel[channels[j]] = 1;
                }
                else if ((*temp_node)[channel_dir[channels[j]].second].type == 'i'){
                    path_channel[channels[j]] = -1;
                }
            }
        }
        //////
        /* cout << "path_" << i << " channel: ";
         for (int j = 0; j < path_channel.size(); j++){
         cout << path_channel[j] << " ";
         }
         cout << endl;*/
        //getchar();
        
        for (int j = 0; j < path_channel.size(); j++) {
            temp_length = 0;
            if (path_channel[j] == 1 || path_channel[j] == -1){
                for (int k = 0; k < member_channel[j].size(); k++) {
                    temp_length += (*temp_edge)[member_channel[j][k]].length;
                }
                temp_row[j] = path_channel[j]*temp_length;
            }
        }
        /* cout << "length: ";
         for (int j = 0; j < temp_row.size(); j++) {
         cout << temp_row[j] << " ";
         }
         cout << endl;*/
        //getchar();
        
        all_function.push_back(temp_row);
        all_function[all_function.size()-1][num_channel] = unit_pressure_drop;
        temp_row.clear();
        temp_row.resize(num_channel+1);
    }
    cout << "\nall_function" << endl;
    for (int i = 0; i < all_function.size(); i++) {
        for (int j = 0 ; j < all_function[i].size() ; j++) {
            // cout << all_function[i][j] << "\t" ;
            fout << setw(5) << all_function[i][j] << " " ;
        }
        //cout << endl;
        fout << endl;
    }
    cout << endl;
    cout << "all function num " << all_function.size() << endl;
    for (int i = 0; i < all_function.size(); i++) {
        functions.push_back(i);
    }
    ////////channel length//////
    for (int j = 0; j < num_channel; j++) {
        temp_length = 0;
        for (int k = 0; k < member_channel[j].size(); k++) {
            temp_length += (*temp_edge)[member_channel[j][k]].length;
        }
        channel_length.push_back(temp_length);
    }
    ////////
}

bool compare (record_info a ,record_info b){
    return a.num < b.num;
}

void matrix::initial_matrix(){ //vector < int > *equal_eq
    matrix_Q.clear();
    store_func.clear();
    store_func.resize(0);
    ////////node functions + flow
    for (int i = 0 ; i < node_func_num ; i++){///
        matrix_Q.push_back(all_function[i]);
        store_func.push_back(i);
    }
    
    for (int i = node_func_num; i < all_function[0].size()-1; i++){///
        matrix_Q.push_back(all_function[functions[i]]);
        store_func.push_back(functions[i]);
        //cout << functions[i] << " ";
    }
    cout << "functions" <<endl;
    for (int i = 0; i < functions.size(); i++) {
        cout <<functions[i] << " ";
    }
    cout << endl;
    cout << "used functions "<< endl;
    for (int i = 0; i < store_func.size(); i++) {
        cout << store_func[i] << " ";
    }
    cout << endl;
    //cout << endl;
}


void matrix::check_matrix_Q(){
    vector < vector <long double> > matrix_copy;
    matrix_copy = matrix_Q;
    record_info temp_record;
    vector <record_info> record;
    vector <int> store_func_copy;
    store_func_copy.clear();
    store_func_copy = store_func;
    /*cout << "store_func_copy"<< endl;
     for (int i = 0; i < store_func_copy.size(); i++) {
     cout << store_func_copy[i] << " ";
     }
     cout << endl;
     ofstream fout("after_check.txt");*/
    for (int j = 0; j < matrix_Q[0].size()-1 ; j++){
        temp_record.column = j;
        temp_record.num = 0;
        record.push_back(temp_record);
        for ( int i = 0; i < matrix_Q.size() ; i++){
            if (matrix_Q[i][j] != 0){
                record[record.size()-1].num++;
                record[record.size()-1].row.push_back(i);
            }
        }
    }
    //cout << 5555555 << " " << matrix_copy[5].size() << endl;
    for (int i = 0; i < matrix_Q[0].size()-1 ; i++){
        sort (record.begin(),record.end(),compare);
        matrix_Q[record[0].column] = matrix_copy[record[0].row[0]];//
        //cout << 2 << endl;
        store_func[record[0].column] = store_func_copy[record[0].row[0]];/////
        //cout << 3 << endl;
        for (int j = 1; j < record.size() ; j++){
            for ( int k = 0 ; k < record[j].row.size(); k++){
                if (record[j].row[k] == record[0].row[0]){
                    record[j].row.erase(record[j].row.begin()+k);
                    record[j].num--;
                }
            }
        }
        //cout << 4 << endl;
        record.erase(record.begin());
        //cout << 5 << endl;
    }
    //cout << 6666666 << endl;
    /*cout << "after check" << endl;
     for (int i = 0; i < matrix_Q.size(); i++){
     for (int j = 0; j < matrix_Q[i].size(); j++){
     cout << matrix_Q[i][j] << "\t";
     fout << matrix_Q[i][j] << "\t";
     }
     cout << endl;
     fout << endl;
     }
     cout << endl;*/
    cout << "after check "<< endl;
    for (int i = 0; i < store_func.size(); i++) {
        cout << store_func[i] << " ";
    }
    cout << endl;
}

int  matrix::Gaussian_Elimination(){
    long double a,b;
    for (int j = 0; j < matrix_Q[0].size()-1; j++ ){
        //////
        if (matrix_Q[j][j] == 0){
            cout << "111 " << store_func[j] << endl;
            if (store_func[j] < node_func_num) {///
                //cout << node_func_num+1 << " " << store_func[node_func_num+1] << endl;
                //getchar();
                functions.push_back(functions[node_func_num]);///
                functions.erase(functions.begin()+node_func_num);///
            }
            else{
                for (int i = 0;  i < functions.size(); i++) {
                    if (functions[i] == store_func[j]) {
                        functions.erase(functions.begin()+i);
                        break;
                    }
                }
                functions.push_back(store_func[j]);
            }
            return j;
        }
        ///////
        for (int i = 0; i < matrix_Q.size(); i++){
            if ( j == i ){
                if ( matrix_Q[i][j] != 1 ){
                    a = matrix_Q[i][j];
                    for (int k = j ; k < matrix_Q[0].size() ; k++){
                        matrix_Q[i][k] /= a;
                    }
                }
            }
            else {
                if ( matrix_Q[i][j] != 0 ){
                    a = matrix_Q[i][j];
                    b = matrix_Q[j][j];
                    int counter = 0;
                    for(int k = j; k < matrix_Q[0].size(); k++){
                        matrix_Q[i][k] += (-1)*matrix_Q[j][k]/b*a;
                    }
                    
                    for(int k = 0; k < matrix_Q[0].size(); k++){
                        if (matrix_Q[i][k] != 0){
                            counter++;
                        }
                    }
                    
                    if (counter == 0){ //same
                        cout << "222 " << store_func[i] << endl;
                        if (store_func[i] < node_func_num) {///
                            functions.erase(functions.begin()+j);///
                        }
                        else {//
                            for (int k = 0;  k < functions.size(); k++) {
                                if (functions[k] == store_func[i]) {
                                    functions.erase(functions.begin()+k);
                                    break;
                                }
                            }
                        }//
                        return i;
                    }
                }
            }
        }
    }
    cout << "sol: " << num_channel << endl;
    for (int i = 0; i < matrix_Q.size(); i++){
        //for (int j = 0; j < matrix_Q[i].size(); j++){
        //cout << matrix_Q[i][j] << "\t";
        cout << i+1 << " " << matrix_Q[i][matrix_Q[0].size()-1] <<endl;//<< "\t";
        /*if (matrix_Q[i][matrix_Q[0].size()-1] == 0) {
         cout << "  000000 " ;
         getchar();
         }*/
        //}
        // cout << endl;
    }
    cout << endl;
    return -1;
}

void matrix::check_sol(){
    long double sol;
    //temp_row[j] = path_channel[j]*temp_length;
    for (int i = 0; i < all_function.size(); i++) {//
        sol = 0;
        //cout << matrix_Q.size() << " " << all_function[i].size()-1 << endl;
        for (int j = 0; j < all_function[i].size()-1; j++) {
            sol += all_function[i][j] *  matrix_Q[j][matrix_Q[0].size()-1];
        }
        cout << "function" << i << " " << sol << endl;
    }
}
