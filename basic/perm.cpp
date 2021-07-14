/*
@file perm.cpp
@brief display all possible permutations of a given input string

@author xnomas
*/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define NO_ARG 1

int main(int argc, char const *argv[])
{
	if(argc != 2) 
	{
		cerr << "ERROR: No string provided! Use: " << argv[0] << " {string}" << endl;
		exit(NO_ARG);
	}

	string to_perm = argv[1];
	sort(to_perm.begin(), to_perm.end());

	cout << to_perm << endl;

	while(next_permutation(to_perm.begin(), to_perm.end())) 
	{
		cout << to_perm << endl;
	}

	return 0;
}