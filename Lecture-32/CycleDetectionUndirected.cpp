// CycleDetectionUndirected.cpp
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

	bool cycle_undirectedBFS(T src) {
		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;
		queue<T> q;

		q.push(src);
		parent[src] = src;
		visited[src] = true;

		while (!q.empty()) {
			T node = q.front();
			q.pop();


			for (auto neighbour : adj[node]) {
				if (visited[neighbour] and parent[node] != neighbour) {
					// if visited hai aur neighbour current node ka parent nhi h
					// Toh cycle hai
					return true;
				}
				else if (!visited[neighbour]) {
					visited[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}

		return false;
	}

	bool cycleD_DFS_helper(T node, unordered_map<T, bool> &visited, unordered_map<T, bool> &inStack) {
		visited[node] = true;
		inStack[node] = true;

		// Now iterate over the neighbours of the current node
		// and if the neighbour is present in the stack that means cycle is there
		for (auto neighbour : adj[node]) {
			if (!visited[neighbour] and cycleD_DFS_helper(neighbour, visited, inStack) ||
			        inStack[neighbour]) {
				// inStack[neighbour]: Agar neighbour ancestor hai, toh cycle is present
				return true;
			}
		}

		inStack[node] = false; // Backtracking
		return false;
	}

	bool cycleDetection_DirectedDFS() {

		unordered_map<T, bool> visited;
		unordered_map<T, bool> inStack; // Will only store the ancestors of current
		// node

		for (auto p : adj) {
			T node = p.first;
			if (!visited[node]) {
				bool kyaCycleHai = cycleD_DFS_helper(node, visited, inStack);
				if (kyaCycleHai) return true;
			}
		}
		return false;
	}

	bool ud_cycle_dfs_helper(T node, unordered_map<T, bool> &visited, unordered_map<T, bool> &parent) {
		visited[node] = true;

		for (auto neighbour : adj[node]) {
			if (!visited[neighbour]) {
				parent[neighbour] = node;
				bool kyaCycleHai = ud_cycle_dfs_helper(neighbour, visited, parent);
				if (kyaCycleHai) return true;
			}
			else if (neighbour != parent[node]) {
				// Jis neighbour par gaye, vo visited hai aur vo current node ka parent nhi h
				// This means cycle hai
				return true;
			}
		}
		return false;
	}

	bool ud_cycle_dfs() {
		unordered_map<T, bool> visited;
		unordered_map<T, bool> parent;

		for (auto p : adj) {
			T node = p.first;
			if (!visited[node]) {
				bool kyaCycleHai = ud_cycle_dfs_helper(node, visited, inStack);
				if (kyaCycleHai) return true;
			}
		}
		return false;
	}


};

void solve() {
	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(3, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);

	cout << g.cycle_undirectedBFS(0) << endl;

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











