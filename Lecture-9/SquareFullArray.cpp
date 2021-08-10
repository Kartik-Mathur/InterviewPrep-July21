class Solution {
public:
	int ans = 0;

	void solve(vector<int>& nums, int start) {
		// base case
		if (start > 1) {
			int sum = nums[start - 1] + nums[start - 2];
			int y = sqrt(sum);
			if (y * y - sum != 0) return;
		}
		if (start == nums.size()) {
			ans ++;

			return;
		}

		// recursive case
		unordered_map<int, bool> m;
		for (int end = start ; end < nums.size(); end++) {
			if (end == start || nums[start] != nums[end]) {
				if (m.count(nums[end]) == 0) {
					swap(nums[start], nums[end]);
					solve(nums, start + 1);
					swap(nums[start], nums[end]);
				}
				m[nums[end]] = 1;
			}
		}
	}

	int numSquarefulPerms(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		solve(nums, 0);
		return ans;
	}
};