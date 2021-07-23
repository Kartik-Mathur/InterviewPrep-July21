// Vector.cpp
#include <iostream>
#include <vector>
using namespace std;
#define pb push_back

int main() {
	// Initialization
	// vector<int> v; // 1.
	vector<int> v(5, 20); // 2.
	// 3rd Way
	vector<int> v1(v.begin(), v.end());

	for (int i = 0 ; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	// 4th Way
	vector<int> a{1, 2, 3, 4};

	// For Each Loop
	for (auto elements : a) {
		cout << elements << " ";
	}
	cout << endl;

	vector<int> b;
	b.reserve(100);
	// b.pb(1);
	// b.pb(2);
	// b.pb(3);
	// b.pb(4);
	// b.pb(5);
	for (int i = 1 ; i <= 5 ; i++) {
		b.pb(i);

		// cout << "Size " << b.size() << endl;
		// cout << "Capacity " << b.capacity() << endl;
	}

	b.insert(b.begin() + 2, 8); // Inserts only one value
	b.insert(b.begin() + 2, 2, 8); // Inserts only one value
	// b.clear();
	for (auto elements : b) {
		cout << elements << " ";
	}
	cout << endl;
	// cout << b.max_size() << endl;
	cout << b.front() << endl;
	cout << b.back() << endl;
	cout << "Capacity " << b.capacity() << endl;

	b.resize(40);
	cout << "Capacity " << b.capacity() << endl;

	return 0;
}
















