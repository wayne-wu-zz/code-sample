// PointsInAPlane.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <math.h>

using namespace std;

struct Point {
	int x; //x_cord 
	int y; //y_cord
	Point* colinear; //points to another point in the colinear path
};

int main()
{
	int n; 
	cin >> n;

	Point* coordinates = new Point[n];

	for (int i = 0; i < n; i++) {
		cin >> coordinates[i].x >> coordinates[i].y;
	}

	delete coordinates;

    return 0;
}


int min_ways(Point coordinates[], int size) {


}