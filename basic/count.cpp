/*
@file count.cpp
@brief write a program that takes a file as an argument and counts the total number of lines

@author xnomas
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

#define NOT_ENOUGH_ARGS 1
#define FOPEN_ERROR 2

int count_lines(istream &file)
{
	int count = 0;
	string line;

	while(getline(file, line))
	{
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	
	if(argc > 1)
	{
		ifstream file(argv[1]);

		if(!file.is_open())
		{
			cerr << "ERROR: Could not open file " << argv[1] << endl;
			exit(FOPEN_ERROR); 
		}

		cout << count_lines(file) << endl;

		file.close();

	} else {
		cerr << "ERROR: No filename provided!" << endl;
		exit(NOT_ENOUGH_ARGS);
	}
	return 0;
}