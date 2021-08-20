// RotatedSortedArray.cpp
#include <iostream>
using namespace std;

int solve(int *a, int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			break;
		}
		else if (a[s] <= a[mid]) {
			if (key >= a[s] and key <= a[mid])
				e = mid - 1;
			else
				s = mid + 1;
		}
		else {
			if (key >= a[mid] and key <= a[e]) {
				s = mid + 1;
			}
			else
				e = mid - 1;
		}
	}
	return ans;
}

int main() {

	int a[] = {8, 10, 11, 1, 2, 4, 5, 6, 7};
	int n = sizeof(a) / sizeof(int);

	cout << solve(a, n, 5) << endl;


	return 0;
}
















