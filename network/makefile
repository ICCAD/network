network_sol:main.o network.o matrix_solution.o constraint_check.o chip_info.o BasicExcel.o ExcelFormat.o network_gen.o
	g++ -g -o network_sol main.o network.o matrix_solution.o constraint_check.o chip_info.o BasicExcel.o ExcelFormat.o network_gen.o
main.o:main.cpp matrix_solution.h chip_info.h
	g++ -g -c main.cpp matrix_solution.h chip_info.h
network.o:network.cpp matrix_solution.h
	g++ -g -c network.cpp network.h
matrix_solution.o:matrix_solution.cpp matrix_solution.h network.h
	g++ -g -c matrix_solution.cpp matrix_solution.h network.h
constraint_check.o:constraint_check.cpp constraint_check.h
	g++ -g -c constraint_check.cpp constraint_check.h
chip_info.o:chip_info.cpp chip_info.h
	g++ -g -c chip_info.cpp chip_info.h
BasicExcel.o:BasicExcel.cpp ExcelFormat.h
	g++ -g -c BasicExcel.cpp ExcelFormat.h
ExcelFormat.o:ExcelFormat.cpp ExcelFormat.h BasicExcel.hpp 
	g++ -g -c ExcelFormat.cpp ExcelFormat.h BasicExcel.hpp
network_gen.o:network_gen.cpp network_gen.h chip_info.h
	g++ -g -c network_gen.cpp network_gen.h chip_info.h
clean:
	rm network_sol main.o network.o matrix_solution.o constraint_check.o chip_info.o BasicExcel.o ExcelFormat.o network_gen.o