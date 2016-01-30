// Sort Matrix Columns (C++).cpp : Defines the entry point for the console application.
// You have a matrix of integers of N*N size. 
// You should sort the columns in the matrix by first row in ascending order. 
// If the numbers in the first line are equal - 
// you should sort it by the lowest number of second line 
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

void sort_matrix(vector<vector<int>>* matrix);
void swap_columns(vector<vector<int>>* matrix, int col1, int col2);
bool compare_col(vector<int> col1, vector<int> col2);
vector<vector<int>> transpose_matrix(vector<vector<int>> matrix);

int main()
{
	vector<vector<int>> matrix;

	string line;
	vector<int> row;

	while (getline(cin, line)) {
		istringstream iss(line);
		string input; 
		if (line.empty()) 
			break;

		int num;
		while (iss >> input) {
			if (input == "|") {
				matrix.push_back(row); //add row
				row.clear(); //clear list to restart
			}
			else {
				num = stoi(input);
				row.push_back(num);
			}
		}
		matrix.push_back(row); //push back the last one
	}

	cout << matrix[0][0] << matrix[0][1] << matrix[0][2] << endl;
	cout << matrix[1][0] << matrix[1][1] << matrix[1][2] << endl;
	cout << matrix[2][0] << matrix[2][1] << matrix[2][2] << endl;
 
	matrix = transpose_matrix(matrix); //row -> col for easier sorting

	sort_matrix(&matrix);

	matrix = transpose_matrix(matrix);

	//printing
	for each(vector<int> var in matrix) {
		for each (int num in var) {
			cout << num << " ";
		}
		cout << "| ";
	}
	cout << endl; 

	int num;
	cin >> num;

    return 0;
}

void sort_matrix(vector<vector<int>>* matrix) {
	
	/* Sort the array */

	int size = (*matrix).size();
	for (int j = 1; j < size; j++)
		for (int k = j; k > 0 && compare_col((*matrix)[k], (*matrix)[k-1]); k--) {
			swap_columns(matrix, k, k-1);
		}
}

void swap_columns(vector<vector<int>>* matrix, int col1, int col2) {
	/* Swap the matrix given col1 & col2 */

	vector<int> temp_col; 
	temp_col = (*matrix)[col1];
	(*matrix)[col1] = (*matrix)[col2];
	(*matrix)[col2] = temp_col;

}

bool compare_col(vector<int> col1, vector<int> col2) {
	/* Compare col1 and col2, if col1 less than col2 return true, else false*/

	for (int comparing_row = 0; comparing_row < col1.size(); comparing_row++){
		if (col1[comparing_row] < col2[comparing_row])
			return true;
		else if (col1[comparing_row] > col2[comparing_row])
			return false;
	}
	return false;
}

vector<vector<int>> transpose_matrix(vector<vector<int>> matrix) {
	/* Change the inner vector from row to col for easier swapping */

	vector<vector<int>> temp_matrix;
	vector<int> temp;

	for (int i = 0; i < matrix.size(); i++) {
		temp.clear();
		for (int j = 0; j < matrix.size(); j++) {
			temp.push_back(matrix[j][i]);
		}
		temp_matrix.push_back(temp);
	}	
	
	return temp_matrix;

}