// PathSum3Optimized.cpp
class Solution {
public:
	int ans = 0;
	int pathSum(TreeNode* root, int targetSum) {
		if (!root) return 0;
		unordered_map<int, int> h;
		h[0] = 1;
		solve(root, 0, targetSum, h);
		return ans;
	}

	void solve(TreeNode* root, int cs, int ts, unordered_map<int, int> &h) {
		// base case
		if (!root) return;

		// recursive case
		cs += root->val;
		if (h.count(cs - ts)) {
			ans += h[cs - ts];
		}

		if (h.count(cs) == 0) {
			h[cs] = 1;
		}
		else {
			h[cs] ++;
		}
		solve(root->left, cs, ts, h);
		solve(root->right, cs, ts, h);
		h[cs] --; // Backtracking
	}
};