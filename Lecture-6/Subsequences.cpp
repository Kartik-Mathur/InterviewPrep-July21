// Subsequences.cpp
#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int primes[] = {2, 3, 5};
	int n = 3;
	int number = 1000;
	int ans = 0;

	for (int i = 1 ; i < (1 << n) ; i++) {
		int product = 1;
		int setBits = __builtin_popcount(i);
		cout << "Number of setbits: " << setBits << ", ";
		for (int j = 0 ; j < n ; j++) {
			if (i & (1 << j)) {
				cout << primes[j] << " ";
				product *= primes[j];
			}
		}
		// if I have multiplied numbers odd times
		// then add it
		// else subtract it from ans
		cout << " Product: " << product << endl;
	}

	// cout << ans << endl;
	return 0;
}
















