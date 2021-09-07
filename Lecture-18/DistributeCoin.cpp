// DistributeCoin.cpp
// https://leetcode.com/problems/distribute-coins-in-binary-tree/
class Solution {
public:
	int total_moves = 0;

	int sikke(TreeNode* root) {
		if (!root) return 0;

		int left = sikke(root->left);
		int right = sikke(root->right);

		total_moves += abs(left) + abs(right);
		return root->val + left + right - 1;
	}

	int distributeCoins(TreeNode* root) {
		sikke(root);
		return total_moves;
	}
};