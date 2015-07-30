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
    for (int i = 0; i < (*temp_node).size(); i++) {
        if((*temp_node)[i].type != 'c' && (*temp_node)[i].type != 'I' && (*temp_node)[i].type != 'O'){
            cout << (*temp_node)[i].num << endl;
            DFS_edge(i, temp_node, temp_edge, &temp_edge_member, &record_edge);
            // cout << "edge done" << endl;
        }
        break;
    }
    for (int i = 0; i < (*temp_edge).size() ; i++){
        (*temp_edge)[i].channel = -1;
    }
    for( int i = 0; i < member_channel.size(); i++){
        cout << "channel_" << i << ": " ;
        for (int j = 0; j < member_channel[i].size(); j++) {
            (*temp_edge)[member_channel[i][j]].channel = i;
            cout << member_channel[i][j] << " ";
        }
        cout << endl;
    }
    cout << "num_channel: " << num_channel << endl;
    for (int i = 0; i < (*temp_edge).size(); i++){
        cout << "edge_" << i << ": channel_" << (*temp_edge)[i].channel << endl;
    }
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

////////////////////
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
    for( int i = 0; i < member_path.size(); i++){
        cout << "path_" << i << ": " ;
        for (int j = 0; j < member_path[i].size(); j++) {
            cout << member_path[i][j] << " ";
        }
        cout << endl;
    }
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
    cout << "\nflow_direction"<< endl;
    for (int i = 0; i < channel_dir.size(); i++) {
        cout << "channel_" << i << " in: " <<channel_dir[i].first << " out: " << channel_dir[i].second << endl;
    }
}

void matrix::get_funtion(vector <node> *temp_node , vector <edge_info> *temp_edge, long double unit_pressure_drop){
    vector <long double> temp_row(num_channel+1,0);
    vector <int> path_channel(num_channel,0);
    long double temp_length = 0;
    vector <int> channels(0);
    
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
    node_func_num = all_function.size();
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
        cout << "path_" << i << " channel: ";
        for (int j = 0; j < path_channel.size(); j++){
            cout << path_channel[j] << " ";
        }
        cout << endl;
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
            cout << all_function[i][j] << "\t" ;
        }
        cout << endl;
    }
    cout << endl;
}


bool compare (record_info a ,record_info b){
    return a.num < b.num;
}

void matrix::initial_matrix(vector < int > *equal_eq){
    matrix_Q.clear();
    store_func.clear();
    store_func.resize(0);
    ////////node functions
    for (int i = 0 ; i < node_func_num ; i++){
        matrix_Q.push_back(all_function[i]);
        store_func.push_back(i);
    }
    
    if ((*equal_eq).size() == 0){
        for (int i = node_func_num; i < all_function[0].size()-1; i++){
            matrix_Q.push_back(all_function[i]);
            store_func.push_back(i);
        }
    }
    else{
        for (int i = node_func_num,k = node_func_num; i < all_function[0].size()-1 && k < all_function.size(); k++){
            for (int j = 0; j < (*equal_eq).size(); j++){
                if (k == (*equal_eq)[j]){
                    break;
                }
                if ( j == (*equal_eq).size()-1){
                    matrix_Q.push_back(all_function[k]);
                    store_func.push_back(k);
                    i++;
                }
            }
        }
    }
    cout << "store_func: ";
    for ( int i = 0; i < store_func.size(); i++){
        cout << store_func[i] << " ";
    }
    cout << endl;
    cout << "initial" <<endl;
    for (int i = 0;i < matrix_Q.size();i++){
        for (int j = 0; j < matrix_Q[i].size(); j++){
            cout<< matrix_Q[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void matrix::check_matrix_Q(){
    vector < vector <long double> > matrix_copy;
    matrix_copy = matrix_Q;
    record_info temp_record;
    vector <record_info> record;
    vector <int> store_func_copy;
    store_func_copy.clear();
    //store_func_copy.resize();
    store_func_copy = store_func;
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
    
    for (int i = 0; i < matrix_Q[0].size()-1 ; i++){
        sort (record.begin(),record.end(),compare);
        matrix_Q[record[0].column] = matrix_copy[record[0].row[0]];
        store_func[record[0].column] = store_func_copy[record[0].row[0]];/////
        for (int j = 1; j < record.size() ; j++){
            for ( int k = 0 ; k < record[j].row.size(); k++){
                if (record[j].row[k] == record[0].row[0]){
                    record[j].row.erase(record[j].row.begin()+k);
                    record[j].num--;
                }
            }
        }
        record.erase(record.begin());
    }
    cout << "after check" << endl;
    for (int i = 0; i < matrix_Q.size(); i++){
        for (int j = 0; j < matrix_Q[i].size(); j++){
            cout << matrix_Q[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int  matrix::Gaussian_Elimination(vector < int > *equal_eq){
    long double a,b;
    for (int j = 0; j < matrix_Q[0].size()-1; j++ ){
        if (matrix_Q[j][j] == 0){
            (*equal_eq).push_back(store_func[j]);
            cout << "111 " << store_func[j] << endl;
            cout << (*equal_eq)[(*equal_eq).size()-1] << endl;
            return j;
        }
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
                        (*equal_eq).push_back(store_func[i]);
                        cout << "222 " << store_func[i] << endl;
                        return i;
                    }
                }
            }
        }
    }
    cout << "sol: " << num_channel << endl;
    for (int i = 0; i < matrix_Q.size(); i++){
        for (int j = 0; j < matrix_Q[i].size(); j++){
            cout << matrix_Q[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return -1;
}

void matrix::get_pressure_drop(double wc, double hc, double coolant_flow_rate, double unit_pressure_drop, vector <edge_info> *temp_edge){
    double k,dh,Ac,Q,n;
    dh = (2 * wc * hc) / (wc + hc);
    Ac = wc * hc;
    k = 0.02848 / (dh * dh * Ac);
    vector <double> sol_Q;
    vector <int> inlet_channel;
    for (int i = 0; i < member_path.size(); i++) {
        if (inlet_channel.size() == 0 || inlet_channel[inlet_channel.size()-1] != (*temp_edge)[member_path[i][0]].channel) {
            inlet_channel.push_back((*temp_edge)[member_path[i][0]].channel);
        }
    }
    Q = 0;
    cout << "inlet_channel: ";
    for (int i = 0; i < inlet_channel.size(); i++) {
        cout << inlet_channel[i] << " ";
        if (matrix_Q[inlet_channel[i]][matrix_Q[0].size()-1] < 0) {
            Q -= matrix_Q[inlet_channel[i]][matrix_Q[0].size()-1];

        }
        else {
            Q += matrix_Q[inlet_channel[i]][matrix_Q[0].size()-1];
        }
    }
    cout << "\nQ: " << Q << endl;
    cout << "coolant_flow_rate: " << coolant_flow_rate << endl;
    n = coolant_flow_rate / Q;
    for (int i = 0; i < matrix_Q.size(); i++) {
        sol_Q.push_back( n * matrix_Q[i][matrix_Q[0].size()-1] );
    }
    pressure_drop = k * unit_pressure_drop * n;
    cout << "pressure_drop: " << pressure_drop << endl;
}
