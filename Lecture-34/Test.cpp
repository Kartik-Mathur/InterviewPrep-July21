#include <iostream>
#include <vector>
using namespace std;

class dsu {
	vector<int> parent;
	vector<int> size;
public:
	dsu(int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0 ; i < n ; i++)
			parent[i] = i, size[i] = 1;
	}

	int get(int v) {
		if (v == parent[v]) return v;

		return parent[v] = get(parent[v]);
	}

	void union_set(int a, int b) {
		int spa = get(a);
		int spb = get(b);

		if (spa != spb) {
			if (size[spa] < size[spb]) {
				swap(spa, spb);
			}
			size[spa] += size[spb];
			parent[spb] = spa;

		}
	}
};

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int mst(vector<vector<int> > adj, int edges) {
	dsu g(edges);

	int ans = 0;
	for (int i = 0 ; i < edges; i++) {
		int u = adj[i][0];
		int v = adj[i][1];
		int w = adj[i][2];

		if (g.get(u) != g.get(v)) {
			ans += w;
			g.union_set(u, v);
		}
	}
	return ans;
}

void solve() {
	int edge;
	cin >> edge;

	vector<vector<int> > adj(edge);
	int u, v, w;
	for (int i = 0; i < edge; ++i)
	{
		cin >> u >> v >> w;
		adj[i] = {u - 1, v - 1, w};
	}

	sort(adj.begin(), adj.end(), compare);


	cout << mst(adj, edge);
}

int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}
















