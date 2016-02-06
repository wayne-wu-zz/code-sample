//Optimal Game Strategy

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int optimal_sum(int nums[], int i, int j);

int main()
{
	int size = 3;

	while (size % 2 != 0) {
		cin >> size;
	}

	int* nums = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}
	
	int i = 0; //start
	int j = size - 1;

	int sum = optimal_sum(nums, i, j);

	cout << sum << endl;

	cin >> size; 
}


int optimal_sum(int nums[], int i, int j) {

	if (i < j) {
		int max_sum;
		//max_sum = max(min(option1 + option2) + value, min(option3 + option4) + value))
		max_sum = max(min(optimal_sum(nums, i + 1, j - 1), optimal_sum(nums, i + 2, j)) + nums[i],
			min(optimal_sum(nums, i + 1, j - 1), optimal_sum(nums, i, j - 2)) + nums[j]);
		return max_sum;
	}
	else {
		return 0;
	}
}