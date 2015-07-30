final:main.o network.o matrix_solution.o constraint_check.o chip_data.o BasicExcel.o ExcelFormat.o
	g++ -g -o final main.o network.o matrix_solution.o constraint_check.o
main.o:main.cpp network.h
	g++ -g -c main.cpp network.h
network.o:network.cpp network.h
	g++ -g -c network.cpp network.h
matrix_solution.o:matrix_solution.cpp matrix_solution.h network.h
	g++ -g -c matrix_solution.cpp matrix_solution.h network.h
constraint_check.o:constraint_check.cpp constraint_check.h
	g++ -g -c constraint_check.cpp constraint_check.h
chip_data.o:chip_data.cpp chip_data.h
	g++ -g -c chip_data.cpp chip_data.h
BasicExcel.o:BasicExcel.cpp ExcelFormat.h
	g++ -g -c BasicExcel.cpp ExcelFormat.h
ExcelFormat.o:ExcelFormat.cpp ExcelFormat.h BasicExcel.hpp 
	g++ -g -c ExcelFormat.cpp ExcelFormat.h BasicExcel.hpp
clean:
	rm final main.o network.o matrix_solution.o