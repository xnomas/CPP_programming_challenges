/*
@file file_size.cpp
@brief given the name of a file, print out the size of the file, in bytes

@author xnomas
*/

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define NO_ARG 1
#define FILE_ERR 2

int get_file_size(ifstream &file) 
{
	file.seekg(0, ios::end); // seek to end of file
	return file.tellg();	 // tell us the current position to tell us the number of bytes
}


int main(int argc, char const *argv[])
{
	if(argc != 2) 
	{
		cerr << "ERROR: No filename provided! Use: " << argv[0] << " {filename}" << endl;
		exit(NO_ARG);
	}

	ifstream file(argv[1]);

	if(!file.is_open())
	{
		cerr << "ERROR: Could not open file " << argv[1] << endl;
		exit(FILE_ERR);
	}

	cout << get_file_size(file) << " bytes" << endl;

	file.close();
	return 0;
}
