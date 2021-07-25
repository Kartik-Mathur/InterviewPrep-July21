// RottingOranges.cpp
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int fresh_oranges = 0;

		queue<pair<int, int> > q;

		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < m ; j++) {
				if (grid[i][j] == 1) fresh_oranges++;
				else if (grid[i][j] == 2) {
					q.push({i, j});
				}
			}
		}

		int x[] = {0 , 0 , 1, -1};
		int y[] = {1, -1 , 0 , 0};

		int time = 0;
		while (!q.empty()) {
			int s = q.size();
			while (s--) {
				auto node = q.front();
				q.pop();
				int i = node.first;
				int j = node.second;

				for (int k = 0 ; k < 4 ; k++) {
					int ni = i + x[k];
					int nj = j + y[k];

					if (min(ni, nj) >= 0 and ni < n and nj < m and grid[ni][nj] == 1) {
						grid[ni][nj] = 2;
						q.push({ni, nj});
						fresh_oranges--;
					}
				}
			}
			if (!q.empty()) {
				time++;
			}
		}

		if (fresh_oranges == 0) return time;
		else return -1;
	}
};