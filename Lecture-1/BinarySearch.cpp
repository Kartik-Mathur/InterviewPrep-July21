// BinarySearch.cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr[] = {1, 3, 5, 7, 7, 7, 7, 8, 9};
	int n = sizeof(arr) / sizeof(int);

	// sort(arr, arr + n);
	bool ans = binary_search(arr, arr + n, 10); // O(logN)

	if (ans) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not Found" << endl;
	}

	// lower_bound and upper_bound: address return
	// lower_bound : 1 3 5 7 7 7 7 8 9, >=key, key : 7
	auto it = lower_bound(arr, arr + n, 7); // O(logN)
	cout << *it << endl;
	int indx = it - arr;
	cout << "Index" << indx << endl;

	// upper_bound : 1 3 5 7 7 7 7 8 9, >key, key : 7
	auto it1 = upper_bound(arr, arr + n, 7); // O(logN)
	cout << *it1 << endl;
	indx = it1 - arr;
	cout << "Index" << indx << endl;

	// Find the occurances of key: 7
	cout << "7 Occ : " << it1 - it << endl;
	return 0;
}
















