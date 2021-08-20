// Permutations.cpp
#include <iostream>
#include <set>
using namespace std;
string x;
set<string> s;

void Permutations(string inp, string out) {
	// base case
	if (inp.size() == 0) {
		if (out > x) {
			// cout << out << endl;
			s.insert(out);
		}
		return;
	}

	// recursive case
	for (int i = 0 ; i < inp.size() ; i++) {
		string smallerSortedString = inp.substr(0, i) + inp.substr(i + 1);
		Permutations(smallerSortedString, out + inp[i]);
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string inp, out;
	cin >> inp;
	x = inp;
	sort(inp.begin(), inp.end());

	Permutations(inp, out);
	for (auto ele : s) {
		cout << ele << endl;
	}


	return 0;
}
















