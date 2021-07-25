// Set.cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(4);
	s.insert(4);
	s.insert(4);
	// set doesnot take duplicate values
	// Erase in set
	// Can be done via value or via iterator
	auto it = s.begin();
	s.erase(it);
	// s.erase(1);

	auto ans = s.find(3);
	if (ans != s.end()) {
		cout << "Found " << *ans << endl;
	}
	else {
		cout << "Not Found " << endl;
	}

	auto lb = s.lower_bound(4);
	if (lb != s.end()) {
		cout << "Found " << *lb << endl;
	}
	else {
		cout << "Not Found " << endl;
	}

	// set<int>::iterator
	for (auto it = s.begin() ; it != s.end() ; it++) {
		cout << *it << endl;
	}

	return 0;
}
















