// ExchangeCoins.cpp
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define inf 1e10

// int ExchangeCoins(int amt, int *coins, int n) {
// 	if (amt == 0) {
// 		return 0;
// 	}

// 	int ans = INT_MAX;
// 	for (int i = 0 ; i < n ; i++) {
// 		if (amt - coins[i] >= 0) {
// 			int ca = ExchangeCoins(amt - coins[i], coins, n);
// 			if (ca != INT_MAX) {
// 				ans = min(ans, ca + 1);
// 			}
// 		}
// 	}
// 	return ans;
// }

ll ExchangeCoins(ll amt, ll *coins, ll n, ll *dp) {
	if (amt == 0) {
		return dp[amt] = 0;
	}

	if (dp[amt] != -1) {
		return dp[amt];
	}

	ll ans = inf;
	for (ll i = 0 ; i < n ; i++) {
		if (amt - coins[i] >= 0) {
			ll ca = ExchangeCoins(amt - coins[i], coins, n, dp);
			// if (ca != INT_MAX) {
			ans = min(ans, ca + 1);
			// }
		}
	}
	return dp[amt] = ans;
}

ll bottomUp(ll amt, ll *coins, ll n) {
	vector<ll> dp(amt + 1, INT_MAX);
	dp[0] = 0;

	for (ll i = 1 ; i <= amt ; i++) {
		for (ll j = 0 ; j < n ; j++) {
			if (i - coins[j] >= 0)
				dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
		}
	}
	return dp[amt];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll dp[10000];
	memset(dp, -1, sizeof dp);
	ll coins[] = {1, 7, 10};
	ll amt = 1455;
	cout << ExchangeCoins(amt, coins, 3, dp) << endl;
	cout << bottomUp(amt, coins, 3) << endl;
	// cout << INT_MAX << endl;
	// cout << INT_MAX + 1 << endl;
	// cout << INT_MIN << endl;

	// cout << INT_MIN - 1 << endl;


	return 0;
}
















