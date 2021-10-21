// KCompleteWord.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define new(a,n) ll*a = new ll[n]
#define new1(a,n,m) ll**a = new ll*[n]; for(ll i = 0 ; i < n ; i++) a[i] = new ll[m];
#define mp make_pair
#define pb push_back
#define fi first
#define pii pair<ll,ll>
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define init(a,n,v) for(int i = 0 ; i <n ; i++) a[i]=v;
#define init2(a,n,m,v) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){a[i][j]=v;}}
#define AS 200001
#define mod 1000000007
class dsu {
	vector<ll> parent;
	vector<ll> size;
public:
	dsu(ll n) {
		parent.resize(n);
		size.resize(n);
		for (ll i = 0 ; i < n ; i++)
			parent[i] = i, size[i] = 1;
	}

	ll get(ll v) {
		if (v == parent[v]) return v;

		return parent[v] = get(parent[v]);
	}

	void union_set(ll a, ll b) {
		ll spa = get(a);
		ll spb = get(b);

		if (spa != spb) {
			if (size[spa] < size[spb]) {
				swap(spa, spb);
			}
			size[spa] += size[spb];
			parent[spb] = spa;

		}
	}
};

ll solve() {
	string s;
	ll n, k;
	cin >> n >> k >> s;
	vector<vector<ll> > mapping(n + 1, vector<ll> (26, 0));
	dsu g(n);

	for (int i = 0; i < n; ++i)
	{
		g.union_set(i, n - i - 1);// For Pallindrome
	}

	for (ll i = 0; i < n; ++i)
	{
		ll u = i;
		ll v = i + k;
		if (v < n) {
			g.union_set(u, v);
		}
	}


	for (int i = 0; i < n; ++i)
	{
		mapping[g.get(i)][s[i] - 'a']++;
	}

	ll ans = 0;
	for (ll i = 0; i < n; ++i)
	{
		ll total = 0;
		ll mx = INT_MIN;
		for (ll j = 0; j < 26; ++j)
		{
			total += mapping[i][j];
			mx = max(mapping[i][j], mx);
		}
		ans += total - mx;
	}

	return ans;
}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t; cin >> t;
	while (t--)
		cout << solve() << endl;

	return 0;
}











