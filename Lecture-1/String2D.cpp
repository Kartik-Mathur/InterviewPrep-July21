// String2D
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(string a, string b) {
	if (a.length() == b.length()) {
		return a > b;
	}
	return a.length() > b.length();
}

int main() {

	vector<string> a = {
		"Hello",
		"Mango",
		"PineApple",
		"Guava"
	};

	sort(a.begin(), a.end(), comparator);

	for (int i = 0 ; i < 4 ; i++) {
		cout << a[i] << endl;
	}
	return 0;
}

















