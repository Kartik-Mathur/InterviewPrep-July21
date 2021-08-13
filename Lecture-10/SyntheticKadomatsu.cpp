// SyntheticKadomatsu.cpp
// https://atcoder.jp/contests/abc119/tasks/abc119_c
#include <iostream>
using namespace std;
#define ll long long

ll n, A, B, C;
ll b[10];

ll solve(ll x, ll y, ll z, ll i) {
	// base case
	if (i == n) {
		if (x == 0 || y == 0 || z == 0) {
			return 1e10;
		}
		return abs(x - A) + abs(y - B) + abs(z - C);
	}

	// recursive case
	ll op1 = solve(x, y, z, i + 1) + 0;
	ll op2 = solve(x + b[i], y, z, i + 1) + (x == 0 ? 0 : 10);
	ll op3 = solve(x, y + b[i], z, i + 1) + (y == 0 ? 0 : 10);
	ll op4 = solve(x, y, z + b[i], i + 1) + (z == 0 ? 0 : 10);

	return min(op1, min(op2, min(op3, op4)));
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> A >> B >> C;
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	cout << solve(0, 0, 0, 0) << endl;
	return 0;
}
















