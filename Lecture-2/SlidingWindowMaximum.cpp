// SlidingWindowMaximum.cpp
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<pair<int, int> > q;
		int n = nums.size();
		vector<int> ans;

		for (int i = 0 ; i < n ; i++) {
			// if there are elements smaller than current elements
			// inside deque, remove all of them
			while (!q.empty() and q.back().first < nums[i]) {
				q.pop_back();
			}

			// if there are elements that are outside the current window
			// remove them
			while (!q.empty() and q.front().second <= i - k) {
				q.pop_front();
			}

			q.push_back({nums[i], i});
			if (i - k + 1 >= 0) {
				ans.push_back(q.front().first);
			}
		}

		return ans;
	}
};