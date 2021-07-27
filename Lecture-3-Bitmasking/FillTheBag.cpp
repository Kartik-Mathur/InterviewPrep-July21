// FillTheBag.cpp
#include <bits/stdc++.h>
using namespace std;
#define F(a,n) for(int i = 0 ; i < n ; i++){cin >> a[i];}
#define ll long long int

ll t, n, m;
ll a[100005];

void solve() {
	cin >> n >> m;
	F(a, m);

	ll p[64] = {0};
	ll total_mithai = 0;
	for (int i = 0 ; i < m ; i++) {
		p[int(log2(a[i]))]++;
		total_mithai += a[i];
	}

	if (n > total_mithai) {
		cout << -1 << endl;
		return;
	}

	ll i = 0, ans = 0;
	while (i < 61) {
		if (((n >> i) & 1)) {
			if (p[i])p[i]--;
			else {
				while (i < 61 and !p[i]) {
					ans++;
					p[i]++;
					i++;
				}
				p[i]--;
				continue;
			}
		}
		p[i + 1] += p[i] / 2;
		i++;
	}
	cout << ans << endl;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}
















