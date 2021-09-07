// https://leetcode.com/problems/house-robber-iii/
class Solution {
public:
	vector<int> solve(TreeNode* root) {
		// base case
		if (!root) {
			return {0, 0}; // {rob,notRob}
		}
		// recursive case
		vector<int> left = solve(root->left);//{rob,notRob}
		vector<int> right = solve(root->right);// {rob,notRob}
		// left[0],right[0] : Robbery hui
		// left[1],right[1] : Robbery nhi hui
		int rob = root->val + left[1] + right[1];
		int notRob = max(left[0], left[1]) + max(right[0], right[1]);
		return {rob, notRob};
	}
	int rob(TreeNode* root) {
		if (!root) return 0;
		vector<int> ans = solve(root);
		return max(ans[0], ans[1]);
	}
};

















