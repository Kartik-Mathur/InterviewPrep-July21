// NQueen.cpp
#include <iostream>
using namespace std;

bool kyaSafeHai(int board[][100], int i, int j, int n) {
	for (int k = 0 ; k < i ; k++)
		if (board[k][j])
			return false;

	int x = i , y = j;
	// Checking upper right dia
	while (i >= 0 and j < n) {
		if (board[i][j]) return false;
		i--; j++;
	}
	// Checking upper left dia
	while (x >= 0 and y >= 0) {
		if (board[x][y]) return false;
		x--; y--;
	}
	return true;
}

bool NQueen(int board[][100], int i, int n) {
	// base case
	if (i == n) {
		// print the chess board
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				board[i][j] == 1 ? cout << "Q " : cout << "_ ";
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}

	// recursive case
	for (int j = 0 ; j < n ; j++) {
		if (kyaSafeHai(board, i, j, n)) {
			board[i][j] = 1; // Keep the queen on i,j cell
			bool BaakiBaatBani = NQueen(board, i + 1, n);
			if (BaakiBaatBani) return true;
			board[i][j] = 0; // Remove that queen if its not safe
		}
	}
	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int board[100][100] = {0};
	int n;
	cin >> n;

	bool ans = NQueen(board, 0, n);


	return 0;
}
















