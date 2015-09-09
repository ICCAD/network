
#include "network_gen.h"

void network_generator::data_init(chip_data &chip){
	this->chip = chip;
	channel_layer = chip.layer_num - 1;
	alpha = 0.3;
	beta = 0.6;
	
	vector < vector <int> > temp_liquid(101,vector <int> (101));
	
	vector < vector < vector <double> > > temp(4, vector < vector <double> >(101,vector <double> (101,channel_layer*1000)));
	for( int x=0;x<101;x++ ){
		for( int y=0;y<101;y++ ){
			double distance_square = pow(55-x, 2) + pow(50-y, 2);
			temp[0][y][x] += 50 * 10 * (pow(30, 2) / (pow(30, 2) + distance_square));
		}
	}
	for( int x=0;x<101;x++ ){
		for( int y=0;y<101;y++ ){
			double distance_square = pow(50-x, 2) + pow(45-y, 2);
			temp[1][y][x] += 50 * 10 * (pow(30, 2) / (pow(30, 2) + distance_square));
		}
	}
	for( int x=0;x<101;x++ ){
		for( int y=0;y<101;y++ ){
			double distance_square = pow(45-x, 2) + pow(50-y, 2);
			temp[2][y][x] += 50 * 10 * (pow(30, 2) / (pow(30, 2) + distance_square));
		}
	}
	for( int x=0;x<101;x++ ){
		for( int y=0;y<101;y++ ){
			double distance_square = pow(50-x, 2) + pow(55-y, 2);
			temp[3][y][x] += 50 * 10 * (pow(30, 2) / (pow(30, 2) + distance_square));
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
	
	liquid_network = init_liquid_network;
	
	
}

void network_generator::find_network_sol(){
	
	for(int i=0;i<10000;i++){
		network_init();
		if(network_gen()){
			cout << i << " network build done !" << endl;
		}
		network_evolution();
		//print_network();
		//cout << "seed #1" << endl;
		//getchar();
	}
	cout << "done" << endl;
	print_network();
	
}

bool network_generator::network_gen(){
	
	int inlet_dir = -1, outlet_dir = -1, line_layer = 0;
	pair <int, int> path_head;
	vector < pair <int, int> > inlet(channel_layer*4), outlet(channel_layer*4);
	vector <int> inlet_lock(channel_layer*4), outlet_lock(channel_layer*4);
	vector < pair <int, int> > centers(4);
	
	centers[0].first = 55;
	centers[0].second = 50;
	centers[1].first = 50;
	centers[1].second = 45;
	centers[2].first = 45;
	centers[2].second = 50;
	centers[3].first = 50;
	centers[3].second = 55;
	//random_in_out_let(inlet, outlet);
	
	inlet[0].first = 77;//53
    inlet[0].second = 100;//0
    inlet[1].first = 19;
    inlet[1].second = 0;
    inlet[2].first = 100;
    inlet[2].second = 23;
    inlet[3].first = 0;
    inlet[3].second = 27;
    outlet[0].first = 53;//77
    outlet[0].second = 0;//100
    outlet[1].first = 100;
    outlet[1].second = 35;
    outlet[2].first = 0;
    outlet[2].second = 65;
    outlet[3].first = 49;
    outlet[3].second = 100;
	
	for( int i=0;i<inlet.size();i++ ){
		pout(inlet[i]);
		cout << " ";
		pout(outlet[i]);
		cout << endl;
	}
	getchar();
	
	for( int line_num=0;line_num<channel_layer*4;line_num++ ){
		vector < vector <double> > temp_heat_map(101, vector <double>(101));
		bool reverse = 0;
		for( int x=0;x<101;x++ ){
			for( int y=0;y<101;y++ ){
				double distance_square = pow(x-outlet[line_num].first, 2) + pow(y-outlet[line_num].second, 2);
				temp_heat_map[y][x] += 1000 * 10 * (pow(30, 2) / (pow(30, 2) + distance_square));
			}
		}
		path_head = inlet[line_num];
		liquid_network[line_num/4][inlet[line_num].second][inlet[line_num].first] = 4;
		while(path_head != outlet[line_num]){
			//pout(path_head);
			//cout <<endl;
			//getchar();
			if(Is_close_center(path_head, centers[line_num%4]) && reverse == 0){
				for( int x=0;x<101;x++ ){
					for( int y=0;y<101;y++ ){
						if(liquid_network[line_num/4][y][x] == 4){
							liquid_network[line_num/4][y][x] = 1;
						}
					}
				}
				reverse = 1;
			}
			if(reverse){
				choose_dir(path_head, line_num/4, &temp_heat_map);
				liquid_network[line_num/4][path_head.second][path_head.first] = 4;
			}
			else{
				choose_dir(path_head, line_num/4, &init_heat_network[line_num%4]);
				liquid_network[line_num/4][path_head.second][path_head.first] = 4;
			}
		}
		
		for( int x=0;x<101;x++ ){
			for( int y=0;y<101;y++ ){
				if(liquid_network[line_num/4][y][x] == 4){
					liquid_network[line_num/4][y][x] = 1;
				}
			}
		}
		//cout << "line done !" << endl;
		//print_liquid_network();
		
		//getchar();
	}
	for( int i=0;i<channel_layer*4;i++ ){
		liquid_network[i/4][inlet[i].second][inlet[i].first] = 2;
		liquid_network[i/4][outlet[i].second][outlet[i].first] = 3;
	}
	for( int l=0;l<channel_layer;l++ ){
		for( int x=0;x<101;x++ ){
			for( int y=0;y<101;y++ ){
				if(liquid_network[l][y][x] == 7){
					liquid_network[l][y][x] = 0;
				}
			}
		}
	}
	
	print_liquid_network();
	//getchar();
	return true;
}

void network_generator::choose_dir(pair <int, int> &path_head, int layer, vector < vector <double> > *heat_map){
	
	vector <double> score(4);
	if(path_head.first+1 <= 100 && liquid_network[layer][path_head.second][path_head.first+1] != 7 &&  liquid_network[layer][path_head.second][path_head.first+1] != 4){
		score[0] += (*heat_map)[path_head.second][path_head.first+1];
		if(check_line(path_head, 0, layer)){
			score[0] -= 1000;
		}
	}
	
	if(path_head.second-1 >= 0 && liquid_network[layer][path_head.second-1][path_head.first] != 7 &&  liquid_network[layer][path_head.second-1][path_head.first] != 4){
		score[1] += (*heat_map)[path_head.second-1][path_head.first];
		if(check_line(path_head, 1, layer)){
			score[1] -= 1000;
		}
	}
	
	if(path_head.first-1 >= 0 && liquid_network[layer][path_head.second][path_head.first-1] != 7 &&  liquid_network[layer][path_head.second][path_head.first-1] != 4){
		score[2] += (*heat_map)[path_head.second][path_head.first-1];
		if(check_line(path_head, 2, layer)){
			score[2] -= 1000;
		}
	}
	
	if(path_head.second+1 <= 100 && liquid_network[layer][path_head.second+1][path_head.first] != 7 &&  liquid_network[layer][path_head.second+1][path_head.first] != 4){
		score[3] += (*heat_map)[path_head.second+1][path_head.first];
		if(check_line(path_head, 3, layer)){
			score[3] -= 1000;
		}
	}
	
	double max_score = 0.0;
	int next_location = -1;
	for( int i=0;i<4;i++ ){
		//cout << i << " " << score[i] << endl;
		if(max_score < score[i]){
			max_score = score[i];
			next_location = i;
		}
	}
	if(next_location == 0){
		path_head.first ++;
	}
	else if(next_location == 1){
		path_head.second --;
	}
	else if(next_location == 2){
		path_head.first --;
	}
	else if(next_location == 3){
		path_head.second ++;
	}
	if(next_location == -1){
		cout << "error" << endl;
		getchar();
	}
}

bool  network_generator::Is_close_center(pair <int, int> path_head, pair <int, int> center){
	
	if(abs(path_head.first-center.first) + abs(path_head.second-center.second) <= 3){
		return true;
	}
	else{
		return false;
	}
	
}

bool network_generator::check_line(pair<int, int> path_head, int mode,int layer){
	
	int check_length = 2;
	if(mode == 0){
		for( int i=1;i<check_length;i++ ){
			if(path_head.first+i <= 100){
				if(liquid_network[layer][path_head.second][path_head.first+i] == 4){
					return true;
				}
			}
		}
		return false;
	}
	if(mode == 1){
		for( int i=1;i<check_length;i++ ){
			if(path_head.second-i >= 0){
				if(liquid_network[layer][path_head.second-i][path_head.first] == 4){
					return true;
				}
			}
		}
		return false;
	}
	if(mode == 2){
		for( int i=1;i<check_length;i++ ){
			if(path_head.first-i >= 0){
				if(liquid_network[layer][path_head.second][path_head.first-i] == 4){
					return true;
				}
			}
		}
		return false;
	}
	if(mode == 3){
		for( int i=1;i<check_length;i++ ){
			if(path_head.second+i <= 100){
				if(liquid_network[layer][path_head.second+i][path_head.first] == 4){
					return true;
				}
			}
		}
		return false;
	}
}

void network_generator::random_in_out_let(vector < pair <int, int> > &inlet, vector < pair <int, int> > &outlet){
	
	vector <int> in_dir(inlet.size()), out_dir(inlet.size());
	vector < vector <int> > valid(4, vector <int>(101));
	for( int i=0;i<in_dir.size();i++ ){
		in_dir[i] = rand()%4 + 1;
		out_dir[i] = rand()%4 + 1;
	}
	while(in_dir[1] == in_dir[0]){
		in_dir[1] = in_dir[1]%4 + 1;
	}
	while(in_dir[2] == in_dir[0] || in_dir[2] == in_dir[1]){
		in_dir[2] = in_dir[2]%4 + 1;
	}
	while(in_dir[3] == in_dir[0] || in_dir[3] == in_dir[1] || in_dir[3] == in_dir[2]){
		in_dir[3] = in_dir[3]%4 + 1;
	}
	while(out_dir[1] == out_dir[0]){
		out_dir[1] = out_dir[1]%4 + 1;
	}
	while(out_dir[2] == out_dir[0] || out_dir[2] == out_dir[1]){
		out_dir[2] = out_dir[2]%4 + 1;
	}
	while(out_dir[3] == out_dir[0] || out_dir[3] == out_dir[1] || out_dir[3] == out_dir[2]){
		out_dir[3] = out_dir[3]%4 + 1;
	}
	for( int i=0;i<in_dir.size();i++ ){
		if(in_dir[i] == 1){
			inlet[i].first = 100;
			inlet[i].second = rand()%80 + 10;
			while(valid[0][inlet[i].second] == 1 || inlet[i].second%2 == 0){
				inlet[i].second = rand()%80 + 10;
			}
			valid[0][inlet[i].second] = 1;
		}
		else if(in_dir[i] == 2){
			inlet[i].second = 0;
			inlet[i].first = rand()%80 + 10;
		while(valid[1][inlet[i].first] == 1 || inlet[i].first%2 == 0){
				inlet[i].first = rand()%80 + 10;
			}
			valid[1][inlet[i].first] = 1;
		}
		else if(in_dir[i] == 3){
			inlet[i].first = 0;
			inlet[i].second = rand()%80 + 10;
			while(valid[2][inlet[i].second] == 1 || inlet[i].second%2 == 0){
				inlet[i].second = rand()%80 + 10;
			}
			valid[2][inlet[i].second] = 1;
		}
		else if(in_dir[i] == 4){
			inlet[i].second = 100;
			inlet[i].first = rand()%80 + 10;
			while(valid[3][inlet[i].first] == 1 || inlet[i].first%2 == 0){
				inlet[i].first = rand()%80 + 10;
			}
			valid[3][inlet[i].first] = 1;
		}
		if(out_dir[i] == 1){
			outlet[i].first = 100;
			outlet[i].second = rand()%80 + 10;
			while(valid[0][outlet[i].second] == 1 || outlet[i].second%2 == 0){
				outlet[i].second = rand()%80 + 10;
			}
		}
		else if(out_dir[i] == 2){
			outlet[i].second = 0;
			outlet[i].first = rand()%80 + 10;
			while(valid[1][outlet[i].first] == 1 || outlet[i].first%2 == 0){
				outlet[i].first = rand()%80 + 10;
			}
		}
		else if(out_dir[i] == 3){
			outlet[i].first = 0;
			outlet[i].second = rand()%80 + 10;
			while(valid[2][outlet[i].second] == 1 || outlet[i].second%2 == 0){
				outlet[i].second = rand()%80 + 10;
			}
		}
		else if(out_dir[i] == 4){
			outlet[i].second = 100;
			outlet[i].first = rand()%80 + 10;
			while(valid[3][outlet[i].first] == 1 || outlet[i].first%2 == 0){
				outlet[i].first = rand()%80 + 10;
			}
		}
	}
}

void network_generator::network_evolution(){
	
	long double coolant_flow_rate = 42.0;
	long double unit_pressure_drop = 100.0;
	while(1){
		print_network();
		long double total_Q = 0;
		vector <int> network_col(101,0);
		vector < vector <int> > single_network(101,network_col);
        vector < vector < vector <int> > > network(channel_layer,single_network);
        vector <int> channel_info_col(101,-1);
        vector < vector <int> > single_channel_info(101,channel_info_col);
		vector < vector < vector <int> > > channel_info(channel_layer,single_channel_info);
		vector <long double> flowrate_col(101,0);
		vector < vector <long double> > single_flow_rate(101,flowrate_col);
		vector < vector < vector <long double> > > flow_rate(channel_layer,single_flow_rate);
		vector < vector < vector <int> > > direction(channel_layer,single_network);
		vector < matrix > matrix_a(channel_layer);
		vector < vector <node> > tempnode(channel_layer);
		vector < vector <edge_info> > edges(channel_layer);
		for (int i = 0; i < channel_layer; i++) {
			network_graph( &liquid_network[i], &tempnode[i], &edges[i]);
			cout << "network_graph done!" << endl;
			matrix_a[i].get_num_channel(&tempnode[i], &edges[i]);
			cout << "get_num_channel done!" << endl;
            matrix_a[i].initial_direction(&tempnode[i], &edges[i]);
            cout << "initial_direction done!" << endl;
            matrix_a[i].write_spice_input(&i, &tempnode[i],unit_pressure_drop);
            cout << "write_spice_input done!" << endl;
            string spice_sim = "hspice spice_";
			spice_sim += i + 48;
			spice_sim += ".txt";
			spice_sim += " > test_";
			spice_sim += i + 48;
			spice_sim += ".txt";
			cout << spice_sim << endl;
			system(spice_sim.c_str());
            matrix_a[i].read_spice_result(&i);
            cout << "read_spice_result done!" << endl;
            matrix_a[i].get_inlet_Q(&tempnode[i]);
		}
		for (int i = 0; i < channel_layer; i++) {
			total_Q += matrix_a[i].inlet_Q;
			//cout << i << " " << "total_Q " << total_Q << "\t" ;
		}
		for (int i = 0; i < channel_layer; i++) {
			cout << "\nchannel_layer " << i << endl;
			matrix_a[i].get_pressure_drop(chip.width, chip.height, chip.length, coolant_flow_rate, unit_pressure_drop, total_Q);
			matrix_a[i].fill_flow_rate(&tempnode[i] ,&edges[i],&flow_rate[i],&channel_info[i]);
			matrix_a[i].fill_direction(&tempnode[i] ,&edges[i],&direction[i]);
			matrix_a[i].write_output(&i,&liquid_network[i], &tempnode[i],&flow_rate[i],&direction[i],&channel_info[i]);
		}
		
		cout << "file done !" << endl;
		vector < RTree<int, int, 2, float>* > edge_rtree(channel_layer);
		for( int i=0;i<channel_layer;i++ ){
			edge_rtree[i] = new RTree<int, int, 2, float>;
			int minp[2], maxp[2];
			for( int j=0;j<edges[i].size();j++ ){
				minp[0] = min(tempnode[i][edges[i][j].nodes.first].coordinate.first, tempnode[i][edges[i][j].nodes.second].coordinate.first);
				minp[1] = min(tempnode[i][edges[i][j].nodes.first].coordinate.second, tempnode[i][edges[i][j].nodes.second].coordinate.second);
				maxp[0] = max(tempnode[i][edges[i][j].nodes.first].coordinate.first, tempnode[i][edges[i][j].nodes.second].coordinate.first);
				maxp[1] = max(tempnode[i][edges[i][j].nodes.first].coordinate.second, tempnode[i][edges[i][j].nodes.second].coordinate.second);
				if(edges[i][j].HV == 'H'){
					minp[0] += 1;
					maxp[0] -= 1;
					/*cout << tempnode[i][edges[i][j].nodes.first].coordinate.first << " " << tempnode[i][edges[i][j].nodes.second].coordinate.first << endl;
					cout << tempnode[i][edges[i][j].nodes.first].coordinate.second << " " << tempnode[i][edges[i][j].nodes.second].coordinate.second << endl;
					cout << minp[0] << " " << maxp[0] << endl;
					cout << minp[1] << " " << maxp[1] << endl;*/
					//getchar();
				}
				else if(edges[i][j].HV == 'V'){
					minp[1] += 1;
					maxp[1] -= 1;
				}
				if(edges[i][j].HV != 'N'){
					edge_rtree[i]->Insert(minp, maxp, j);
				}
			}
		}
		cout << "Rtree done !" << endl;
		/*int minp[2], maxp[2];
		minp[0] = 17;
		minp[1] = 0;
		maxp[0] = 17;
		maxp[1] = 4;
		vector <int> edge_list;
		for( int i=0;i<channel_layer;i++ ){
			edge_list.clear();
			edge_rtree[i]->Search(minp, maxp, &edge_list);
			for( int k=0;k<edge_list.size();k++ ){
				cout << tempnode[i][edges[i][edge_list[k]].nodes.first].coordinate.first << " " << tempnode[i][edges[i][edge_list[k]].nodes.first].coordinate.second << endl;
				cout << tempnode[i][edges[i][edge_list[k]].nodes.second].coordinate.first << " " << tempnode[i][edges[i][edge_list[k]].nodes.second].coordinate.second << endl;
			}
			cout << edge_list.size() << endl;
		}
		getchar();*/
		
		chdir("3d-ice/bin/");
		string simulator = "./3D-ICE-Emulator test_case_0";
		simulator += chip.case_num + 48;
		simulator += ".stk";
		for( int i=0;i<channel_layer;i++ ){
			simulator += " ../../network_";
			simulator += i+48;
			simulator += " ../../flowrate_";
			simulator += i+48;
			simulator += " ../../direction_";
			simulator += i+48;
		}
		cout << simulator << endl;
		system(simulator.c_str());
		getchar();
		
		chdir("../../");
		ifstream *fin = new ifstream[channel_layer+1];
		vector < vector < vector <double> > > T_map;
		double T_max = 0, T_min = 1<<30;
		pair<int, int> target;
		for( int i=0;i<channel_layer+1;i++ ){
			string file_location = "3d-ice/bin/testcase_0";
			vector < vector <double> > temp_T_map(101, vector <double>(101));
			file_location += chip.case_num+48;
			file_location += "/output_";
			file_location += i+48;
			file_location += ".txt";
			cout << file_location << endl;
			
			fin[i].open(file_location.c_str());
			if(fin[i].eof()){
				cout << "error tmap !" << endl;
				return ;
			}
			else{
				for( int k=0;k<temp_T_map.size();k++ ){
					for( int j=0;j<temp_T_map[k].size();j++ ){
						fin[i] >> temp_T_map[k][j];
						if(T_max < temp_T_map[k][j]){
							T_max = temp_T_map[k][j];
							target.first = j;
							target.second = k;
						}
						if(T_min > temp_T_map[k][j]){
							T_min = temp_T_map[k][j];
						}
					}
				}
			}
			fin[i].close();
			T_map.push_back(temp_T_map);
			print_heat_color_picture(&temp_T_map, i);
		}
		if(T_max - T_min > chip.T_gredient){
			cout << "T_gredient fail !!!" << endl;
			cout << "T_gredient : " << chip.T_gredient << endl;
		}
		if(T_max > chip.T_max+273){
			cout << "T_max fail !!!" << endl;
			cout << "T_max : " << chip.T_max << endl;
		}
		cout << "sim over !!!!!!!!!!!!!!!!!!" << endl;
		return;
		pout(target);
		cout << endl;
		cout << T_max << endl;
		if(optimization_move_channel(target, &edge_rtree, &edges, &tempnode)){
			cout << "good" << endl;
		}
		else{
			cout << "bad" << endl;
		}
		getchar();
	}
	
	
}

bool network_generator::check_around(pair<int, int> node_1, pair<int, int> node_2, int layer){
	
	if(node_1.first == node_2.first){
		for( int i=node_1.first-1;i<=node_1.first+1;i++ ){
			if(liquid_network[layer][node_1.second-1][i] == 1 || liquid_network[layer][node_2.second+1][i] == 1){
				return false;
			}
		}
		for( int i=node_1.second;i<=node_2.second;i++ ){
			if(liquid_network[layer][i][node_1.first] == 1 || liquid_network[layer][i][node_2.first] == 1){
				return false;
			}
		}
		return true;
	}
	else{
		for( int i=node_1.second-1;i<=node_1.second+1;i++ ){
			if(liquid_network[layer][i][node_1.first-1] == 1 || liquid_network[layer][i][node_2.first+1] == 1){
				return false;
			}
		}
		for( int i=node_1.first;i<=node_2.first;i++ ){
			if(liquid_network[layer][node_1.second][i] == 1 || liquid_network[layer][node_2.second][i] == 1){
				return false;
			}
		}
		return true;
	}
	
	
}

bool network_generator::optimization_move_channel(pair <int, int> target, vector < RTree<int, int, 2, float>* > *edge_rtree, vector < vector <edge_info> > *edges, vector < vector <node> > *tempnode){
	
	int valid_length = 5;
	int minp[2], maxp[2];
	vector <int> edge_list;
	for( int layer=0;layer<channel_layer;layer++ ){
		for( int l=5;l<10;l++ ){
			edge_list.clear();
			if(target.second+l <= 100){
				minp[0] = target.first - valid_length;
				minp[1] = target.second+l;
				maxp[0] = target.first + valid_length;
				maxp[1] = target.second+l;
				(*edge_rtree)[layer]->Search(minp, maxp, &edge_list);
				for( int k=0;k<edge_list.size();k++ ){
					if((*edges)[layer][edge_list[k]].HV == 'H'){
						pair<int, int> node_1, node_2;
						node_1.first = max(minp[0], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.first].coordinate.first);
						node_1.second = minp[1];
						node_2.first = min(maxp[0], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.second].coordinate.first);
						node_2.second = minp[1];
						if(node_1.first % 2 != 1){
							node_1.first += 1;
						}
						if(node_2.first % 2 != 1){
							node_2.first -= 1;
						}
						if(node_2.first - node_1.first >= 2){
							pair<int, int> tmp_node_1=node_1, tmp_node_2=node_2;
							tmp_node_1.second -= 2;
							tmp_node_2.second -= 2;
							if(check_around(tmp_node_1, tmp_node_2, layer)){
								for( int j=0;j<node_2.first - node_1.first - 1;j++ ){
									liquid_network[layer][node_1.second][node_1.first+1+j] = 0;
									liquid_network[layer][node_1.second-2][node_1.first+1+j] = 1;
								}
								liquid_network[layer][node_1.second-1][node_2.first] = 1;
								liquid_network[layer][node_1.second-1][node_1.first] = 1;
								liquid_network[layer][node_1.second-2][node_2.first] = 1;
								liquid_network[layer][node_1.second-2][node_1.first] = 1;
								pout(node_1);
								cout << endl;
								pout(node_2);
								cout << endl;
								cout << "1" << endl;
								getchar();
								return true;
							}
						}
					}
				}
			}
			edge_list.clear();
			if(target.second-l >= 0){
				minp[0] = target.first - valid_length;
				minp[1] = target.second-l;
				maxp[0] = target.first + valid_length;
				maxp[1] = target.second-l;
				(*edge_rtree)[layer]->Search(minp, maxp, &edge_list);
				for( int k=0;k<edge_list.size();k++ ){
					if((*edges)[layer][edge_list[k]].HV == 'H'){
						pair<int, int> node_1, node_2;
						node_1.first = max(minp[0], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.first].coordinate.first);
						node_1.second = minp[1];
						node_2.first = min(maxp[0], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.second].coordinate.first);
						node_2.second = minp[1];
						if(node_1.first % 2 != 1){
							node_1.first += 1;
						}
						if(node_2.first % 2 != 1){
							node_2.first -= 1;
						}
						if(node_2.first - node_1.first >= 2){
							pair<int, int> tmp_node_1=node_1, tmp_node_2=node_2;
							tmp_node_1.second += 2;
							tmp_node_2.second += 2;
							if(check_around(tmp_node_1, tmp_node_2, layer)){
								for( int j=0;j<node_2.first - node_1.first - 1;j++ ){
									liquid_network[layer][node_1.second][node_1.first+1+j] = 0;
									liquid_network[layer][node_1.second+2][node_1.first+1+j] = 1;
									cout << node_1.second << " " << node_1.first+1+j << "123123" << endl;
								}
								liquid_network[layer][node_1.second+1][node_2.first] = 1;
								liquid_network[layer][node_1.second+1][node_1.first] = 1;
								liquid_network[layer][node_1.second+2][node_2.first] = 1;
								liquid_network[layer][node_1.second+2][node_1.first] = 1;
								pout(node_1);
								cout << endl;
								pout(node_2);
								cout << endl;
								pout(tmp_node_1);
								cout << endl;
								pout(tmp_node_2);
								cout << endl;
								cout << "2" << endl;
								cout << l << endl;
								getchar();
								return true;
							}
						}
					}
				}
			}
			edge_list.clear();
			if(target.first+l <= 100){
				minp[0] = target.first+l;
				minp[1] = target.second - valid_length;
				maxp[0] = target.first+l;
				maxp[1] = target.second + valid_length;
				(*edge_rtree)[layer]->Search(minp, maxp, &edge_list);
				for( int k=0;k<edge_list.size();k++ ){
					if((*edges)[layer][edge_list[k]].HV == 'V'){
						pair<int, int> node_1, node_2;
						node_1.first = minp[0];
						node_1.second = max(minp[1], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.first].coordinate.second);
						node_2.first = minp[0];
						node_2.second = min(maxp[1], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.second].coordinate.second);
						if(node_1.second % 2 != 1){
							node_1.second += 1;
						}
						if(node_2.second % 2 != 1){
							node_2.second -= 1;
						}
						if(node_2.second - node_1.second >= 2){
							pair<int, int> tmp_node_1=node_1, tmp_node_2=node_2;
							tmp_node_1.first -= 2;
							tmp_node_2.first -= 2;
							if(check_around(tmp_node_1, tmp_node_2, layer)){
								for( int j=0;j<node_2.second - node_1.second - 1;j++ ){
									liquid_network[layer][node_1.second+1+j][node_1.first] = 0;
									liquid_network[layer][node_1.second+1+j][node_1.first-2] = 1;	
								}
								liquid_network[layer][node_2.second][node_1.first-1] = 1;
								liquid_network[layer][node_1.second][node_1.first-1] = 1;
								liquid_network[layer][node_2.second][node_1.first-2] = 1;
								liquid_network[layer][node_1.second][node_1.first-2] = 1;
								pout(node_1);
								cout << endl;
								pout(node_2);
								cout << endl;
								cout << "3" << endl;
								getchar();
								return true;
							}
						}
					}
				}
			}
			edge_list.clear();
			if(target.first-l >= 0){
				minp[0] = target.first-l;
				minp[1] = target.second - valid_length;
				maxp[0] = target.first-l;
				maxp[1] = target.second + valid_length;
				(*edge_rtree)[layer]->Search(minp, maxp, &edge_list);
				for( int k=0;k<edge_list.size();k++ ){
					if((*edges)[layer][edge_list[k]].HV == 'V'){
						pair<int, int> node_1, node_2;
						node_1.first = minp[0];
						node_1.second = max(minp[1], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.first].coordinate.second);
						node_2.first = minp[0];
						node_2.second = min(maxp[1], (*tempnode)[layer][(*edges)[layer][edge_list[k]].nodes.second].coordinate.second);
						if(node_1.second % 2 != 1){
							node_1.second += 1;
						}
						if(node_2.second % 2 != 1){
							node_2.second -= 1;
						}
						if(node_2.second - node_1.second >= 2){
							pair<int, int> tmp_node_1=node_1, tmp_node_2=node_2;
							tmp_node_1.first += 2;
							tmp_node_2.first += 2;
							if(check_around(tmp_node_1, tmp_node_2, layer)){
								for( int j=0;j<node_2.second - node_1.second - 1;j++ ){
									liquid_network[layer][node_1.second+1+j][node_1.first] = 0;
									liquid_network[layer][node_1.second+1+j][node_1.first+1] = 1;
								}
								liquid_network[layer][node_2.second][node_1.first+1] = 1;
								liquid_network[layer][node_1.second][node_1.first+1] = 1;
								liquid_network[layer][node_2.second][node_1.first+2] = 1;
								liquid_network[layer][node_1.second][node_1.first+2] = 1;
								pout(node_1);
								cout << endl;
								pout(node_2);
								cout << endl;
								cout << "4" << endl;
								getchar();
								return true;
							}
						}
					}
				}
			}
			
		}
	}
	return false;
	
	
}

