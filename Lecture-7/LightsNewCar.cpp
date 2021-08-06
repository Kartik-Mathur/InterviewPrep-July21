// LightsNewCar.cpp
#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007

ll stringToInt(string &a, ll m) {
	ll ans = 0;
	for (auto ch : a) {
		ans = ans * 10 + (ch - '0');
		ans %= m;
	}
	return ans;
}

ll fastPower(ll a, ll n) {
	if (!n) return 1;

	ll temp = fastPower(a, n / 2);
	ll ans = (temp % mod) * (temp % mod);
	ans %= mod;
	if (n & 1) {
		ans = (ans % mod) * (a % mod);
		ans %= mod;
	}
	return ans;
}

void solve(string &a, string &b) {

	// Find a%mod
	ll x = stringToInt(a, mod);

	// Find b%(mod-1)
	ll y = stringToInt(b, mod - 1);

	cout << fastPower(x, y) << endl;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// cout << "Hello";
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		solve(a, b);
	}

	return 0;
}
















