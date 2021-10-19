// Set.cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
	set <pair<int, char> > s;

	// Insertion
	s.insert({5, 'B'});
	s.insert({3, 'C'});
	s.insert({1, 'A'});
	s.insert({4, 'D'});
	s.insert({7, 'E'});

	// Printing set, the result of output is sorted in set
	// while (!s.empty()) {
	// 	auto address = s.begin(); // Address of the first element
	// 	auto p = *address;

	// 	cout << p.first << "," << p.second << endl;
	// 	s.erase(address); // Address leta hai and delete kar deta hai us element ko
	// }

	// Updation inside a set
	// To update inside the set, you need to delete the value and insert it again
	// {1,'A'}, we will find it first inside the set, agar exist karti hai toh I can delete
	// it.
	auto x = s.find({1, 'A'});// It gives the address of the element
	if (x != s.end()) {
		cout << "Pair is present" << endl;
		s.erase(x);
		s.insert({8, 'A'});
	}
	else {
		cout << "Not Present" << endl;
		s.insert({8, 'A'}); // If hai hi nhi toh seedhe insert krdo
	}

	while (!s.empty()) {
		auto address = s.begin(); // Address of the first element
		auto p = *address;

		cout << p.first << "," << p.second << endl;
		s.erase(address); // Address leta hai and delete kar deta hai us element ko
	}
	// set<int> s; // NlogN

	// s.insert(1);
	// s.insert(2);
	// s.insert(3);
	// s.insert(4);

	// while (!s.empty()) {
	// 	auto address = s.begin(); // Address of the first element
	// 	int element = *address;

	// 	cout<<element<<endl;
	// 	s.erase(address); // Address leta hai and delete kar deta hai us element ko
	// }


	return 0;
}
















