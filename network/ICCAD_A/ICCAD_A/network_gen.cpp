
#include "network_gen.h"

void network_generator::data_init(chip_data &chip){
	this->chip = chip;
	channel_layer = chip.layer_num - 1;
	alpha = 0.3;
}

void network_generator::network_init(){
	
	heat_network.clear();
	liquid_network.clear();
	vector < vector <double> > temp(101,vector <double> (101,channel_layer*1000));
    vector < vector <int> > temp_liquid(101,vector <int> (101));
    heat_network = temp;
    for (int i=0; i<101; i+=2) {
        for (int j=0; j<101; j+=2) {
            temp_liquid[i][j] = 7;
        }
    }
    for (int i=0; i<channel_layer; i++) {
        liquid_network.push_back(temp_liquid);
    }
	
}

void network_generator::find_network_sol(){
	
	for(int i=0;i<16;i++){
		network_init();
		network_gen(i);
		cout << "seed #1" << endl;
		getchar();
	}
	
	
	
	
}

bool network_generator::network_gen(int seed){
	
	pair <int, int> path_head;
	pair <int, int> inlet[channel_layer*4],outlet[channel_layer*4];
	double efficiency = 1;
	if(seed < 4){
		seed %= 4;
		inlet[0].first = rand()%20 + 10 + 20*seed;
		while(inlet[0].first%2 == 0){
			inlet[0].first = rand()%20 + 10 + 20*seed;
		}
		inlet[0].second = 0;
	}
	else if(seed < 8){
		seed %= 4;
		inlet[0].first = 100;
		inlet[0].second = rand()%20 + 10 + 20*seed;
		while(inlet[0].second%2 == 0){
			inlet[0].second = rand()%20 + 10 + 20*seed;
		}
	}
	else if(seed < 12){
		seed %= 4;
		inlet[0].first = rand()%20 + 10 + 20*seed;
		while(inlet[0].first%2 == 0){
			inlet[0].first = rand()%20 + 10 + 20*seed;
		}
		inlet[0].second = 100;
	}
	else if(seed < 16){
		seed %= 4;
		inlet[0].first = 0;
		inlet[0].second = rand()%20 + 10 + 20*seed;
		while(inlet[0].second%2 == 0){
			inlet[0].second = rand()%20 + 10 + 20*seed;
		}
	}
	liquid_network[0][inlet[0].second][inlet[0].first] = 4;
	cout << inlet[0].first << " " << inlet[0].second << endl;
	path_head = inlet[0];
	int path_length = 1;
	cool_down(path_head, efficiency);
	efficiency = 1 * (pow(50, 5)/(pow(path_length, 5) + pow(50, 5)));
	
	print_heat_network();
	
	while(1){
		if(!(path_head.first%2 == 1 && path_head.second%2 == 1)){ 
			if(path_head.first+1 != 100 && liquid_network[0][path_head.second][path_head.first+1] == 0){
				if(liquid_network[0][path_head.second][path_head.first+1] != 1){
					liquid_network[0][path_head.second][path_head.first+1] = 4;
				}
				path_head.first += 1;
			}
			else if(path_head.first-1 != 0 && liquid_network[0][path_head.second][path_head.first+1] == 0){
				if(liquid_network[0][path_head.second][path_head.first+1] != 1){
					liquid_network[0][path_head.second][path_head.first-1] = 4;
				}
				path_head.first -= 1;
			}
			else if(path_head.second+1 != 100 && liquid_network[0][path_head.second+1][path_head.first] == 0){
				if(liquid_network[0][path_head.second+1][path_head.first] != 1){
					liquid_network[0][path_head.second+1][path_head.first] = 4;
				}
				path_head.second += 1;
			}
			else if(path_head.second-1 != 0 && liquid_network[0][path_head.second-1][path_head.first] == 0){
				if(liquid_network[0][path_head.second-1][path_head.first] != 1){
					liquid_network[0][path_head.second-1][path_head.first] = 4;
				}
				path_head.second -= 1;
			}
			cool_down(path_head, efficiency);
			efficiency = 1 * (pow(50, 5)/(pow(path_length, 5) + pow(50, 5)));
			path_length ++ ;
			cout << "0 0 done" << endl;
		}
		else{
			int next_dir = choose_dir(path_head, path_length);
			cout << next_dir << "  456" << endl;
			if(next_dir == 0){
				path_head.first += 1;
			}
			else if(next_dir == 1){
				path_head.second -= 1;
			}
			else if(next_dir == 2){
				path_head.first -= 1;
			}
			else if(next_dir == 3){
				path_head.second += 1;
			}
			liquid_network[0][path_head.second][path_head.first] = 4;
			cool_down(path_head, efficiency);
			efficiency = 1 * (pow(50, 5)/(pow(path_length, 5) + pow(50, 5)));
			path_length ++ ;
			cout << "1 1 done" << endl;
			
		}
		cout << path_head.first << " " << path_head.second << " " << path_length << " " << efficiency << endl;
		print_heat_network();
		getchar();
		
		
		
		
		
	}
	
	return true;
}

