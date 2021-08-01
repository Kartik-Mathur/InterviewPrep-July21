// RecursiveSequence.cpp
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define mod 1000000000

ll k, n;
vector<ll> b, c;


vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B) {
	vector<vector<ll> > C(k, vector<ll>(k));
	for (int i = 0 ; i < k ; i++)
		for (int j = 0 ; j < k ; j++)
			for (int l = 0 ; l < k ; l++)
				C[i][j] = (C[i][j] + (A[i][l] * B[l][j]) % mod) % mod;

	return C;
}

vector<vector<ll> > power(vector<vector<ll> > A, ll p) {
	if (p == 1) {
		return A;
	}

	if (p & 1) {
		return multiply(A, power(A, p - 1));
	}

	vector<vector<ll> > X = power(A, p / 2);
	return multiply(X, X);
}

ll solve() {
	if (n < k) {
		return b[n - 1];
	}

	vector<vector<ll> > T(k, vector<ll>(k));
	vector<ll> F1(b.begin(), b.end());


	for (int i = 0 ; i < k ; i++) {
		for (int j = 0 ; j < k ; j++) {
			if (i < k - 1) {
				if (j == i + 1) {
					T[i][j] = 1;
				}
				else {
					T[i][j] = 0;
				}
			}
			else {
				for (int j = 0 ; j < k ; j++)
					T[i][j] = c[k - 1 - j];
			}
		}
	}

	T = power(T, n - 1);

	ll ans = 0;
	for (ll j = 0 ; j < k ; j++) {
		ans = (ans + (T[0][j] * F1[j]) % mod) % mod;
	}
	return ans;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	while (t--) {
		cin >> k;
		int num;
		for (int i = 0 ; i < k ; i++) {
			cin >> num;
			b.push_back(num);
		}

		for (int i = 0 ; i < k ; i++) {
			cin >> num;
			c.push_back(num);
		}
		cin >> n;

		cout << solve() << endl;

		b.clear();
		c.clear();
	}

	return 0;
}
















