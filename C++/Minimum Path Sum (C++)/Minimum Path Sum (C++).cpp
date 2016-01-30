// Minimum Path Sum (C++).cpp : Defines the entry point for the console application.
// You are given an n*n matrix of integers. 
// You can move only right and down. 
// Calculate the minimal path sum from the top left to the bottom right

/*
Input Sample:
2
4,6
2,8
3
1,2,3
4,5,6
7,8,9
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int matrix_size;
	cin >> matrix_size;
	
	vector<vector<int>> matrix;
	for (int i = 0; i < matrix_size; i++) {
		vector<int> row;
		int num[] = { 0,0 };
		cin >> num[0] >> num[1];
		row.push_back(num[0]);
		row.push_back(num[1]);
	}

	int i = 0;
	int k = 0;
	
	int min_sum = 0;
	int sum = 0;

	for (int i = 0; i <= matrix_size; i++) {
		for (int k = 0; k <= matrix_size; k++)
			sum += matrix[k][i];
	}

	//right -> i++
	//down -> k++
	
    return 0;
}
