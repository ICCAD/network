//
//  constraint_check.cpp
//  network
//
//  Created by 張志銘 on 2015/7/29.
//  Copyright (c) 2015年 cmchang. All rights reserved.
//

#include "constraint_check.h"

string read_teperature(const char *t_file, vector < vector <double> > *t_data){
	
	ifstream fin(t_file);
	
	if(!fin){
		cout << "read t_data fail !" << endl;
		return "failure"; 
	}
	double temp_t = 0.0;
	
	for( int i=0;i<101;i++ ){
		vector <double> temp_data;
		for( int j=0;j<101;j++ ){
			fin >> temp_t;
			temp_data.push_back(temp_t);
		}
		t_data->push_back(temp_data);
	}
	return "succeed";
	
}

bool check_MAX_temperature(vector < vector <double> > t_data, double MAX_t){
	
	for( int i=0;i<t_data.size();i++ ){
		for( int j=0;j<t_data[i].size();j++ ){
			if(t_data[i][j] > MAX_t){
				return false;
			}
		}
	}
	return true;
	
}

bool check_teperature_gradient(vector < vector <double> > t_data, double MAX_gradient){
	
	double MIN_t = 1 << 30;
	double MAX_t = 0.0;
	
	for( int i=0;i<t_data.size();i++ ){
		for( int j=0;j<t_data[i].size();j++ ){
			MIN_t = min(MIN_t,t_data[i][j]);
			MAX_t = max(MAX_t,t_data[i][j]);
		}
	}
	if(MAX_t - MIN_t > MAX_gradient){
		return false;
	}
	return true;
	
}

