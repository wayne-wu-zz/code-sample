// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void find_combinations(string input, vector<string> &combinations);
void add_combinations(string character, vector<string> &combinations);
vector<int> calculate_ugly_numbers(vector<string> &combinations);

int main()
{
	string input;
	cin >> input;

	vector<string> combinations;
	find_combinations(input, combinations);

	for each(string var in combinations) {
		cout << var << " ";
	}
	cout << endl;

	//calculate_ugly_numbers(combinations); 

	cin >> input;

	return 0; 
}

void find_combinations(string input, vector<string> &combinations) {
	/* The recursive function that finds the combination */
	if (input.size() > 1) {
		string character(1, input[input.size() - 1]); //stores the last character
		input.pop_back(); //remove the last element  
		find_combinations(input, combinations);
		add_combinations(character, combinations);
	}
	else {
		combinations.push_back(input);
	}
}

void add_combinations(string character, vector<string> &combinations) {
	/* Adds character to exsiting combination with +, - or nothing */
	vector<string> temp_combo;
	string line;
	for each(string var in combinations) {
		line = var;
		line.insert(var.size(), "+"+character);
		temp_combo.push_back(line);
		line = var;
		line.insert(var.size(), "-"+character);
		temp_combo.push_back(line);
		line = var;
		line.insert(var.size(), character);
		temp_combo.push_back(line);
	}
	combinations = temp_combo;
}

vector<int> calculate_ugly_numbers(vector<string> &combinations) {
	/* Evaluate the string and calculate the ugly numbers for each combination */
	vector<int> ugly_nums;
	for each(string var in combinations) {
		int num = 0;
		//TODO: evaluate var; need to hack it for C++
		if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
			ugly_nums.push_back(num);
		}
	}

	return ugly_nums;
}
