// ConsoleApplication2.cpp : Defines the entry point for the console application.
// You are given a prefix expression. Write a program which evaluates it.

/* Input Sample:
* + 2 3 4
*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int convert_char(char number[]);

double calculate_prefix(vector<char> operators, vector<int> operands);

int main(int argc, char *argv[])
{
	string line;
	getline(cin, line);

	vector<char> operators; //storing operators
	vector<int> operands; //storing numbers

	istringstream iss(line);
	string input;

	while (iss >> input) {
		if (input == "+" || input == "*" || input == "/") {
			if (operators.empty()) {
				operators.push_back(*(input.c_str()));
			}
			else {
				vector<char>::iterator front = operators.begin();
				operators.insert(front, *(input.c_str()));
			}
		}
		else {
			operands.push_back(stoi(input));
		}
	}

	/*
	cout << "Operators: ";
	for each (char var in operators){
		cout << var;
	}
	cout << endl;

	cout << "Operands: ";
	for each (int var in operands) {
		cout << var;
	}
	cout << endl;
	*/

	double result = calculate_prefix(operators, operands);

	cout << "Result: " << result << endl;
	cin >> line; //wait for exit

    return 0;
}

int convert_char(char number[]) {
	//TODO* Convert number given in char to numerical int
	int num1 = number[0] - '0';
	int num2 = number[1] - '0';
	return (num1 + num2 * 10);
}

double calculate_prefix(vector<char> operators, vector<int> operands) {

	double result = 0; 
	int j;
	for (int i = 0; i < operands.size(); i++) {
		j = i - 1;
		if (j >= 0) {
			if (operators[j] == '+') {
				result += operands[i];
			}
			else if (operators[j] == '*') {
				result *= operands[i];
			}
			else if (operators[j] == '/') {
				result /= operands[i];
			}
		}
		else {
			result = operands[i];
		}
	}
	return result;
}
