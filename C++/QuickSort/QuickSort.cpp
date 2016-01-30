// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void quicksort(int arr[], int left, int right);

int main()
{
	int size = 10;
	int nums[] = {4, 3, 10, 156, 57, 1, 32, 78, 99, 25};

	cout << "Unsorted: ";
	for (int i = 0; i < size; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	quicksort(nums, 0, size - 1);

	cout << "Sorted: ";
	for (int i = 0; i < size; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	cin >> size;
	return 0;
}


void quicksort(int arr[], int left, int right) {

	int left_starting = left;
	int right_starting = right;

	int temp;
	int pivot_value = arr[(left + right) / 2];

	cout << "Pivot: " << pivot_value << endl;

	//partition
	while (left <= right) {
		while (arr[left] < pivot_value) {
			left++;
		}
		while (arr[right] > pivot_value) {
			right--;
		}
		if (left <= right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	};

	if (right > left_starting) {
		quicksort(arr, left_starting, right);
	}

	if (left < right_starting) {
		quicksort(arr, left, right_starting);
	}

}
