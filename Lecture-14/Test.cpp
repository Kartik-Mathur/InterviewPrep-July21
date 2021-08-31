// Test.cpp
#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 3, 4, 5, 6, 6, 6};
	int n = sizeof(a) / sizeof(int);
	for (int i = 0 ; i < n ; i++) {
		bool previousKeEqualHai = false;
		bool NextKeEqualHai = false;

		if (i != 0) {
			if (a[i] == a[i - 1]) previousKeEqualHai = true;
		}
		if (i != n - 1) {
			if (a[i] == a[i + 1]) NextKeEqualHai = true;
		}

		if (previousKeEqualHai == false and NextKeEqualHai == false)
			cout << a[i] << " ";

	}
	cout << endl;
	return 0;
}
















