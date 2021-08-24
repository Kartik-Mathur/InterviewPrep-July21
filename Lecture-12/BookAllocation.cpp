// BookAllocation.cpp
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define ll long long

bool isPossible(ll *books, ll n, ll total_students, ll curr_minimum) {
	ll students_used = 1;
	ll pages_allocated = 0;

	for (ll i = 0 ; i < n ; i++) {
		if (pages_allocated + books[i] <= curr_minimum) {
			pages_allocated += books[i];
		}
		else {
			students_used++;
			pages_allocated = books[i];
			if (students_used > total_students) return false;
		}
	}
	return true;
}


ll solve(ll *a, ll n, ll total_students) {
	ll s = 0, e = INT_MAX;
	ll ans = INT_MAX;

	while (s <= e) {
		ll mid = (s + e) / 2;
		if (isPossible(a, n, total_students, mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ll t, n, total_students;
	ll a[1005];
	cin >> t;
	while (t--) {
		cin >> n >> total_students;
		ll sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			// sum += a[i];
		}
		cout << solve(a, n, total_students) << endl;
	}

	return 0;
}
















