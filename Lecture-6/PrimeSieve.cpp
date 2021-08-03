// PrimeSieve.cpp
#include <iostream>
#include <bitset>
using namespace std;
// bool p[10000000] = {0};
bitset<10000000> p;

void sieve(int n) {

	// for (int i = 2 ; i <= n ; i++) {
	// 	if (p[i] == 0) {
	// 		for (int j = 2 * i; j <= n ; j += i) {
	// 			if (p[j] == 0) {
	// 				p[j] = 1;
	// 			}
	// 		}
	// 	}
	// }
	// Optimized Prime Sieve - 1
	// for (int i = 2 ; i <= n ; i++) {
	// 	if (p[i] == 0) {
	// 		for (int j = i * i; j <= n ; j += i) {
	// 			if (p[j] == 0) {
	// 				p[j] = 1;
	// 			}
	// 		}
	// 	}
	// }
	// Optimized Prime Sieve - 2
	for (int i = 3 ; i <= n ; i += 2) {
		if (p[i] == 0) {
			for (int j = i * i; j <= n ; j += i) {
				if (p[j] == 0) {
					p[j] = 1;
				}
			}
		}
	}
	// cout << 2 << " ";
	for (int i = 3; i <= n ; i += 2)
		if (p[i] == 0)
			cout << i << " ";

	cout << endl;
}

int main() {

	int n;
	cin >> n;
	sieve(n);

	return 0;
}
















