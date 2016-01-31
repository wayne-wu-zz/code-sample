// Fibonacci Modified (C++).cpp : Defines the entry point for the console application.
// Fibonacci Modified:
// A, B -> Two terms that are given 
// N -> The term that you want to find 
// T(N+2) = T(N+1)^2 + T(N)

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long fib_N(int a, int b, int n);
int fib_2(int a, int b, int n);

int main()
{
	int a = 0;
	int b = 1;
	int n = 5;

	cin >> a >> b >> n;
	
	int ans = fib_2(a, b, n);

	cout << ans << endl;
	cin >> n;
}

long fib_N(int a, int b, int n) {

	//recursive

	if (n == 1) {
		return a; //base case
	}
	if (n == 2) {
		return b; //base case
	}

	long current_fib;
	current_fib = (pow(fib_N(a, b, n - 1), 2)) + fib_N(a, b, n-2);

	return current_fib;
}

int fib_2(int a, int b, int n) {

	//Non-recursive

	int a1 = a, a2 = b;
	int nextFib, i;

	i = 3;
	while (i <= n) {
		nextFib = pow(a2, 2) + a1;
		a1 = a2;
		a2 = nextFib;
		i++;
	}

	return nextFib;
}