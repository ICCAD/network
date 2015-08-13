
#include "network_gen.h"

void network_generator::data_init(chip_data &chip){
	this->chip = chip;
	channel_layer = chip.layer_num - 1;
	alpha = 0.3;
	beta = 0.6;
	vector < vector <double> > temp(101,vector <double> (101,channel_layer*1000));
	vector < vector <int> > temp_liquid(101,vector <int> (101));
	for( int i=0;i<this->chip.dies.size();i++ ){
		for( int j=0;j<this->chip.dies[i].blocks.size();j++ ){
			double mid_x = this->chip.dies[i].blocks[j].lx + this->chip.dies[i].blocks[j].width / 2.0;
			double mid_y = this->chip.dies[i].blocks[j].ly + this->chip.dies[i].blocks[j].length / 2.0;
			double power = this->chip.dies[i].blocks[j].power;
			double half_power_length = min(this->chip.dies[i].blocks[j].length/2.0, this->chip.dies[i].blocks[j].width/2.0);
			for( int x=0;x<101;x++ ){
				for( int y=0;y<101;y++ ){
					double distance_square = pow(mid_x-(50+100*x), 2) + pow(mid_y-(50+100*y), 2);
					temp[y][x] += power * 20 * (pow(half_power_length, 2) / (pow(half_power_length, 2) + distance_square));
				}
			}
		}
	}
	for( int x=0;x<101;x++ ){
		for( int y=0;y<101;y++ ){
			double distance_square = pow(5000-(50+100*x), 2) + pow(5000-(50+100*y), 2);
			temp[y][x] += 40 * 10 * (pow(3000, 2) / (pow(3000, 2) + distance_square));
		}
	}
	for (int i=0; i<101; i+=2) {
        for (int j=0; j<101; j+=2) {
            temp_liquid[i][j] = 7;
        }
    }
    for (int i=0; i<channel_layer; i++) {
        init_liquid_network.push_back(temp_liquid);
    }
	init_heat_network = temp; 
}

void network_generator::network_init(){
	
	heat_network = init_heat_network;
	liquid_network = init_liquid_network;
	
	
}

void network_generator::find_network_sol(){
	
	for(int i=0;i<16;i++){
		network_init();
		if(network_gen(i)){
			cout << "network build done !" << endl;
		}
		print_network();
		cout << "seed #1" << endl;
		getchar();
	}
	
}

