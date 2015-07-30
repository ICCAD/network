#ifndef CAD_A_H
#define CAD_A_H


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
	int lx,ly,rx,ry;
	double power;
};

struct die {
    string name;
	vector < block > blocks;
};

class flow_network{
	public:
		//flow_network();
		void write_output(const char *);
		void read_file(const char *);
	private:
		vector <vector <vector <int> > > cells;
		vector <die> dies;
		int layer_num;
};




#endif