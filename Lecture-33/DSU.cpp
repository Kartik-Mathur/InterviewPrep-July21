// DSU.cpp
#include <iostream>
using namespace std;

class dsu {
	vector<int> parent;
public:
	dsu(int n) {
		parent.resize(n);
		for (int i = 0 ; i < n ; i++)
			parent[i] = i;
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

		if (spa != spb)
			parent[spa] = spb;
	}
};

int main() {


	return 0;
}
















