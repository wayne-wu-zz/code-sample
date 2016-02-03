// LongestCommonSubsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int find_lcs(int arr1[], int arr2[], int i, int j);
int longest_common_subseq(int arr1[], int arr2[], int i, int j, int** lcs_mag);
int max(int a, int b);

int main()
{
	int n, m;
	cin >> n >> m;

	int* arr1 = new int[n];
	int* arr2 = new int[m];

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	int num = find_lcs(arr1, arr2, n, m);

	int size; 
	cin >> size;
	
	delete arr1; 
	delete arr2; 
}

int find_lcs(int arr1[], int arr2[], int i, int j) {

	//2D array that stores the magintude of lcs
	int** lcs_mag = new int*[i];
	for (int k = 0; k < i; k++) {
		lcs_mag[k] = new int[j]();
	}

	//2D array that stores the flagging
	bool** flag = new bool*[i];
	for (int k = 0; k < i; k++) {
		flag[k] = new bool[j]();
	}

	int num = longest_common_subseq(arr1, arr2, i-1, j-1, lcs_mag);

	cout << num;

	//TODO: Find the subsequence using bottom-up dynamic programming (using lcs_mag)

	return num;
}


int longest_common_subseq(int arr1[], int arr2[], int i, int j, int** lcs_mag) {

	if (i >= 0 && j >= 0) {
		//memo-ization algo
		if (lcs_mag[i][j]) {
			return lcs_mag[i][j];
		}

		if (arr1[i] == arr2[j]) {
			lcs_mag[i][j] = longest_common_subseq(arr1, arr2, i - 1, j - 1, lcs_mag) + 1;
		}
		else {
			//branch-off
			lcs_mag[i][j] = max(longest_common_subseq(arr1, arr2, i, j - 1, lcs_mag), longest_common_subseq(arr1, arr2, i, j - 1, lcs_mag));
		}

		return lcs_mag[i][j];
	}

	//BaseCase-ish
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

