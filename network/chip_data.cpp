#include "chip_data.h"

void flow_network::read_file(const char *input){//*pointer
	ifstream fin (input);
	string temps;
	string tempss;
	char tempc;
	block tempblock;
	die tempdie;	
	stringstream ss;
	int temp;
	double tempp;
	
	fin >> temps >> temps;
	fin >> tempc >> tempc;
	fin >> layer_num;
	cout << "layer_num : " << layer_num << endl;
	dies.resize(layer_num);
	fin >> tempc >> tempc >> tempc;
	for(int i=0 ; i<layer_num;i++){
		fin >> temps;
		for (int j=0;j<temps.length()-1;j++){
			tempss+=temps[j];
		}
		dies[i].name= tempss;
		temps = "";
		tempss = "";
	}

	for (int i=0;i<dies.size();i++){
		cout << dies[i].name << " " ;
	}
	cout << endl;
	
	for (int i=0;i<layer_num;i++){
		while (temps != "{"){
			fin >> temps;
		}
		cout << 111 << endl;
		while (!fin.eof()){
			fin >> temps;
			if (temps=="}"){
				break;
			}
			for (int j=0;j<temps.length()-2;j++){
				tempss+=temps[j];
			}
			tempblock.name = tempss;
			cout << tempblock.name << " ";
			tempss="";
			fin >> temps;
			for (int j=1;j<temps.length()-1;j++){
				if (temps[j] != ',' || temps[j] != ')'){
					tempss+=temps[j];
				}
				if (temps[j] == ','){
					ss << tempss;
					ss >> temp;
					tempss="";
					ss.str("");
					ss.clear();	
					tempblock.lx = temp;
					cout << tempblock.lx << ",";
				}
				if (temps[j] == ')'){
					ss << tempss;
					ss >> temp;
					tempss="";
					ss.str("");
					ss.clear();	
					tempblock.ly = temp;
					cout << tempblock.ly << ")";
				}
			}
			tempss="";
			fin >> temps;
			for (int j=1;j<temps.length()-1;j++){
				if (temps[j] != ',' || temps[j] != ')'){
					tempss+=temps[j];
				}
				if (temps[j] == ','){
					ss << tempss;
					ss >> temp;
					tempss="";
					ss.str("");
					ss.clear();	
					tempblock.rx = temp;
					cout << tempblock.rx << ",";
				}
				if (temps[j] == ')'){
					ss << tempss;
					ss >> temp;
					tempss="";
					ss.str("");
					ss.clear();	
					tempblock.ry = temp;
					cout << tempblock.ry << ")"<<endl;
				}
			}
			tempss="";
			dies[i].blocks.push_back(tempblock);
			cout << 222 << endl;
		}
		cout << 333 << endl;
	}	
	tempc = ' ';
	tempss = "";
	for(int i=0;i<layer_num;i++){
		cout << 444 << endl;
		while (tempc !='{'){
			fin >> 	tempc;	
		}
		cout << tempc << endl;
		for (int j=0;j<dies[i].blocks.size();j++){
			while (!fin.eof()){
				fin >> tempc;
				tempss+=tempc;
				if (tempc==';' || tempc=='}'){
					break;
				}
			}
			ss << tempss;
			ss >> tempp;
			tempss="";
			ss.str("");
			ss.clear();	
			dies[i].blocks[j].power = tempp;
		}
	}
	cout << endl;
	for (int i=0;i<layer_num;i++){
		cout << dies[i].name << ":" << endl;
		for(int j=0;j<dies[i].blocks.size();j++){
			cout << dies[i].blocks[j].name << ": " << "(" << dies[i].blocks[j].lx <<","<<dies[i].blocks[j].ly <<") " << "("<< dies[i].blocks[j].rx <<"," << dies[i].blocks[j].ry <<") "<< dies[i].blocks[j].power << endl;
		}
	}
	vector <vector <int> > temp_cell(101,vector <int> (101,1));
	cells.resize(layer_num-1,temp_cell);
	
	for (int k=0; k<layer_num-1;k++){
		for (int i=0;i<101;i++){
			if (i<50){
				cells[k][i][0]=2;
				cells[k][i][100]=3;
			}
			else{
				cells[k][i][0]=3;
				cells[k][i][100]=2;
			}			
		}
		for (int j=0;j<101;j++){
			if (j<50){
				cells[k][0][j]=3;
				cells[k][100][j]=2;
			}
			else{
				cells[k][0][j]=2;
				cells[k][100][j]=3;
			}			
		}
	}
	
	for (int k=0; k<layer_num-1;k++){
		for (int i=0;i<101;i+=2){
			for(int j=0;j<101;j+=2){
				cells[k][i][j]=-1;
			}
		}
	}
}

void flow_network::write_output(const char *test_case){
	for(int k=0;k<layer_num-1;k++){
		BasicExcel xls;

		 // create sheet 1 and get the associated BasicExcelWorksheet pointer
		xls.New(1);
		BasicExcelWorksheet* sheet = xls.GetWorksheet(0);

		XLSFormatManager fmt_mgr(xls);


		 // Create a table containing an header row in bold and four rows below.

		ExcelFont font_bold;
		font_bold._weight = FW_BOLD; // 700

		CellFormat fmt_bold(fmt_mgr);
		fmt_bold.set_font(font_bold);

		ExcelFont font_red_bold;
		font_red_bold._weight = FW_BOLD;
		font_red_bold._color_index = EGA_BLACK;
		CellFormat color_1(fmt_mgr, font_red_bold);
		color_1.set_color1(COLOR1_PAT_SOLID);
		color_1.set_color2(MAKE_COLOR2(29,0));
		CellFormat color_2(fmt_mgr, font_red_bold);
		color_2.set_color1(COLOR1_PAT_SOLID);
		color_2.set_color2(MAKE_COLOR2(16,0));
		for (int i=0;i<101;i++){
			for(int j=0;j<101;j++){
				BasicExcelCell* cell = sheet->Cell(i, j);
				sheet->Cell(i, j)->Set(cells[k][i][j]);
				if (cells[k][i][j]==-1){
					cell->SetFormat(color_2);
				}
				else{
					cell->SetFormat(color_1);
				}
			}
		}
		for (int i=0;i<101;i++){
			sheet->SetColWidth(i,950);
		}
		string temp = test_case;
		char layernum = k+48;
		string test_case_num = "";
		test_case_num += test_case[10];
		test_case_num += test_case[11];
		string output_name="";
		output_name += "cada030_problemA_testcase";
		output_name += test_case_num;
		if(layer_num-1 > 1){
			output_name += "_channellayer";
			output_name += layernum;
		}
		output_name += ".xls";
		xls.SaveAs(&output_name[0]);	
	}
	
}


