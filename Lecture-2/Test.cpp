#include <iostream>
using namespace std;

int main() {

	int x[] = {0, 0, -1, 1};
	int y[] = {1, -1, 0, 0};

	int i = 2, j = 2;

	for (int k = 0 ; k < 4 ; k++) {
		int ni = i + x[k];
		int nj = j + y[k];

		cout << ni << ", " << nj << endl;
	}

	return 0;
}
















