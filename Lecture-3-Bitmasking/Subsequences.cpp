// Subsequences.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	char a[100];
	cin >> a;

	n = strlen(a);

	for (int k = 0 ; k < (1 << n) ; k++) {
		int pos = 0;
		int i = k;
		while (i) {
			if (i & 1) {
				cout << a[pos];
			}
			pos++;
			i = i >> 1;
		}
		cout << endl;
	}

	return 0;
}
















