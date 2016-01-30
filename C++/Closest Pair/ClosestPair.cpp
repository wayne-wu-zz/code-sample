// ConsoleApplication2.cpp : Defines the entry point for the console application.
// You will be given the x/y co-ordinates of several locations. 
// You will be laying out 1 cable between two of these locations. 
// In order to minimise the cost, your task is to find the shortest distance between a pair of locations, 
// so that pair can be chosen for the cable installation.

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> coordinates; //*TODO: This is not valid
float min_distance = 0;

float calc_distance(vector<int> pt1, vector<int> pt2);

int main()
{

	int coordinates_num = 0; 	
	cin >> coordinates_num;

	int pt[2] = { 0,0 };
	for (int i = 0; i < coordinates_num; i++) {
		vector<int> coordinate;
		cin >> pt[0] >> pt[1];
		coordinate.push_back(pt[0]);
		coordinate.push_back(pt[1]);
		coordinates.push_back(coordinate);
	}

	int num;
	cin >> num;

	for each(vector<int> var in coordinates) {
		cout << "x:" << var[0] << ", y:" << var[1] << endl;
	}


	if (num == 0) {
		float min = 0;
		for (int i = 0; i < (coordinates.size() - 1); i++) {
			float  distance = calc_distance(coordinates[i], coordinates[i + 1]);
			if (distance <= min || min == 0) {
				min = distance;
			}
		}
		min_distance = min;
	}
	else {
		cout << "You've entered more than " << coordinates_num << "points." << endl;
	}

	cout << "Smallest Distance: " << min_distance << endl;
	cin >> num;

    return 0;
}

float calc_distance(vector<int> pt1, vector<int> pt2) {
	//calculate distance between two points
	float distance = sqrt(pow(pt2[0] - pt1[0], 2) + pow((pt2[1] - pt1[1]), 2));
	//cout << distance << endl;
	return distance;
}
