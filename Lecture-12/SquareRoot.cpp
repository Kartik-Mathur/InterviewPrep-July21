// SquareRoot.cpp
#include <iostream>
#include <iomanip>
using namespace std;

float SquareRoot(int n) {

	float ans = 0;
	int s = 0;
	int e = n;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (mid * mid <= n) {
			ans = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}

	float inc = 0.1;
	for (int places = 1 ; places <= 4 ; places++) {

		while (ans * ans <= n) {
			ans += inc;
		}

		ans = ans - inc;
		inc /= 10;
	}

	return ans;
}

int main() {

	int n = 25;
	// cout << fixed << setprecision(4) << SquareRoot(n) << endl;
	cout << SquareRoot(n) << endl;

	return 0;
}
















