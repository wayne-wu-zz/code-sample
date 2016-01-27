// Sort Matrix Columns (C++).cpp : Defines the entry point for the console application.
// You have a matrix of integers of N*N size. 
// You should sort the columns in the matrix by first row in ascending order. 
// If the numbers in the first line are equal - 
// you should sort it by the lowest number of second line, 
// if numbers in the second line are also equal you should sort it by the next row etc.

#include "stdafx.h"
#include <iostream>
#include <vector> //construct matrix
#include <regex>
#include <string>

using namespace std;

vector<vector<int>> create_matrix(string line); //row<column>

int main()
{
	vector<vector<int>> matrix;

	string line;
	vector<int> row;

	/*
	while (getline(cin, line, ' ')) {
		if (line == "|") {
			matrix.push_back(row);
			vector<int> row; //new instance of row
		}
		else {
			int num = stoi(line); //convert string to integer
			row.push_back(num); // add integer to row vector
		}
	}
	cout << matrix[0][0] << matrix[0][1] << matrix[0][2]; */
	vector<string> test;

	//need to send EOL character 
	while (getline(cin, line, ' ')) {
		test.push_back(line);
		cout << line;
	}

	for each (string var in test) {
		cout << var;
	}

	int num;
	cin >> num;

    return 0;
}

vector<vector<int>> create_matrix(string line) {

	vector<vector<int>> matrix;

	//generate row vector
	vector<int> row;
	
		
	return matrix;
}