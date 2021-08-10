// CombinationSum - 3.cpp
// https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
	vector<vector<int>> ans;

	void solve(vector<int> &x, int k, int n, int start, int sum = 0) {
		// base case
		if (sum == n and k == 0) {
			ans.push_back(x);
			return;
		}
		if (sum > n || k <= 0) return;

		// recursive case
		for (int no = start ; no <= 9 ; no++) {
			if (no + sum <= n) {
				x.push_back(no);
				solve(x, k - 1, n, no + 1, sum + no);
				x.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> x;
		solve(x, k, n, 1);
		return ans;
	}
};