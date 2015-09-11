#include "chip_info.h"

bool chip_data::read(const char *input){//*pointer
	ifstream fin (input);
	char this_data;
	int this_type = 0;
	string current_data = "";
	stringstream ss;
	
	fin.get(this_data);
	while(!fin.eof()){
		fin.get(this_data);
		if(this_data == '\n' || this_data == ' '){
			current_data = "";
			continue;
		}else{
			if( (48 <= this_data && this_data <= 57) || (65 <= this_data && this_data <= 90) || (97 <= this_data && this_data <= 122) || this_data == '_' || this_data == '.'){
				current_data += this_data;
			}
		}
		if(this_data == '=' || this_data == '('){
			if(current_data == "N"){
				fin >> layer_num;
				current_data = "";
			}
			else if(current_data == "F"){
				current_data = "";
				int die_num = 0;
				while(1){
					fin.get(this_data);
					if( (48 <= this_data && this_data <= 57) || (65 <= this_data && this_data <= 90) || (97 <= this_data && this_data <= 122) || this_data == '_' || this_data == '.'){
						current_data += this_data;
					}
					if(this_data == ',' || this_data == '}'){
						die temp;
						temp.name = current_data;
						dies.push_back(temp);
						current_data = "";
					}
					if(this_data == '='){
						int this_die = -1;
						for(int i=0;i<dies.size();i++ ){
							if(dies[i].name == current_data){
								this_die = i;
								current_data = "";
								die_num ++ ;
							}
						}
						while(1){
							fin.get(this_data);
							if(this_data == '\n' || this_data == ' '){
								current_data = "";
								continue;
							}
							if( (48 <= this_data && this_data <= 57) || (65 <= this_data && this_data <= 90) || (97 <= this_data && this_data <= 122) || this_data == '_' || this_data == '.'){
								current_data += this_data;
							}
							if(this_data == ':'){
								block temp;
								temp.name = current_data;
								
								dies[this_die].blocks.push_back(temp);
								current_data = "";
							}
							if(this_data == ',' || this_data == ')'){
								if(dies[this_die].blocks[dies[this_die].blocks.size()-1].lx == -1){
									ss << current_data;
									ss >> dies[this_die].blocks[dies[this_die].blocks.size()-1].lx;
								}
								else if(dies[this_die].blocks[dies[this_die].blocks.size()-1].ly == -1){
									ss << current_data;
									ss >> dies[this_die].blocks[dies[this_die].blocks.size()-1].ly;
								}
								else if(dies[this_die].blocks[dies[this_die].blocks.size()-1].width == -1){
									ss << current_data;
									ss >> dies[this_die].blocks[dies[this_die].blocks.size()-1].width;
								}
								else if(dies[this_die].blocks[dies[this_die].blocks.size()-1].length == -1){
									ss << current_data;
									ss >> dies[this_die].blocks[dies[this_die].blocks.size()-1].length;
								}
								ss.clear();
								ss.str("");
								current_data = "";
							}
							if(this_data == '}'){
								break;
							}
						}
					}
					if(die_num == dies.size() && die_num != 0){
						break;
					}
				}
			}
			else if(current_data == "P"){
				current_data = "";
				while(1){
					fin.get(this_data);
					if( (48 <= this_data && this_data <= 57) || (65 <= this_data && this_data <= 90) || (97 <= this_data && this_data <= 122) || this_data == '_' || this_data == '.'){
						current_data += this_data;
					}
					if(this_data == ')'){
						int this_die;
						for(int i=0;i<dies.size();i++){
							if(dies[i].name == current_data){
								this_die = i;
								current_data = "";
							}
						}
						int this_block = 0;
						while(1){
							fin.get(this_data);
							if( (48 <= this_data && this_data <= 57) || (65 <= this_data && this_data <= 90) || (97 <= this_data && this_data <= 122) || this_data == '_' || this_data == '.'){
								current_data += this_data;
							}
							if(this_data == ';' || this_data == '}'){
								ss << current_data;
								ss >> dies[this_die].blocks[this_block++].power;
								ss.clear();
								ss.str("");
								current_data = "";
							}
							if(this_data == '}'){
								break;
							}
						}
						break;
					}
					
				}
			}
			else if(current_data == "Fil"){
				current_data = "";
				while(1){
					int constraint_num = 0;
					fin.get(this_data);
					if( (48 <= this_data && this_data <= 57) || (65 <= this_data && this_data <= 90) || (97 <= this_data && this_data <= 122) || this_data == '_' || this_data == '.'){
						current_data += this_data;
					}
					if(this_data == ',' || this_data == '}'){
						block temp;
						temp.name = current_data;
						constraint.push_back(temp);
						current_data = "";
					}
					if(this_data == '='){
						int this_con = -1;
						for(int i=0;i<constraint.size();i++ ){
							if(constraint[i].name == current_data){
								this_con = i;
								current_data = "";
								constraint_num ++ ;
							}
						}
						while(1){
							fin.get(this_data);
							if( (48 <= this_data && this_data <= 57) || (65 <= this_data && this_data <= 90) || (97 <= this_data && this_data <= 122) || this_data == '_' || this_data == '.'){
								current_data += this_data;
							}
							if(this_data == ',' || this_data == ')'){
								if(constraint[constraint.size()-1].lx == -1){
									ss << current_data;
									ss >> constraint[constraint.size()-1].lx;
								}
								else if(constraint[constraint.size()-1].ly == -1){
									ss << current_data;
									ss >> constraint[constraint.size()-1].ly;
								}
								else if(constraint[constraint.size()-1].width == -1){
									ss << current_data;
									ss >> constraint[constraint.size()-1].width;
								}
								else if(constraint[constraint.size()-1].length == -1){
									ss << current_data;
									ss >> constraint[constraint.size()-1].length;
								}
								ss.clear();
								ss.str("");
								current_data = "";
							}
							if(this_data == '}'){
								break;
							}
						}
					}
					if(constraint_num == constraint.size() && constraint_num != 0){
						break;
					}
				}
			}
			else if(current_data == "T"){
				current_data = "";
				fin >> T_max >>T_gredient;
			}
			else if(current_data == "W"){
				current_data = "";
				fin >> width;
			}
			else if(current_data == "H"){
				current_data = "";
				fin >> height;
			}
			else if(current_data == "L"){
				current_data = "";
				fin >> length;
			}
			else if(current_data == "C"){
				current_data = "";
				fin >> case_num;
			}
			else{
				cout << "unknown flag" << endl;
				return false;
			}
		}
		else{
			if(this_type == 1){
				ss << current_data;
				ss >> layer_num;
				ss.clear();
				ss.str("");
				current_data = "";
				this_type = 0;
			}
			else if(this_type == 2){
				
			}
		}
	}
	return true;
}

void chip_data::write_output(const char *test_case){
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
				sheet->Cell(i, j)->Set(channel[k][i][j]);
				if (channel[k][i][j]==-1){
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


