// List.cpp
#include <iostream>
#include <list>
using namespace std;

bool comparator(int a, int b) {
	return a < b;
}

int main() {

	// list <int> l;
	list <int> l{1, 2, 2, 2, 3, 4, 5, 0, -1};


	l.sort();
	l.remove(2);
	// l.reverse();

	auto it = l.begin();
	it++;
	it++;
	l.insert(it, 5);

	for (auto it = l.begin() ; it != l.end() ; it++) {
		cout << *it << endl;
	}

	for (auto ele : l) {
		cout << ele << " ";
	}

	return 0;
}
