int network_generator::choose_dir(pair <int, int> path_head, int path_length){
	
	double score[4] = {0};
	if(path_head.first+1 != 100 && liquid_network[0][path_head.second][path_head.first+1] == 0){  //right : 0
		double max_heat = 0;
		for( int i=path_head.second-1;i<path_head.second+1;i++ ){
			for( int j=path_head.first+1;j<path_head.first+10;j++ ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]);
				}
			}
		}
		score[0] += max_heat;
		if(path_length < 100){
			score[0] -= alpha * (pow((path_head.first+2)-50, 2) + pow(path_head.second-50, 2));
		}
		else{
			score[0] += alpha * (pow((path_head.first+2)-50, 2) + pow(path_head.second-50, 2));
		}
	}
	if(path_head.first-1 != 0 && liquid_network[0][path_head.second][path_head.first-1] == 0){  //left : 2
		double max_heat = 0;
		for( int i=path_head.second-1;i<path_head.second+1;i++ ){
			for( int j=path_head.first-1;j>path_head.first-10;j-- ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]); 
				}
			}
		}
		score[2] += max_heat;
		if(path_length < 100){
			score[2] -= alpha * (pow((path_head.first-2)-50, 2) + pow(path_head.second-50, 2));
		}
		else{
			score[2] += alpha * (pow((path_head.first-2)-50, 2) + pow(path_head.second-50, 2));
		}
	}
	if(path_head.second+1 != 100 && liquid_network[0][path_head.second+1][path_head.first] == 0){  //top : 3
		double max_heat = 0;
		for( int i=path_head.second+1;i<path_head.second+10;i++ ){
			for( int j=path_head.first-1;j<path_head.first+1;j++ ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]);
				}
			}
		}
		score[3] += max_heat;
		if(path_length < 100){
			score[3] -= alpha * (pow(path_head.first-50, 2) + pow((path_head.second+2)-50, 2));
		}
		else{
			score[3] += alpha * (pow(path_head.first-50, 2) + pow((path_head.second+2)-50, 2));
		}
	}
	if(path_head.second-1 != 0 && liquid_network[0][path_head.second-1][path_head.first] == 0){  //bot : 1
		double max_heat = 0;
		for( int i=path_head.second-1;i>path_head.second-10;i-- ){
			for( int j=path_head.first-1;j<path_head.first+1;j++ ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]);
				}
			}
		}
		score[1] += max_heat;
		if(path_length < 100){
			score[1] -= alpha * (pow(path_head.first-50, 2) + pow((path_head.second-2)-50, 2));
		}
		else{
			score[1] += alpha * (pow(path_head.first-50, 2) + pow((path_head.second-2)-50, 2));
		}
	}
	double max_score = - (1<<30);
	int next_dir = 0;
	for( int i=0;i<4;i++ ){
		cout << "score " << i << " " << score[i] << endl;
		if(max_score < score[i]){
			max_score = score[i];
			next_dir = i;
		}
	}
	return next_dir;
}

void network_generator::cool_down(pair<int, int> center, double efficiency){
	double distance_square;
	for(int x=0;x<101;x++){
		for(int y=0;y<101;y++ ){
			distance_square = pow((double)(center.first-x), 2) + pow((double)(center.second-y), 2);
			heat_network[y][x] -= 10 * efficiency * (2500.0/(2500.0+distance_square)); ////////////////// P * e * (2500/(2500+d^2));
		}
	}
}

void network_generator::print_liquid_network(){
	
    ofstream fout("liquid_network");
    for (int l=0; l<channel_layer; l++) {
        for (int i=0; i<101; i++) {
            for (int j=0; j<101; j++) {
                fout << liquid_network[l][i][j] << " ";
            }
            fout << endl;
        }
        fout << endl;
    }
}

void network_generator::print_heat_network(){
	
	ofstream fout("heat_network");
	for (int i=0; i<101; i++) {
		for (int j=0; j<101; j++) {
			fout << setw(10) << setiosflags(ios::left) << setprecision(6) << heat_network[i][j];
		}
		fout << endl;
	}
}
