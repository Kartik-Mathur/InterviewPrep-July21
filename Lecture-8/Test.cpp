#include <iostream>
using namespace std;
#define ll long long
ll p, n;

ll Fastpower(ll a, ll b, ll m) {

    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans % m * a % m) % m;
        a *= a;
        a %= m;
        b = b >> 1;
    }
    return ans;
}

ll solve() {

    ll ans = - 1;
    for (ll i = n + 1; i < p; i++) {
        ans *= Fastpower(i, p - 2, p) % p;
        ans %= p;
    }

    ans = (ans + p) % p;
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
        cin >> n >> p;
        if (n >= p)
            cout << 0 << endl;
        else
            cout << solve() << endl;
    }

    return 0;
}
















