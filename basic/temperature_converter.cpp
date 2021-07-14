/*
@file temperature_converter.cpp
@brief In this challenge, write a program that takes in three arguments, a start temperature (in Celsius), an end temperature (in Celsius) and a step size.
Print out a table that goes from the start temperature to the end temperature, in steps of the step size; 

@author xnomas
*/


#include <iostream>
#include <iomanip>

using namespace std;

#define START_TEMP_ERROR 1
#define END_TEMP_ERROR 2
#define STEP_ERROR 3


float convert(int temperature) 
{
	return temperature * 9/5 + 32;
}


void print_table(int start_temperature, int end_temperature, int step) {
	printf("%-10s   %10s\n", "Celsius", "Fahrenheit");
	printf("%-10s   %10s\n", "-------", "----------");

	for(int i=start_temperature; i <= end_temperature; i += step) {
		printf("%-10f   %10f\n", (float) i, convert(i));
	}
}


int main(int argc, char const *argv[])
{
	int start_temperature, end_temperature, step;

	cout << "Please give in a lower limit, limit >= 0: ";
	cin >> start_temperature;

	if(start_temperature < 0) 
	{
		cerr << "ERROR: Starting temperature must be above 0!" << endl;
		exit(START_TEMP_ERROR);
	}	

	cout << "Please give in a higher limit, 10 < limit <= 50000: ";
	cin >> end_temperature;
	
	if( (end_temperature <= 10) || (end_temperature > 50000) )
	{
		cerr << "ERROR: End temperature must be between 10 and 50000!" << endl;
		exit(END_TEMP_ERROR);
	}

	cout << "Please give in a step, 0 < step <= 10: ";
	cin >> step;

	if ( (step <= 0) || (step > 10) )
	{
		cerr << "ERROR: Step must be between 1 and 10!" << endl;
		exit(STEP_ERROR);
	} else if ( step > end_temperature - start_temperature )
	{
		cerr << "ERROR: Step must not be greater than the difference between temperatures!" << endl;
		exit(STEP_ERROR);	
	}
	
	print_table(start_temperature, end_temperature, step);

	return 0;
}