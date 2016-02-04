// StringPermutations.cpp : Defines the entry point for the console application.
// Write a program which prints all the permutations of a string in alphabetical order. 
// We consider that digits < upper case letters < lower case letters.
// The sorting should be performed in ascending order.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void find_permutations(string input, vector<string> &permutations);
void add_permutations(string character, vector<string> &permutations);

int main()
{
	string input; 
	cin >> input; 

	vector<string> permutations;

	find_permutations(input, permutations);

	//TODO: Sort Permutations. May be able to use Binary set instead of vector for instant sorting

	for each(string var in permutations) {
		cout << var << " ";
	}
	cout << endl;

	cin >> input;

    return 0;
}

void find_permutations(string input, vector<string> &permutations) {
	
	if (input.size() > 1) {
		string character(1, input[input.size() - 1]);
		input.pop_back(); //remove the last character
		find_permutations(input, permutations); 
		add_permutations(character, permutations);
	}
	else {
		permutations.push_back(input);
	}
}

void add_permutations(string character, vector<string> &permutations) {

	vector<string> temp_permu; //store it locally
	if (!permutations.empty()) {
		for each(string var in permutations) {
			for (int i = 0; i <= var.size(); i++) {
				string temp = var;
				temp.insert(i, character);
				temp_permu.push_back(temp);
			}
		}
	}
	else {
		temp_permu.push_back(character); //only character
	}
	permutations = temp_permu;

}