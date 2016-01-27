// Sort Matrix Columns (C++).cpp : Defines the entry point for the console application.
// You have a matrix of integers of N*N size. 
// You should sort the columns in the matrix by first row in ascending order. 
// If the numbers in the first line are equal - 
// you should sort it by the lowest number of second line, 
// if numbers in the second line are also equal you should sort it by the next row etc.

/*Input Sample: 
1 2 3 | 4 5 6 | 7 8 9
*/

#include "stdafx.h"
#include <iostream>
#include <vector> //construct matrix
#include <regex>
#include <string>
#include <sstream>

using namespace std;

void sort_matrix(vector<vector<int>> matrix);

int main()
{

	vector<vector<int>> matrix;

	string line;
	vector<int> row;
	bool isDone = false;

	while (getline(cin, line)) {
		istringstream iss(line);
		string input; 
		if (line.empty()) 
			break;

		while (iss >> input) {
			if (input == "|") {
				matrix.push_back(row); //add row
				row.clear(); //clear list to restart
			}
			else {
				int num = stoi(input);
				row.push_back(num);
			}
		}
		matrix.push_back(row); //push back the last one
	}

	cout << matrix[0][0] << matrix[0][1] << matrix[0][2] << endl;
	cout << matrix[1][0] << matrix[1][1] << matrix[1][2] << endl;
	cout << matrix[2][0] << matrix[2][1] << matrix[2][2] << endl;
 

	//need to send EOL character 
	int num;
	cin >> num;

    return 0;
}

void sort_matrix(vector<vector<int>> matrix) {
	
	int i = 0;
	int j = 0; 

	bool isSorted = false;
	while (!isSorted) {
		for (int j = 0; j < matrix[j].size; j++) {
			
		}
	}
	for (int i = 0; i < matrix.size(); i++) {
	}

	for each(int var in matrix[j]) {
		
		//pass
	}
	//sort the matrix. Should be dynamic array
}