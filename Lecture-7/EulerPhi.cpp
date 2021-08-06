// EulerPhi.cpp
#include <iostream>
using namespace std;

int EulerPhi(int n) {
	int ans = n;
	// n*(1-1/p1)*(1-1/p2);
	for (int i = 2 ; i * i <= n ; i++) {
		int a = i;
		if (n % a == 0) {
			ans -= ans / i;

			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		ans -= ans / n;
	}
	return ans;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	// cin >> n;
	n = 100;

	cout << EulerPhi(n) << endl;

	return 0;
}
















