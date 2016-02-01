// Minimum Path Sum (C++).cpp : Defines the entry point for the console application.
// You are given an n*n matrix of integers. 
// You can move only right and down. 
// Calculate the minimal path sum from the top left to the bottom right

/*
Input Sample:
3
1 2 3
4 5 6
7 8 9
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max(int a, int b);
int find_sum(vector<vector<int>> matrix);
int minimum_path_sum(vector<vector<int>> matrix, int i, int j);

int main()
{
	//NxN
	int matrix_size;
	cin >> matrix_size;
	
	vector<vector<int>> matrix;
	for (int i = 0; i < matrix_size; i++) {
		vector<int> row;
		int num;

		for (int j = 0; j < matrix_size; j++) {
			cin >> num;
			row.push_back(num);
		}

		matrix.push_back(row);
	}

	for each(vector<int> row in matrix) {
		for each(int num in row) {
			cout << num << " ";
		}
		cout << endl;
	}

	int sum = find_sum(matrix);

	cin >> matrix_size;
    return 0;
}

int find_sum(vector<vector<int>> matrix) {

	//we want the minimum path sum of matrix[0][0] which is the first element
	int sum = minimum_path_sum(matrix, 0, 0);

	cout << sum <<endl;

	return sum;
}

int minimum_path_sum(vector<vector<int>> matrix, int i, int j) {

	//TODO: Memo-ization algorithm to avoid repetitive work

	int size = matrix.size(); //n x n matrix
	//cout << "Size: " << size <<endl;

	if (i < size && j < size) {
		//cout << "i: " << i << " j: " << j << endl;

		//cout << matrix[i][j] << endl; 

		int max_sum;

		max_sum = max(minimum_path_sum(matrix, i+1, j), minimum_path_sum(matrix, i, j+1)) + matrix[i][j];

		return max_sum;
	}

	//cout << "Out of bound. Returning 0\n";

	return 0;
}


int max(int a, int b) {

	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
