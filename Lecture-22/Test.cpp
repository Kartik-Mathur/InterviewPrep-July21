#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// TopDown
int fibo(int n, int *dp) {
	if (n <= 1) return dp[n] = n;

	if (dp[n] != -1) {
		return dp[n];
	}

	return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

// Bottom-Up: iterative
int bottomUp(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2 ; i <= n ; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 0; i <= n; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	return dp[n];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int dp[1000];
	memset(dp, -1, sizeof dp);

	int n; cin >> n;
	cout << fibo(n, dp) << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	cout << bottomUp(n) << endl;

	long long int y = 10;
	long long int x = 20;

	cout << max(x, y) << endl;

	return 0;
}
















