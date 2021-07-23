// Map.cpp
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	// Key: Unique
	// map<string, int> m;
	int a = 10;
	// auto x = 10;
	// cout << sizeof(x) << endl;

	unordered_map<string, int> m;

	m.insert({"Mango", 100});
	pair<string, int> p("Pineapple", 400);
	m.insert(p);

	p = make_pair("Kiwi", 200);
	m.insert(p);

	m.insert(make_pair("Guava", 50));

	for (auto node : m) {
		cout << node.first << "->" << node.second << endl;
	}

	cout << m.count("MangoShake") << endl;


	return 0;
}
















