// PizzaProblem.cpp
#include <iostream>
using namespace std;
#define ll long long int

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;

		if (n < 6) {
			cout << 15 << endl;
		}
		else if (n % 2 == 0) {
			cout << n / 2 * 5 << endl;
		}
		else {
			cout << (n + 1) / 2 * 5 << endl;
		}
	}
	return 0;
}
















