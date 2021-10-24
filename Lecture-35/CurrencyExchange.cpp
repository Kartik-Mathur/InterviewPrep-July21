// CurrencyExchange.cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int deno[] = {1, 2, 5, 10, 20};
	int n = sizeof(deno) / sizeof(int);
	int amount = 15;

	// auto coin = upper_bound(deno, deno + n, amount);
	// cout << *(coin - 1) << endl;
	int cnt = 0;
	while (amount > 0 ) {
		int coin = *(upper_bound(deno, deno + n, amount) - 1);
		cout << coin << "-->";
		amount -= coin;
		cnt++;
	}
	cout << endl << "Total Coins Given: " << cnt << endl;

	return 0;
}
















