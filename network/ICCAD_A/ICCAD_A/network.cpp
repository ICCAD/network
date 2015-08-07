//
//  network.cpp
//  network
//
//  Created by 張志銘 on 2015/7/18.
//  Copyright (c) 2015年 cmchang. All rights reserved.
// 

#include "network.h"

void network_reverse (vector < vector <int> > *network){
    vector < vector <int> > copy_network;
    copy_network = (*network);
    for (int i = 0; i < (*network).size(); i++) {
        (*network)[i] = copy_network[(*network).size()-1-i];
    }
    for (int i = 0; i < (*network).size(); i++) {
        for (int j = 0; j < (*network)[i].size(); j++) {
            cout << (*network)[i][j] << " ";
        }
        cout << endl;
    }
}

void network_graph( vector < vector <int> > *network, vector <node> *tempnode, vector <edge_info> *edges){
    node temp;
    edge_info temp_edge;
    vector <int> network_col((*network)[0].size(),-2);//
    vector < vector <int> > network_state((*network).size(),network_col);//
    cout << (*network)[0].size() << " " << (*network).size() << endl;
    for ( int i = 0; i < (*network).size() ; i++) {
        for ( int j = 0; j < (*network)[i].size(); j++) {
            if ((*network)[i][j] == 1 || (*network)[i][j] == 2  || (*network)[i][j] == 3) {
                network_state[i][j] = -1;
            }
			
			if ((*network)[i][j] == 2 || (*network)[i][j] == 3 ) {
				temp.num = (*tempnode).size();
				temp.coordinate.first = j;
				temp.coordinate.second = i;
				if ((*network)[i][j] == 2){
					temp.type = 'i';
				}
				else{
					temp.type = 'o';
				}
				(*tempnode).push_back(temp);
				network_state[i][j] = temp.num;
			}
			else if ( (*network)[i][j] == 1 ) { //flow
				if ( i == 0 ) {
					if ( j == 0 ){
						if ( ((*network)[i+1][j] != -1 && (*network)[i+1][j] != 0) && ((*network)[i][j+1] != -1 && (*network)[i][j+1] != 0) ){
							temp.num = (*tempnode).size();
							temp.coordinate.first = j;
							temp.coordinate.second = i;
							temp.type = 'c';
							(*tempnode).push_back(temp);
							network_state[i][j] = temp.num;
						}
					}
					else if ( j == (*network).size()-1){
						if ( ((*network)[i+1][j] != -1 && (*network)[i+1][j] != 0) && ((*network)[i][j-1] != -1 && (*network)[i][j-1] != 0) ){
							temp.num = (*tempnode).size();
							temp.coordinate.first = j;
							temp.coordinate.second = i;
							temp.type = 'c';
							(*tempnode).push_back(temp);
							network_state[i][j] = temp.num;
						}
					}
					else{
						if ( ((*network)[i+1][j] != -1 && (*network)[i+1][j] != 0) && (((*network)[i][j-1] != -1 && (*network)[i][j-1] != 0) || ((*network)[i][j+1] != -1 && (*network)[i][j+1] != 0))){
							temp.num = (*tempnode).size();
							temp.coordinate.first = j;
							temp.coordinate.second = i;
							temp.type = 'N';
							(*tempnode).push_back(temp);
							network_state[i][j] = temp.num;
						}
					}	
				}
				else if ( i == (*network).size()-1  ){
					if ( j == 0 ){
						if ( ((*network)[i-1][j] != -1 && (*network)[i-1][j] != 0) &&  ((*network)[i][j+1] != -1 && (*network)[i][j+1] != 0) ){
							temp.num = (*tempnode).size();
							temp.coordinate.first = j;
							temp.coordinate.second = i;
							temp.type = 'c';
							(*tempnode).push_back(temp);
							network_state[i][j] = temp.num;
						}
					}
					else if ( j == (*network).size()-1){
						if ( ((*network)[i-1][j] != -1 && (*network)[i-1][j] != 0) &&  ((*network)[i][j-1] != -1 && (*network)[i][j-1] != 0) ){
							temp.num = (*tempnode).size();
							temp.coordinate.first = j;
							temp.coordinate.second = i;
							temp.type = 'c';
							(*tempnode).push_back(temp);
							network_state[i][j] = temp.num;
						}
					}
					else{
						if ( ((*network)[i-1][j] != -1 && (*network)[i-1][j] != 0) && (((*network)[i][j-1] != -1 && (*network)[i][j-1] != 0) || ((*network)[i][j+1] != -1 && (*network)[i][j+1] != 0))){
							temp.num = (*tempnode).size();
							temp.coordinate.first = j;
							temp.coordinate.second = i;
							temp.type = 'N';
							(*tempnode).push_back(temp);
							network_state[i][j] = temp.num;
						}
					}
				}
				else {
					if ( (((*network)[i-1][j] != -1 && (*network)[i-1][j] != 0) || ((*network)[i+1][j] != -1 && (*network)[i+1][j] != 0)) && (((*network)[i][j-1] != -1 && (*network)[i][j-1] != 0) || ((*network)[i][j+1] != -1 && (*network)[i][j+1] != 0))){
						temp.num = (*tempnode).size();
						temp.coordinate.first = j;
						temp.coordinate.second = i;
						temp.type = 'N';
						(*tempnode).push_back(temp);
						network_state[i][j] = temp.num;
					}
				}
			}
        }
    }
	///////////////
    for (int i = 0; i < network_state.size(); i++) {
        for (int j = 0; j < network_state[i].size(); j++) {
            cout << network_state[i][j] << "\t";
        }
        cout << endl;
    }
	//////////////
	temp.num = (*tempnode).size(); // inlet size-2
	temp.type = 'I';
	temp.coordinate.first = -1;
    temp.coordinate.second = -1;
	(*tempnode).push_back(temp);
	temp.num = (*tempnode).size(); // outlet size-1
	temp.type = 'O';
	temp.coordinate.first = -2;
    temp.coordinate.second = -2;
	(*tempnode).push_back(temp);
	
	 for ( int i = 0; i < (*network).size(); i++) {
		for ( int j = 0; j < (*network)[i].size(); j++) {
			if ( (*network)[i][j] == 2 ){ //inlet
				temp_edge.length = 0;
				temp_edge.HV = 'N';
				temp_edge.nodes.first = (*tempnode).size()-2;
				temp_edge.nodes.second = network_state[i][j];
				(*edges).push_back(temp_edge);
				(*tempnode)[network_state[i][j]].edges.push_back((*edges).size()-1);
				(*tempnode)[(*tempnode).size()-2].edges.push_back((*edges).size()-1);
			}
			else if ( (*network)[i][j] == 3 ){ //outlet
				temp_edge.length = 0;
				temp_edge.HV = 'N';
				temp_edge.nodes.first = (*tempnode).size()-1;
				temp_edge.nodes.second = network_state[i][j];
				(*edges).push_back(temp_edge);
				(*tempnode)[network_state[i][j]].edges.push_back((*edges).size()-1);
				(*tempnode)[(*tempnode).size()-1].edges.push_back((*edges).size()-1);
			}
		}
	 }
	//////////////
    int current_node = -1;
    pair < int , int > cells_location;//x y
    for (int j = 0; j < network_col.size() ; j++) {
        for (int i = network_state.size()-1; i >= 0 ; i--) {
            if ( network_state[i][j] >= 0 ) {
                if (current_node == -1) {
                    current_node = network_state[i][j];
                }
                else{
					temp_edge.nodes.first = network_state[i][j];
					temp_edge.nodes.second = current_node;
                    temp_edge.HV = 'V';
					(*edges).push_back(temp_edge);
                    (*tempnode)[current_node].edges.push_back((*edges).size()-1);
					(*tempnode)[network_state[i][j]].edges.push_back((*edges).size()-1);
                    
					current_node = network_state[i][j];
                }
            }
            else if( network_state[i][j] == -2 ){
                current_node = -1;
            }
        }
    }
    current_node = -1;
    for (int i = network_col.size()-1 ; i >= 0 ; i--) {
        for (int j = 0; j < network_state.size() ; j++) {
            if ( network_state[i][j] != -1 && network_state[i][j] != -2 ) {
                if (current_node == -1) {
                    current_node = network_state[i][j];
                }
                else{
					temp_edge.nodes.first = current_node;
					temp_edge.nodes.second = network_state[i][j];
                    temp_edge.HV = 'H';
					(*edges).push_back(temp_edge);
                    (*tempnode)[current_node].edges.push_back((*edges).size()-1);
					(*tempnode)[network_state[i][j]].edges.push_back((*edges).size()-1);
                    
					current_node = network_state[i][j];
                }
            }
            else if( network_state[i][j] == -2 ){
                current_node = -1;
            }
        }
    }

	for (int i = 0; i < (*tempnode).size(); i++){
		if ( (*tempnode)[i].type == 'N'){
			if ( (*tempnode)[i].edges.size() <= 2){
				(*tempnode)[i].type = 'c';
			}
			else{
				(*tempnode)[i].type = 'b';
			}
		}
	}
	
	for (int i = 0; i < (*edges).size(); i++){
		if ( (*edges)[i].HV != 'N'){
			if ( (*edges)[i].HV == 'V'){
				(*edges)[i].length =  (*tempnode)[(*edges)[i].nodes.second].coordinate.second -  (*tempnode)[(*edges)[i].nodes.first].coordinate.second;
			}
			else if ( (*edges)[i].HV == 'H'){
				(*edges)[i].length =  (*tempnode)[(*edges)[i].nodes.second].coordinate.first -  (*tempnode)[(*edges)[i].nodes.first].coordinate.first;
			}
			
			if ( (*tempnode)[(*edges)[i].nodes.second].type == 'i' || (*tempnode)[(*edges)[i].nodes.second].type == 'o' || (*tempnode)[(*edges)[i].nodes.first].type == 'i' || (*tempnode)[(*edges)[i].nodes.first].type == 'o'){
				(*edges)[i].length += 0.5;		
			}
		}
	}
}