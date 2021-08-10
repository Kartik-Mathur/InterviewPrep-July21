#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &v) {
	for (int i = 0 ; i < v.size() ; i++) {
		v[i]++;
	}
}

int main() {
	vector<int> v(5, 0);
	solve(v);
	for (auto c : v) {
		cout << c << " ";
	}
	cout << endl;
	// string str = "aab";
	// int s = 1, e = 2;

	// for (int end = s ; end < str.length(); end++) {
	// 	cout << str.substr(s, end - s + 1) << endl;
	// }


	return 0;
}
