bool network_generator::network_gen(int seed){
	
	int inlet_dir = -1, outlet_dir = -1, line_layer = 0;
	pair <int, int> path_head;
	vector < pair <int, int> > inlet(channel_layer*4), outlet(channel_layer*4);
	vector <int> inlet_lock(channel_layer*4), outlet_lock(channel_layer*4);
	double efficiency = 0.0;
	double half_efficiency_length = 50;
	if(seed < 4){   /////////south
		inlet_dir = 1;
		seed %= 4;
		inlet[inlet_dir+line_layer*4].first = rand()%20 + 10 + 20*seed;
		while(inlet[inlet_dir+line_layer*4].first%2 == 0){
			inlet[inlet_dir+line_layer*4].first = rand()%20 + 10 + 20*seed;
		}
		inlet[inlet_dir+line_layer*4].second = 0;
		inlet_lock[inlet_dir+line_layer*4] = 1;
	}
	else if(seed < 8){   /////////east
		inlet_dir = 0;
		seed %= 4;
		inlet[inlet_dir+line_layer*4].first = 100;
		inlet[inlet_dir+line_layer*4].second = rand()%20 + 10 + 20*seed;
		while(inlet[inlet_dir+line_layer*4].second%2 == 0){
			inlet[inlet_dir+line_layer*4].second = rand()%20 + 10 + 20*seed;
		}
		inlet_lock[inlet_dir+line_layer*4] = 1;
	}
	else if(seed < 12){    /////////north
		inlet_dir = 3;
		seed %= 4;
		inlet[inlet_dir+line_layer*4].first = rand()%20 + 10 + 20*seed;
		while(inlet[inlet_dir+line_layer*4].first%2 == 0){
			inlet[inlet_dir+line_layer*4].first = rand()%20 + 10 + 20*seed;
		}
		inlet[inlet_dir+line_layer*4].second = 100;
		inlet_lock[inlet_dir+line_layer*4] = 1;
	}
	else if(seed < 16){    /////////west
		inlet_dir = 2;
		seed %= 4;
		inlet[inlet_dir+line_layer*4].first = 0;
		inlet[inlet_dir+line_layer*4].second = rand()%20 + 10 + 20*seed;
		while(inlet[inlet_dir+line_layer*4].second%2 == 0){
			inlet[inlet_dir+line_layer*4].second = rand()%20 + 10 + 20*seed;
		}
		inlet_lock[inlet_dir+line_layer*4] = 1;
	}
	inlet[inlet_dir+line_layer*4].first = 21;   //-----------------------------------lock
	
	liquid_network[line_layer][inlet[inlet_dir+line_layer*4].second][inlet[inlet_dir+line_layer*4].first] = 4;
	cout << inlet[inlet_dir+line_layer*4].first << " " << inlet[inlet_dir+line_layer*4].second << endl;
	path_head = inlet[inlet_dir+line_layer*4];
	int path_length = 0;
	efficiency = 1 * (pow(half_efficiency_length, 5)/(pow(path_length, 5) + pow(half_efficiency_length, 5)));
	cool_down(path_head, efficiency);
	
	
	for( int line_num=0;line_num<channel_layer*4;line_num++ ){       //------------------network generation
		while((path_head.first != 0 && path_head.first != 100 && path_head.second != 0 && path_head.second != 100) || path_length < 20){
			cout << 888 << endl;
			if(!(path_head.first%2 == 1 && path_head.second%2 == 1)){ 
				if(path_head.first+1 <= 100 && liquid_network[line_layer][path_head.second][path_head.first+1] == 0){
					if(liquid_network[line_layer][path_head.second][path_head.first+1] != 1){
						liquid_network[line_layer][path_head.second][path_head.first+1] = 4;
					}
					path_head.first += 1;
				}
				else if(path_head.first-1 >= 0 && liquid_network[line_layer][path_head.second][path_head.first-1] == 0){
					if(liquid_network[line_layer][path_head.second][path_head.first+1] != 1){
						liquid_network[line_layer][path_head.second][path_head.first-1] = 4;
					}
					path_head.first -= 1;
				}
				else if(path_head.second+1 <= 100 && liquid_network[line_layer][path_head.second+1][path_head.first] == 0){
					if(liquid_network[line_layer][path_head.second+1][path_head.first] != 1){
						liquid_network[line_layer][path_head.second+1][path_head.first] = 4;
					}
					path_head.second += 1;
				}
				else if(path_head.second-1 >= 0 && liquid_network[line_layer][path_head.second-1][path_head.first] == 0){
					if(liquid_network[line_layer][path_head.second-1][path_head.first] != 1){
						liquid_network[line_layer][path_head.second-1][path_head.first] = 4;
					}
					path_head.second -= 1;
				}
				path_length ++ ;
				efficiency = 1 * (pow(half_efficiency_length, 5)/(pow(path_length, 5) + pow(half_efficiency_length, 5)));
				cool_down(path_head, efficiency);
				
				//cout << "0 0 done" << endl;
			}
			else{
				int next_dir = choose_dir(path_head, path_length, line_layer, outlet_lock);
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
				liquid_network[line_layer][path_head.second][path_head.first] = 4;
				path_length ++ ;
				efficiency = 1 * (pow(half_efficiency_length, 5)/(pow(path_length, 5) + pow(half_efficiency_length, 5)));
				cool_down(path_head, efficiency);
				//cout << "1 1 done" << endl;
				
			}
			
			cout << "(" << path_head.first << "," << path_head.second << ") " << path_length << " " << efficiency << endl;
		}
		for( int x=0;x<101;x++ ){
			for( int y=0;y<101;y++ ){
				if(liquid_network[line_layer][y][x] == 4){
					liquid_network[line_layer][y][x] = 1;
				}
			}
		}
		if(path_head.first == 0){
			outlet_dir = 2;
		}
		else if(path_head.first == 100){
			outlet_dir = 0;
		}
		else if(path_head.second == 0){
			outlet_dir = 1;
		}
		else if(path_head.second == 100){
			outlet_dir = 3;
		}
		outlet[outlet_dir+line_layer*4] = path_head;
		outlet_lock[outlet_dir+line_layer*4] = 1;
		cout << outlet_dir << " " << outlet_lock[outlet_dir+line_layer*4] << endl;
		print_heat_network();
		print_liquid_network();
		cout << line_num << " line done !" << endl;
		getchar();
		
		if(line_num < channel_layer*4-1){       //-------------------------change inlet
			//if(line_num%4 == 0){
				choose_next_layer_inlet(path_head, inlet_lock, inlet, line_layer);
			//}
			//else{
			//	choose_layer_inlet();
			//}
			liquid_network[line_layer][path_head.second][path_head.first] = 4;
			path_length = 0;
			efficiency = 1 * (pow(half_efficiency_length, 5)/(pow(path_length, 5) + pow(half_efficiency_length, 5)));
			cool_down(path_head, efficiency);
			print_heat_network();
		}
		
		if(line_num%4 == 3){   //------------------------------------------change layer
			line_layer ++ ;
		}
		cout << "(" << path_head.first << "," << path_head.second << ")" << endl;
		getchar();
	}
	
	
	return true;
}

