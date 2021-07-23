// Strings.cpp
#include <iostream>
#include <string>
using namespace std;
#define pb push_back

int main() {

	string s;

	// Initialization
	string s1 = "Zello";
	string s2("Hello");
	char a[] = "Hello World";
	string s3(a);

	// cout << s << endl;
	// cout << s1 << endl;
	// cout << s2 << endl;
	// cout << s3 << endl;

	// s3.pb('!');
	// cout << s3 << endl;
	// s3.pop_back();
	// cout << s3 << endl;

	if (s1.compare(s2) == 0) { // 0: Equals, >0 or <0
		cout << s1 << " is equals to " << s2 << endl;
	}
	cout << s1.compare(s2) << endl;

	if (s1 > s2) { // Operator Overloading
		cout << "Yes" << endl;
	}

	string x = "Hello Welcome to Coding Blocks";
	string word = "Coding";
	int indx = x.find("Coding");
	cout << indx << endl;

	string y = x.substr(6, 7);
	cout << y << endl;
	// x.clear();
	x.erase(indx, word.length() + 1);
	for (auto ch : x) {
		cout << ch;
	}
	cout << endl;
	for (auto it = x.begin() ; it != x.end() ; it++) {
		cout << *it << " ";
	}
	cout << endl;
	for (int i = 0 ; i < x.length(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;

	return 0;
}
















