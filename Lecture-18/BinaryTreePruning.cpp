// BinaryTreePruning.cpp
// https://leetcode.com/problems/binary-tree-pruning/
class Pair {
public:
	TreeNode* ra;
	bool isOnePresent;
};

class Solution {
public:

	Pair solve(TreeNode* root) {
		// base case
		if (!root) {
			return {NULL, false};
		}
		// recursive case
		Pair left = solve(root->left);
		Pair right = solve(root->right);

		if (!left.isOnePresent) {
			root->left = NULL;
		}
		if (!right.isOnePresent) {
			root->right = NULL;
		}

		if (root->val == 0 and !left.isOnePresent and !right.isOnePresent) {
			return {NULL, false};
		}

		root->left = left.ra;
		root->right = right.ra;

		return {root, true};
	}

	TreeNode* pruneTree(TreeNode* root) {
		Pair ans = solve(root);
		return ans.ra;
	}
};