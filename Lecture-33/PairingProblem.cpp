// PairingProblem.cpp
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

	// int get(int v) {
	// 	if (v == parent[v]) return v;

	// 	return get(parent[v]); // Path compression: O(N)
	// }
	int get(int v) {
		if (v == parent[v]) return v;

		return parent[v] = get(parent[v]); // Path compression: O(logN)
	}

	void union_set(int a, int b) {
		int spa = get(a);
		int spb = get(b);

		if (spa != spb) {
			if (size[spa] < size[spb]) { // iska mtlb yeh hai ki size of
				// superparent of A(spa) is less than superparent of b(spb)
				swap(spa, spb);
			}
			size[spa] += size[spb];
			size[spb] = 0;
			parent[spb] = spa;

		}
	}

	int solve(int n) {
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int sp = get(i);
			ans += n - size[sp];
		}
		return ans / 2;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, a, b;
	cin >> n >> m;
	dsu g(n);

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		g.union_set(a, b); // o(1)*m
	}

	cout << g.solve(n) << endl;

	return 0;
}
















