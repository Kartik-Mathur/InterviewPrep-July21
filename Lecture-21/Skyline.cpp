// Skyline.cpp
class points {
public:
	int x;
	int y;
	bool start;
};
class Solution {
public:
	static bool compare(points a, points b) {
		if (a.x == b.x) {
			if (a.start and b.start) {
				return a.y > b.y;
			}
			else if (a.start) {
				return a.start ? true : false;
			}
			else {
				return a.y < b.y;
			}
		}
		else {
			return a.x < b.x;
		}
	}

	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<int>> ans;
		int n = buildings.size();
		points p[2 * n];
		int indx = 0;
		for (auto b : buildings) {
			// [2,9,10] b[0]: x1, b[1]: x2, b[2]: height
			p[indx].x = b[0];
			p[indx].y = b[2];
			p[indx].start = true;

			p[indx + 1].x = b[1];
			p[indx + 1].y = b[2];
			p[indx + 1].start = false;
			indx += 2;
		}

		sort(p, p + 2 * n, compare);

		for (auto data : p) {
			cout << data.x << " " << data.y << " " << data.start << endl;
		}

		map<int, int> h; // insertion, deletion and updation : log(N)
		int prev_max = 0;
		h[0] = 1;
		for (auto point : p) {

			if (point.start) {
				if (h.count(point.y)) {
					h[point.y]++;
				}
				else {
					h[point.y] = 1;
				}
			}
			else {
				if (h.count(point.y)) {
					h[point.y]--;
				}
				if (h[point.y] == 0) {
					auto it = h.find(point.y);
					if (it != h.end()) {
						h.erase(it);
					}
				}
			}

			int cur_max = h.rbegin()->first;
			if (cur_max != prev_max) {
				ans.push_back({point.x, cur_max});
				prev_max = cur_max;
			}

		}


		return ans;
	}
};











