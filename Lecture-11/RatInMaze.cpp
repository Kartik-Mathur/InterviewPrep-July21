#include <iostream>
using namespace std;

bool RatInMaze(char maze[][100], int i, int j, bool visited[][100], int n, int m) {
	// base case
	if (i == n - 1 and j == m - 1) {
		visited[i][j] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (maze[i][j] == 'X') {
					cout << "X ";
				}
				else {
					visited[i][j] == 1 ? cout << "1 " : cout << "_ ";
				}
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}

	// recursive case
	visited[i][j] = 1;
	// Right check krke aa
	if (j + 1 < m and maze[i][j + 1] != 'X' and !visited[i][j + 1]) {
		bool KyaRightSeBaniBaat = RatInMaze(maze, i, j + 1, visited, n, m);
		if (KyaRightSeBaniBaat) return true;
	}

	// Check Downwards
	if (i + 1 < n and maze[i + 1][j] != 'X' and !visited[i + 1][j]) {
		bool KyaNeecheSeBaniBaat = RatInMaze(maze, i + 1, j, visited, n, m);
		if (KyaNeecheSeBaniBaat) return true;
	}

	// Left check krke aa
	if (j - 1 >= 0 and maze[i][j - 1] != 'X' and !visited[i][j - 1]) {
		bool KyaLeftSeBaniBaat = RatInMaze(maze, i, j - 1, visited, n, m);
		if (KyaLeftSeBaniBaat) return true;
	}

	// Check upwards
	if (i - 1 >= 0 and maze[i - 1][j] != 'X' and !visited[i - 1][j]) {
		bool KyaUparSeBaatBani = RatInMaze(maze, i - 1, j, visited, n, m);
		if (KyaUparSeBaatBani) return true;
	}
	visited[i][j] = 0;

	return false;
}

int main() {

	char maze[][100] = {
		"0000000",
		"0XXXXXX",
		"0X000X0",
		"0X0X0X0",
		"000X000"
	};

	bool visited[100][100] = {0};
	RatInMaze(maze, 0, 0, visited, 5, 7);


	return 0;
}
















