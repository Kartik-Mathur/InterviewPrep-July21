// LinearDiophantine.cpp
#include <iostream>
using namespace std;

int gcd1(int a, int b) {
	if (b == 0) return a;

	return gcd1(b, a % b);
}

int x, y, gcd;
void ExtendedEuclidAlgo(int a, int b) {
	if (b == 0)	{
		gcd = a;
		x = 1, y = 0;
		return;
	}

	ExtendedEuclidAlgo(b, a % b);
	int cx = y;
	int cy = x - (a / b) * y;
	// cout << cx << " " << cy << endl;
	x = cx;
	y = cy;
}

int main() {

	// int a, b;
	// cin >> a >> b;
	int totalamount = 100;
	int applesprice = 25;
	int organesprice = 18;

	int g = gcd1(applesprice, organesprice);

	cout << g << endl;
	if (( totalamount % g ) != 0) {
		cout << "Not possible" << endl;
		return 0;
	}
	else {
		ExtendedEuclidAlgo(applesprice, organesprice);

		cout << "Apples : " << x << ", Oranges: " << y << endl;
		cout << applesprice*x + organesprice*y << endl;
	}

	return 0;
}
















