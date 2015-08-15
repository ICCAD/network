#ifndef chip_data_h
#define chip_data_h


#include <map>
#include <fstream>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shellapi.h>
#include <crtdbg.h>

#else // _WIN32

#define	FW_NORMAL	400
#define	FW_BOLD		700

#endif // _WIN32

#include "ExcelFormat.h"

using namespace ExcelFormat;
using namespace std;

struct block {
    string name;
	int lx,ly,width,length;
	double power;
	block(){
		lx = -1;
		ly = -1;
		width = -1;
		length = -1;
		power = -1;
	}
};

struct die {
    string name;
	vector <block> blocks;
};

class chip_data{
	public:
		//chip_info();
		friend class network_generator;
		void write_output(const char *);
		bool read(const char *);
	private:
		vector < vector < vector <int> > > channel;
		vector <die> dies;
		int case_num;
		int layer_num;
		vector <block> constraint;
		double length, width, height;
		double T_max;
		double T_gredient;
};




#endif