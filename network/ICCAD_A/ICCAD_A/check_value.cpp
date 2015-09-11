
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
	
	ifstream fin_net(argv[1]),
	         fin_flow(argv[2]),
			 fin_dir(argv[3]);
	
	vector < vector <int> > net(101, vector <int>(101)),dir(101, vector <int>(101));
	vector < vector <double> > flow(101, vector <double>(101));
	
	for( int i=0;i<101;i++ ){
		for( int j=0;j<101;j++ ){
			fin_net >> net[i][j];
			fin_flow >> flow[i][j];
			fin_dir >> dir[i][j];
		}
	}
	int a;
	int x,y;
	
	while(1){
		cout << "choose net:0 , flow:1, dir:2" << endl;
		cin >> a;
		if(a == 0){
			cout << "cin coor" << endl;
			cin >> y >> x;
			cout << y << " " << x << " " << net[y][x] << endl;
			
		}
		else if(a == 1){
			cout << "cin coor" << endl;
			cin >> y >> x;
			cout << y << " " << x << " " << flow[y][x] << endl;
		}
		else if(a == 2){
			cout << "cin coor" << endl;
			cin >> y >> x;
			cout << y << " " << x << " " << dir[y][x] << endl;
		}
		else{
			continue;
		}
	}
	
	
	return 0;
}