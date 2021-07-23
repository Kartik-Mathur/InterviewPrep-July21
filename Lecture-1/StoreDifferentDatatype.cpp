// StoreDifferentDatatype.cpp
#include <iostream>
#include <variant>
using namespace std;
typedef variant<string, int> my;
// overloading cout operator
// cout is present inside ostream
ostream& operator<<(ostream& os, variant<string, int> a) {
	auto value = get_if<int>(&a);
	if (value) {
		cout << get<int>(a);
	}
	else {
		cout << get<string>(a);
	}
	return os;
}

int main() {

	my a;
	a = 2;
	cout << a << endl;

	a = "Hello World";
	// cout << get<int>(a) << endl;
	// a = "Hello World";
	// cout << get<string>(a) << endl;
	cout << a << endl;
	// auto value = get_if<int>(&a);
	// if (value) {
	// 	cout << get<int>(a) << endl;
	// }
	// else {
	// 	cout << get<string>(a) << endl;
	// }
	// auto value = get_if<int>(&a);
	// if (value) {
	// 	cout << *value + 10 << endl;
	// }
	// else {
	// 	cout << "Value is not an integer";
	// }

	return 0;
}
















