// Subsets - 2.cpp
// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
	vector<vector<int>> ans;

	void solve(vector<int>& nums, vector<int> &x, int s) {
		ans.push_back(x);

		// recursive case
		for (int i = s ; i < nums.size() ; i++) {
			if (i != s and nums[i] == nums[i - 1]) continue;

			x.push_back(nums[i]);
			solve(nums, x, i + 1);
			x.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int>x;
		sort(nums.begin(), nums.end());
		solve(nums, x, 0);
		return ans;
	}
};