// CheckPrime.cpp
#include <iostream>
using namespace std;

int main() {


	// i <= sqrt(n)
	// i^2 <= n

	int number = 100;

	for (int n = 2 ; n <= number ; n++) {
		bool isPrime = true;

		for (int i = 2 ; i * i <= n ; i++) {
			if (n % i == 0) {
				// cout << "Not Prime" << endl;
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			cout << n << " ";
		}
	}
	cout << endl;



	return 0;
}
















