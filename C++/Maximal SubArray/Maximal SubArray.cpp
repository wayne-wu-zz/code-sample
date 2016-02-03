// Maximal SubArray.cpp : Defines the entry point for the console application.
//

/* Input Sample: 
2
4
1 2 3 4
6
2 -1 2 3 4 -5
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std;

int maximum_subarray(int nums[], int size);

int main()
{
	int size = 6;
	cin >> size;
	int nums[6];
	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}
	int best_sum = maximum_subarray(nums, size);

	//cout << best_sum; 
	cin >> size;
}

int maximal_sum(int nums[], int size) {
	
	int temp_sum = 0;
	int overall_sum = 0;
	for (int i = 0; i < size; i++) {
		temp_sum += nums[0];
		if (temp_sum >= overall_sum) {
			overall_sum = temp_sum;
		}
	}
	return overall_sum;
}

int maximum_subarray(int nums[], int n) {

	int current_index = n - 1;
	int current_sum = 0; 
	int best_sum = 0; 
	int overall_best_sum = 0;
	int overall_current_sum = 0;

	for (int i = 0; i < n; i++) {
		//contiguous subarray
		current_sum = max(0, current_sum + nums[i]);
		best_sum = max(current_sum, best_sum);

		//not contiguous subarray
		overall_current_sum += nums[i];
		if (overall_current_sum >= overall_best_sum) {
			overall_best_sum = overall_current_sum;
		}
		else {
			overall_current_sum = overall_best_sum;
		}
	}

	cout << best_sum << " " << overall_current_sum;

	return best_sum;
	//current_sum = maximum_subarray(nums, (current_index - 1)) - nums[current_index];
}

int max(int a, int b) {
	if (a > b) {
		return a; 
	}
	else {
		return b; 
	}
}