void network_generator::loading_liquid_network(const char **file){
	
	for( int l=0;l<channel_layer;l++ ){
		ifstream fin(file[2+l]);
		for( int i=0;i<101;i++ ){
			for( int j=0;j<101;j++ ){
				fin >> liquid_network[l][i][j];
			}
		}
		fin.close();
	}
	

}

void network_generator::print_heat_color_picture(vector < vector <double> > *output, int layer){
	
	double MIN_t = 1 << 30, MAX_t = 0;
	for( int y=0;y<101;y++ ){
		for( int x=0;x<101;x++ ){
			if(MIN_t > (*output)[y][x]){
				MIN_t = (*output)[y][x];
			}
			if(MAX_t < (*output)[y][x]){
				MAX_t = (*output)[y][x];
			}
		}
	}
	double gap = (MAX_t - MIN_t) / 10;
	ofstream gnuData_out("color.txt", ios::out);
	ofstream gnuCmd_out("color", ios::out);
	string network_name = "./heat_color_pic/heat_color_picture_case_";
	network_name += char(chip.case_num+48);
	network_name += "_layer_";
	network_name += char(layer+48);
	
	gnuCmd_out << "set terminal png transparent nocrop enhanced size 1000,1000 font \"arial,8\" " << endl;
	gnuCmd_out << "set output '" << network_name << "'" << endl;
	gnuCmd_out << "set title \"heat_color\" " << endl;
	gnuCmd_out << "unset key" << endl << "set tic scale 0" << endl;
	gnuCmd_out << "set palette rgbformula 21,22,23" << endl;
	gnuCmd_out << "set cbrange [0:10]" << endl;
	gnuCmd_out << "set cblabel \"temperature\" " << endl;
	gnuCmd_out << "set cbtics (";
	for( int i=0;i<10;i++ ){
		gnuCmd_out << "\"" << MIN_t + i * gap << "\" " << i;
		if(i < 9){
			gnuCmd_out << ",";
		}
	}
	gnuCmd_out << ")" << endl;
	gnuCmd_out << "set xrange [-0.5:100.5]" << endl;
	gnuCmd_out << "set yrange [-0.5:100.5]" << endl;
	gnuCmd_out << "set view map" << endl;
	gnuCmd_out << "splot 'color.txt' matrix with image" << endl;
	
	for( int i=100;i>=0;i-- ){
		for( int j=0;j<101;j++ ){
			for( int k=1;k<11;k++ ){
				if((*output)[i][j] >= MAX_t-gap*k){
					gnuData_out << 11-k << " ";
					break;
				}
				else if(k == 10){
					gnuData_out << 0 << " ";
				}
			}
		}
		gnuData_out << endl;
	}
	gnuData_out.close();
	gnuCmd_out.close();
	system("gnuplot color");
	
	
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
	fout.close();
}

void network_generator::print_heat_network(vector < vector <double> > heat_network){
	
	ofstream fout("heat_network");
	for (int i=0; i<101; i++) {
		for (int j=0; j<101; j++) {
			fout << setw(10) << setiosflags(ios::left) << setprecision(6) << heat_network[i][j];
		}
		fout << endl;
	}
	fout.close();
}

void network_generator::print_network(){
	
	for( int i=0;i<channel_layer;i++ ){
		ofstream gnuData_out("map.txt", ios::out);
		ofstream gnuCmd_out("gp", ios::out);
		
		string network_name = "./liquid_pic/liquid_network_case_";
		network_name += char(chip.case_num+48);
		network_name += "_layer_";
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
		for( int y=100;y>=0;y-- ){
			for( int x=0;x<101;x++ ){
				if(liquid_network[i][y][x] == 7 || liquid_network[i][y][x] == 0){
					gnuData_out << 0 << " ";
				}
				else{
					gnuData_out << 3 << " ";
				}
				
			}
			gnuData_out << endl;
		}
		gnuData_out.close();
		gnuCmd_out.close();
		system("gnuplot gp");
	}
	
}

void pout(pair <int, int> a){
	
	cout << "(" << a.first << "," << a.second << ")";
}