// ExtendedEuclidAlgo.cpp
#include <iostream>
using namespace std;
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
	cout << cx << " " << cy << endl;
	x = cx;
	y = cy;
}

int main() {

	int a, b;
	cin >> a >> b;

	ExtendedEuclidAlgo(a, b);

	cout << x << ", " << y << endl;


	return 0;
}
















