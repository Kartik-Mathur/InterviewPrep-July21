// SplitArray.cpp
class Solution {
public:
	bool isPossible(vector<int>& weights, int m, int total_weight) {
		int d = 1, curr_weight = 0;
		for (auto w : weights) {
			if (curr_weight + w <= total_weight) {
				curr_weight += w;
			}
			else {
				d++;
				curr_weight = w;
				if (d > m) return false;
			}
		}
		return true;
	}

	int splitArray(vector<int>& nums, int m) {
		int s = 0, e = 0;
		for (auto w : nums) {
			s = max(s, w);
			e += w;
		}
		int ans = INT_MAX;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (isPossible(nums, m, mid)) {
				e = mid - 1;
				ans = min(ans, mid);
			}
			else {
				s = mid + 1;
			}
		}
		return ans;
	}
};