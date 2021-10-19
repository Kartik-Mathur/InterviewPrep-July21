#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
using namespace std;
#define pb push_back

template<typename T>
class Graph {
public:
	unordered_map < T, list<pair<T, int> > > adj;
	void addEdge(T u, T v, int dist, bool bidir = true) {
		adj[u].pb({v, dist});
		if (bidir) adj[v].pb({u, dist});
	}

	void print() {
		for (auto node : adj) {
			cout << node.first << "-->";
			for (auto c : node.second) cout << "(" << c.first << "," << c.second << ")" << " ";
			cout << endl;
		}
	}

	void dijkstras(T src) {
		unordered_map<T, int> dist;
		// Set the distance of all the nodes equal to inf
		for (auto p : adj) {
			dist[p.first] = INT_MAX;
		}

		dist[src] = 0;
		set<pair<int, T> > s;
		s.insert({0, src});

		while (!s.empty()) {
			auto address = s.begin();
			auto p = *address;
			T parent = p.second;
			int parent_dist = p.first;
			s.erase(address);

			for (auto children : adj[parent]) {
				T child_node = children.first;
				int ed = children.second;
				int crd = dist[child_node];

				if (crd > parent_dist + ed) {
					auto f = s.find({crd, child_node});
					if (f != s.end()) {
						s.erase(f);
					}
					s.insert({parent_dist + ed, child_node});
					dist[child_node] = parent_dist + ed;
				}
			}
		}

		for (auto node : dist) {
			cout << "Distance of " << node.first << " from " << src << " : " << node.second << endl;
		}

	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph<char> g;
	g.addEdge('A', 'B', 1);
	g.addEdge('C', 'B', 2);
	g.addEdge('C', 'D', 3);
	g.addEdge('A', 'C', 4);
	g.addEdge('A', 'D', 8);

	g.print();
	g.dijkstras('A');


	return 0;
}
















