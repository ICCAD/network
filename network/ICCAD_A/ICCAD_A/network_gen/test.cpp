
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
	
	ifstream fin(argv[1]);
	
	vector < vector <int> > temp(101, vector <int> (101)),used(101, vector <int> (101)); 
	
	for( int i=0;i<101;i++ ){
		for( int j=0;j<101;j++ ){
			fin >> temp[i][j];
		}
	}
	fin.close();
	for( int i=0;i<101;i++ ){
		for( int j=0;j<101;j++ ){
			used[i][j] = temp[j][100-i];
		}
	}
	for( int i=0;i<101;i++ ){
		for( int j=0;j<101;j++ ){
			if(temp[i][j] != 0){
				used[i][j] = temp[i][j];
			}
		}
	}
	ofstream fout("network_7");
	for( int i=0;i<101;i++ ){
		for( int j=0;j<101;j++ ){
			fout << used[i][j] << " ";
		}
		fout << endl;
	}	
	fout.close();
	
	
	
	
	
	return 0;
}