#include <iostream>
using namespace std;
#define F(a,n) for(int i = 0 ; i < n ; i++){cin >> a[i];}
#define ll long long int
ll n, l, r, x;
ll a[20];

void solve() {
	cin >> n >> l >> r >> x;
	F(a, n);

	ll ans = 0;
	for (int k = 0 ; k < (1 << n) ; k++) {
		ll mi = INT_MAX;
		ll mx = INT_MIN;
		ll i = k;
		int pos = 0;
		ll sum = 0;
		if (__builtin_popcount(i) > 1) {
			while (i) {
				int LSB = (i & 1);
				if (LSB and mi == INT_MAX and mx == INT_MIN) {
					sum += a[pos];
					mi = mx = a[pos];
				}
				else if (LSB) {
					sum += a[pos];
					mi = min(mi, a[pos]);
					mx = max(mx, a[pos]);
				}
				pos++;
				i = i >> 1;
			}
		}

		if (sum >= l and sum <= r and (mx - mi) >= x) {
			ans++;
		}
	}
	cout << ans << endl;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}
















