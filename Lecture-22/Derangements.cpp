// Derangements.cpp
#include <iostream>
using namespace std;

int Derangements(int n) {
	if (n == 0) {
		return 1; // Na koi ghar, na koi card: 1
	}
	if (n == 1) {
		return 0;
	}

	return (n - 1) * (Derangements(n - 1) + Derangements(n - 2));
}

int bottomup(int n) {
	int dp[1000];
	dp[0] = 1;
	dp[1] = 0;

	for (int i = 2 ; i <= n ; i++) {
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
	}
	return dp[n];
}

int print(int *a, int i, int n) {
	// 0,1,2,3,4: i = 0, n: 5
	if (i == n) {
		// for (int j = 0 ; j < n ; j++) {
		// 	cout << a[j] << " ";
		// }
		// cout << endl;
		return 1;
	}

	int ans = 0;

	for (int j = i; j < n ; j++) {
		// 4 3 2 1
		if (a[i] != j) { // 0 1 2 3 4, for sorted unique numbers
			swap(a[i], a[j]); // 4 1 2 3 0
			ans += print(a, i + 1, n);
			swap(a[i], a[j]); // Backtracking 0 1 2 3 4
		}
	}
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 4;
	cout << Derangements(n) << endl;
	int a[100];

	// 1 2 2 2 2 3, if a number occurs more than n/2: not possible
	// 1 2 2 3 1 4
	// 1 1 2 2 3 4, max_freq: 2(1 and 2 number ki freq is 2)
	// 2 2 3 4 1 1

	for (int i = 0 ; i < n ; i++) {
		a[i] = i;
	}
	cout << print(a, 0, n) << endl;
	cout << bottomup(n) << endl;

	return 0;
}
















