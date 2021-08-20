// AggressiveCows.cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

bool isPossible(ll *a, ll n, ll total_cows, ll min_dist) {
	int cows_placed = 1;
	int last_cow_pos = a[0];

	for (int j = 1; j < n ; j++) {
		if (a[j] - last_cow_pos >= min_dist) {
			cows_placed++;
			last_cow_pos = a[j];
			if (cows_placed == total_cows) return true;
		}
	}
	return false;
}

ll solve(ll *a, ll n, ll c) {
	sort(a, a + n);
	ll s = 0;
	ll e = a[n - 1];
	ll ans = 0;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (isPossible(a, n, c, mid)) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t, n, c;
	ll a[100005];
	cin >> t;
	while (t--) {

		cin >> n >> c;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		cout << solve(a, n, c) << endl;
	}

	return 0;
}
















