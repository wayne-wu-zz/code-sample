// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int *num);

int main()
{
	int num = 10;
	print(&num);
    return 0;
}

void print(int *num) {
	cout << num;
}