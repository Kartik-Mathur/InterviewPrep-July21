// Find.cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// cplusplusreference.com
	int arr[] = {1, 4, 3, 5, 7, 8, 9}; // Max Size: 10^6
	int n = sizeof(arr) / sizeof(int);
	// Syntax: find(starting address,ending address,key)
	auto it = find(arr, arr + n, 3);
	int indx = it - arr;
	if (indx == n) {
		cout << "Element Not Found";
	}
	else {
		cout << "Element Found at " << indx;
	}
	// cout << *it << endl;
	cout << endl;
	return 0;
}
















