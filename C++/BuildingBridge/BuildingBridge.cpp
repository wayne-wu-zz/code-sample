//Consider a 2-D map with a horizontal river passing through its center. 
//There are n cities on the southern bank with x-coordinates a(1) ... a(n) 
//and n cities on the northern bank with x-coordinates b(1) ... b(n). 
//You want to connect as many north-south pairs of cities as possible with bridges such that no two bridges cross. 
//When connecting cities, you can only connect city i on the northern bank to city i on the southern bank.

//Input Sample:
//5 (n) 
//1 2 3 4 5 (x-coordinates of north) 
//1 2 3 4 5 (x-coordinates of south)

#include <iostream>
#include <map>
#include <algorithm>

using namespace std; 

int lcs(map<int, int>::reverse_iterator north, map<int, int>::reverse_iterator south, map<int, int>::reverse_iterator ii, map<int, int>::reverse_iterator jj);

int main() {

	int cities;

	cin >> cities; 

	map<int, int> north; 
	map<int, int> south;

	int x_coord;
	for (int i = 0; i < cities; i++) {
		cin >> x_coord;
		north[x_coord] = i+1;
	}

	for (int i = 0; i < cities; i++) {
		cin >> x_coord;
		south[x_coord] = i+1;
	}

	/*map<int, int>::iterator it = north.begin();
	for (it; it != north.end(); ++it) {
		cout << it->first << " " << it->second << " ; ";
	}
	cout << endl;

	it = south.begin();
	for (it; it != south.end(); ++it) {
		cout << it->first << " " << it->second << " ; ";
	}
	cout << endl;*/

	map<int, int>::reverse_iterator ii = north.rbegin();
	map<int, int>::reverse_iterator jj = south.rbegin();


	int num; 
	num = lcs(north.rend(), south.rend(), ii, jj);

	cout << "Maximum number of bridges: " << num;
	cin >> cities; 

	return 0;

}

int lcs(const map<int, int>::reverse_iterator north, const map<int, int>::reverse_iterator south, map<int, int>::reverse_iterator ii, map<int, int>::reverse_iterator jj) {

	if (ii!=north && jj!=south) {
		//cout << " North: " << ii->second;
		//cout << " South: " << jj->second << endl;

		int num = 0;
		if (ii->second == jj->second) {
			num = lcs(north, south, next(ii,1), next(jj,1)) + 1;
			cout << num << endl;
		}
		else {
			num = max(lcs(north, south, ii, next(jj,1)), lcs(north, south, next(ii, 1), jj));
		}
		return num;
	}

	return 0;
}