void network_generator::choose_layer_inlet(pair<int, int> &path_head, vector <int> &inlet_lock, vector < pair <int, int> > &inlet, int layer){
	
	if(inlet_lock[channel_layer*layer+0] != 1){
		
	}
	
}

void network_generator::choose_next_layer_inlet(pair<int, int> &path_head, vector <int> &inlet_lock, vector < pair <int, int> > &inlet, int layer){
	
	double max_heat = 0.0;
	int next_inlet_dir = 0;
	pair <int, int> next_path_head;
	if(inlet_lock[channel_layer*layer+0] != 1){
		for( int i=10;i<90;i++ ){
			if(liquid_network[layer][i][100] == 0 && max_heat < heat_network[i][100]){
				max_heat = heat_network[i][100];
				next_path_head.first = 100;
				next_path_head.second = i;
				next_inlet_dir = 0;
			}
		}
	}
	
	if(inlet_lock[channel_layer*layer+1] != 1){
		for( int i=10;i<90;i++ ){
			if(liquid_network[layer][0][i] == 0 && max_heat < heat_network[0][i]){
				max_heat = heat_network[0][i];
				next_path_head.first = i;
				next_path_head.second = 0;
				next_inlet_dir = 1;
			}
		}
	}
	
	if(inlet_lock[channel_layer*layer+2] != 1){
		for( int i=10;i<90;i++ ){
			if(liquid_network[layer][i][0] == 0 && max_heat < heat_network[i][0]){
				max_heat = heat_network[i][0];
				next_path_head.first = 0;
				next_path_head.second = i;
				next_inlet_dir = 2;
			}
		}
	}
	
	if(inlet_lock[channel_layer*layer+3] != 1){
		for( int i=10;i<90;i++ ){
			if(liquid_network[layer][100][i] == 0 && max_heat < heat_network[100][i]){
				max_heat = heat_network[100][i];
				next_path_head.first = i;
				next_path_head.second = 100;
				next_inlet_dir = 3;
			}
		}
	}

	path_head = next_path_head;
	inlet[channel_layer*layer+next_inlet_dir] = path_head;
	inlet_lock[channel_layer*layer+next_inlet_dir] = 1;
}

