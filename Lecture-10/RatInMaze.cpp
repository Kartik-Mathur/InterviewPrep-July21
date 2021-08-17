// RatInMaze.cpp
#include <iostream>
using namespace std;
int solution[100][100] = {0};
int n, m;

bool RatInMaze(char maze[][100], int i, int j) {
	// base case
	if (i == n - 1 and j == m - 1) {
		solution[i][j] = 1;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0; j < m; ++j)
			{
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}

	// recursive case
	solution[i][j] = 1;
	// Pehle right se check krke aa
	if (j + 1 < m and maze[i][j + 1] != 'X') {
		bool kyaRightSeBaatbani = RatInMaze(maze, i, j + 1);
		if (kyaRightSeBaatbani == true) {
			return true;
		}
	}

	// phir neeche se check krke aa
	if (i + 1 < n and maze[i + 1][j] != 'X') {
		bool kyaNeecheSeBaatbani = RatInMaze(maze, i + 1, j);
		if (kyaNeecheSeBaatbani) {
			return true;
		}
	}

	solution[i][j] = 0;
	return false;

}

int main() {

	char maze[][100] = {
		"0000",
		"00XX",
		"0000",
		"XX00"
	};
	n = m = 4;
	RatInMaze(maze, 0, 0);



	return 0;
}
















