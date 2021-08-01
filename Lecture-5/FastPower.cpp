#include <iostream>
using namespace std;

int power(int a, int n) {
	if (n == 1) {
		return a;
	}

	if (n & 1) {
		return a * power(a, n - 1);
	}

	int x = power(a, n / 2);
	return x * x;
}

int main() {

	int n;
	cin >> n;

	cout << power(2, n) << endl;

	return 0;
}
