int network_generator::choose_dir(pair <int, int> path_head, int path_length, int layer, vector <int> outlet_lock){
	
	int reverse_length = 40;
	double score[4] = {0};
	if(path_head.first+1 <= 100 && liquid_network[layer][path_head.second][path_head.first+1] == 0 && !check_line(path_head, 0, layer)){  //right : 0
		double max_heat = 0;
		for( int i=path_head.second-1;i<path_head.second+1;i++ ){
			for( int j=path_head.first+1;j<path_head.first+10;j++ ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]);
				}
			}
		}
		score[0] += max_heat;
		if(path_length > reverse_length){
			score[0] += alpha * (pow((path_head.first+2)-50, 2) + pow(path_head.second-50, 2));
			
		}
		if(outlet_lock[layer*4+0] == 1){
			score[0] -= beta * (pow(100-abs((path_head.first+2)-100), 2.2));
		}
	}
	if(path_head.first-1 >= 0 && liquid_network[layer][path_head.second][path_head.first-1] == 0 && !check_line(path_head, 2, layer)){  //left : 2
		double max_heat = 0;
		for( int i=path_head.second-1;i<path_head.second+1;i++ ){
			for( int j=path_head.first-1;j>path_head.first-10;j-- ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]); 
				}
			}
		}
		score[2] += max_heat;
		if(path_length > reverse_length){
			score[2] += alpha * (pow((path_head.first-2)-50, 2) + pow(path_head.second-50, 2));
			if(outlet_lock[layer*4+2] == 1){
				score[2] -= beta * (pow(100-abs((path_head.first-2)-0), 2.2));
			}
		}
	}
	if(path_head.second+1 <= 100 && liquid_network[layer][path_head.second+1][path_head.first] == 0 && !check_line(path_head, 3, layer)){  //top : 3
		double max_heat = 0;
		for( int i=path_head.second+1;i<path_head.second+10;i++ ){
			for( int j=path_head.first-1;j<path_head.first+1;j++ ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]);
				}
			}
		}
		score[3] += max_heat;
		if(path_length > reverse_length){
			score[3] += alpha * (pow(path_head.first-50, 2) + pow((path_head.second+2)-50, 2));
			if(outlet_lock[layer*4+3] == 1){
				score[3] -= beta * (pow(100-abs((path_head.second+2)-100), 2.2));
			}
		}
	}
	if(path_head.second-1 >= 0 && liquid_network[layer][path_head.second-1][path_head.first] == 0 && !check_line(path_head, 1, layer)){  //bot : 1
		double max_heat = 0;
		for( int i=path_head.second-1;i>path_head.second-10;i-- ){
			for( int j=path_head.first-1;j<path_head.first+1;j++ ){
				if(i < 101 && i >= 0 && j < 101 && j >= 0){
					max_heat = max(max_heat, heat_network[i][j]);
				}
			}
		}
		score[1] += max_heat;
		if(path_length > reverse_length){
			score[1] += alpha * (pow(path_head.first-50, 2) + pow((path_head.second-2)-50, 2));
			if(outlet_lock[layer*4+1] == 1){
				score[1] -= beta * (pow(100-abs((path_head.second-2)-0), 2.2));
			}
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

bool network_generator::check_line(pair<int, int> path_head, int mode,int layer){
	
	int check_length = 10;
	if(mode == 0){
		for( int i=1;i<check_length;i++ ){
			if(path_head.first+i <= 100){
				if(liquid_network[layer][path_head.second][path_head.first+i] != 0){
					return true;
				}
			}
		}
		return false;
	}
	if(mode == 1){
		for( int i=1;i<check_length;i++ ){
			if(path_head.second-i >= 0){
				if(liquid_network[layer][path_head.second-i][path_head.first] != 0){
					return true;
				}
			}
		}
		return false;
	}
	if(mode == 2){
		for( int i=1;i<check_length;i++ ){
			if(path_head.first-i >= 0){
				if(liquid_network[layer][path_head.second][path_head.first-i] != 0){
					return true;
				}
			}
		}
		return false;
	}
	if(mode == 3){
		for( int i=1;i<check_length;i++ ){
			if(path_head.second+i <= 100){
				if(liquid_network[layer][path_head.second+i][path_head.first] != 0){
					return true;
				}
			}
		}
		return false;
	}
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

void network_generator::print_network(){
	
	for( int i=0;i<channel_layer;i++ ){
		ofstream gnuData_out("map.txt", ios::out);
		ofstream gnuCmd_out("gp", ios::out);
		
		string network_name = "network_";
		network_name += char(i+48);
		gnuCmd_out << "set terminal png transparent nocrop enhanced size 1000,1000 font \"arial,8\" " << endl;
		gnuCmd_out << "set output '" << network_name << "'" << endl;
		gnuCmd_out << "set title \"liquid_network\" " << endl;
		gnuCmd_out << "unset key" << endl << "set tic scale 0" << endl;
		gnuCmd_out << "set palette rgbformula -23,-28,-3" << endl;
		gnuCmd_out << "set cbrange [0:5]" << endl;
		gnuCmd_out << "set cblabel \"liquid\" " << endl;
		gnuCmd_out << "unset cbtics" << endl;
		gnuCmd_out << "set xrange [-0.5:100.5]" << endl;
		gnuCmd_out << "set yrange [-0.5:100.5]" << endl;
		gnuCmd_out << "set view map" << endl;
		gnuCmd_out << "splot 'map.txt' matrix with image" << endl;
		for( int y=0;y<101;y++ ){
			for( int x=0;x<101;x++ ){
				if(liquid_network[i][y][x] == 7 || liquid_network[i][y][x] == 0){
					gnuData_out << 0 << " ";
				}
				else if(liquid_network[i][y][x] == 1){
					gnuData_out << 3 << " ";
				}
				
			}
			gnuData_out << endl;
		}
		system("gnuplot gp");
	}
	
}
