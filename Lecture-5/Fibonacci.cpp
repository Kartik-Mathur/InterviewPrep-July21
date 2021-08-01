// Fibonacci.cpp
#include <iostream>
using namespace std;

double fibo(int n) {
	double phi = (1 + sqrt(5)) / 2;
	double ans = (pow(phi, n) - pow(1 - phi, n)) / sqrt(5);
	return round(ans);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	cout << fibo(n) << endl;


	return 0;
}
















