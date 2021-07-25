// Multimap.cpp
#include <iostream>
#include <map>
using namespace std;
#define mp make_pair
typedef multimap<char, string>:: iterator It;

int main() {

	multimap<char, string> m;
	m.insert(mp('k', "kartik"));
	m.insert(mp('k', "keshav"));
	m.insert(mp('k', "karan"));
	m.insert(mp('a', "ayush"));
	m.insert(mp('a', "arsh"));
	m.insert(mp('r', "ritvik"));

	It it;
	it = m.begin();

	m.erase(it);

	It lb = m.lower_bound('k'); // >=key

	// It lb = m.lower_bound('z'); // >=key
	// if (lb == m.end()) {
	// 	cout << "Not Found" << endl;
	// }
	// return 0;

	It up = m.upper_bound('k'); // >key

	// cout << m.count('z') << endl;
	// cout << (*lb).first << endl;
	// cout << (*lb).second << endl;

	// cout << (*up).first << endl;
	// cout << (*up).second << endl;

	// Print all the values where key is 'k'
	// for (auto it = lb; it != up ; it++) {
	// 	cout << (*it).second << endl;
	// }

	// for (auto it = lb ; it != m.end() ; it++) {
	// 	// cout << (*it).second << endl;
	// 	cout << it->second << endl;
	// }

	// To find the lower_bound and upper_bound in an easier way, we can use
	// equal_range
	pair<It, It> p = m.equal_range('k');

	for (auto it = p.first ; it != p.second ; it++) {
		// cout << (*it).second << endl;
		cout << it->second << endl;
	}

	// for (auto node : m) {
	// 	cout << node.first << "-> " << node.second << endl;
	// }

	return 0;
}
















