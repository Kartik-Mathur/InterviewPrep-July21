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

template<typename T>
class Graph {
public:
	unordered_map<T, list<T> > adj;
	void addEdge(T u, T v, bool bidir = false) {
		adj[u].pb(v);
		if (bidir) adj[v].pb(u);
	}

	void print() {
		for (auto node : adj) {
			cout << node.first << "-->";
			for (auto c : node.second) cout << c << " ";
			cout << endl;
		}
	}

	void ts_helper(T node, unordered_map<T, bool> &visited, list<T> &ans) {
		visited[node] = true;
		for (auto neighbours : adj[node]) {
			if (!visited[neighbours]) {
				ts_helper(neighbours, visited, ans);
			}
		}
		ans.push_front(node);
	}

	void topologicalSort() {
		list<T> ans;
		unordered_map<T, bool> visited;

		for (auto p : adj) {
			T node = p.first;
			if (!visited[node]) {
				ts_helper(node, visited, ans);
			}
		}

		for (auto data : ans) {
			cout << data << "-->";
		}
		cout << endl;
	}
};

void solve() {
	Graph<string> g;

	g.addEdge("Maths", "Programming Logic", false);
	g.addEdge("English", "Programming Logic", false);
	g.addEdge("Programming Logic", "HTML", false);
	g.addEdge("Programming Logic", "JS", false);
	g.addEdge("Programming Logic", "C++", false);
	g.addEdge("Programming Logic", "Java", false);
	g.addEdge("Maths", "HTML", false);
	g.addEdge("HTML", "CSS" , false);
	g.addEdge("CSS", "JS" , false);
	g.addEdge("JS", "Web Dev" , false);
	g.addEdge("C++", "Web Dev" , false);
	g.addEdge("Java", "Web Dev" , false);

	g.topologicalSort();

}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	solve();

	return 0;
}











