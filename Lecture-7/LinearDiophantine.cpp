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
	// applesprice*x + organesprice*y = totalamount;
	// Ax + By = C

	int totalamount = 4505489;
	int applesprice = 25;
	int organesprice = 18;

	int C = totalamount;
	int B = organesprice;
	int A = applesprice;

	int g = gcd1(applesprice, organesprice);
	cout << g << endl;
	if (( totalamount % g ) != 0) {
		cout << "Not possible" << endl;
		return 0;
	}

	ExtendedEuclidAlgo(applesprice, organesprice);

	int lowerLimit = ceil((x * C * g / B));
	int upperLimit = (y * C * g / A);
	cout << lowerLimit << endl;
	cout << upperLimit << endl;
	bool isPossible = false;
	for (int i = lowerLimit ; i <= upperLimit ; i++) {

		int xd = x * C / g + (B / g) * i;
		int yd = y * C / g - (A / g) * i;
		// cout << xd << ", " << yd << endl;
		if (xd >= 0 and yd >= 0) {
			cout << "Apples : " << xd << ", Oranges: " << yd << endl;
			isPossible = true;
			cout << "Total Paise kitne lage: " << applesprice*xd + organesprice*yd << endl;

			// break;
		}
	}
	if (isPossible == false) {
		cout << "Not possible to buy fruits in +ve quantity" << endl;
	}


	return 0;
}
















