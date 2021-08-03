#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int primes[] = {2, 3, 5, 7, 11};
	int n = 3;
	int number = 1000;
	int ans = 0;

	for (int i = 1 ; i < (1 << n) ; i++) {
		int setBits = __builtin_popcount(i);
		int product = 1;

		for (int j = 0 ; j < n ; j++) {
			if (i & (1 << j)) {
				product *= primes[j];
			}
		}

		if (setBits % 2 == 0) {
			ans -= number / product;
		}
		else {
			ans += number / product;
		}
	}

	cout << ans << endl;
	return 0;
}
















