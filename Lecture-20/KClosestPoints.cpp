// KClosestPoints.cpp
#define mydata pair<double,int>
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue<mydata> q;

		for (int i = 0 ; i < points.size() ; i++) {
			double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
			if (q.empty()) q.push({dist, i});
			else {
				if (q.size() < k) {
					q.push({dist, i});
				}
				else {
					if (q.top().first > dist) {
						q.pop();
						q.push({dist, i});
					}
				}
			}
		}

		vector<vector<int> > ans;
		while (!q.empty()) {
			int indx = q.top().second;
			ans.push_back({points[indx][0], points[indx][1]});
			q.pop();
		}

		return ans;
	}
};















