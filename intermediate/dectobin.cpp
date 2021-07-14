/*
@file tobinary.cpp
@brief Write a program that accepts a base ten (non-fractional) number at the command line and outputs the binary representation of that number.

@author xnomas
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define NO_ARGS 1
#define TOO_BIG_NUMBER 2

void to_binary(int decimal) 
{
	if(decimal == 0)
	{
		cout << 0 << endl;
		return;
	}

	string binary_number = "";
	float temp = decimal;

	while(temp != 0)
	{
		temp = temp / 2;
		if(fmod(temp,1) == 0)
		{
			binary_number.append("0");
		} else
		{
			binary_number.append("1");
		}
		temp = trunc(temp);
	}

	reverse(binary_number.begin(), binary_number.end()); 

	cout << binary_number << endl;

	return;
}

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		cerr << "ERROR: No number provided!" << endl;
	}

	try
	{
		to_binary(stoi(argv[1],nullptr,10));
	}
	catch(out_of_range)
	{
		cerr << "ERROR: Integer too big." << endl;
		exit(TOO_BIG_NUMBER);
	}
	catch (...)
	{
		cerr << "ERROR: There's a mistake in your number." << endl;
		exit(NO_ARGS);
	}
	return 0;
}
