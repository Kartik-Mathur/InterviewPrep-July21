#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[100000];
	cin >> a;

	int len = strlen(a);
	int ans = (1 << (len)) - 2;

	int pos = 0;
	for (int i = len - 1; i >= 0 ; i--) {
		if (a[i] == '7') {
			ans += (1 << pos);
		}
		pos++;
	}

	cout << ans + 1 << endl;

	return 0;
}
















