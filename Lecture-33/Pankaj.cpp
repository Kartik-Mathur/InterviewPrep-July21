// Pankaj.cpp
// https://hack.codingblocks.com/app/contests/2487/627/problem
#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<< " ";}cout << endl;
#define NF(v,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin >> v[i][j];}}
#define mod 1000000007
ll n, m;

class dsu {
public:
	vector<int>parent;
	vector<int> size;
	dsu(int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n ; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int get(int v) {
		if (parent[v] == v) return v;
		return parent[v] = get(parent[v]);
	}

	void union_set(int a , int b) {
		int spa = get(a);
		int spb = get(b);
		if (size[spa] < size[spb]) {
			swap(spa, spb);
		}
		size[spa] += size[spb];
		size[spb] = 0;
		parent[spb] = spa;
	}
};

void solve() {
	cin >> n >> m;
	dsu s1 = dsu(n);
	ll a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		s1.union_set(a, b);
	}

	int l = n;
	ll ans = 0 ;
	for (int i = 0 ; i < l; i++) {

		int par = s1.get(i);
		ans += (n - s1.size[par]);
	}
	cout << ans / 2 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// ll t;
	// cin>>t;
	// while(t--){
	solve();
	// }
	return 0;
}