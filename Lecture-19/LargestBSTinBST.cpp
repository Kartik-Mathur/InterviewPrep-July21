// LargestBSTinBST.cpp
class info {
public:
	bool isBst;
	int mi, mx, size;
};

class Solution {
public:

	info solve(TreeNode*root) {
		// Base case
		if (!root) {
			return {true, INT_MAX, INT_MIN, 0};
		}

		if (!root->left and !root->right) {
			return {true, root->val, root->val, 1};
		}

		// recursive
		info left = solve(root->left);
		info right = solve(root->right);
		info ans;
		if (left.isBst and right.isBst and root->val > left.mx and root->val < right.mi) {
			ans.mi = min(left.mi, min(right.mi, root->val));
			//ans.mx = max(right.mx, max(right.mx, root->val));
			ans.mx = max(right.mx, max(left.mx, root->val)); //this is correct, we have to find the mx of entire subtree
			ans.size = 1 + left.size + right.size;
			ans.isBst = true;
			return ans;
		}

		ans.isBst = false;
		ans.size = max(left.size, right.size);
		return ans;
	}

	int largestBSTSubtree(TreeNode* root) {
		info ans = solve(root);
		return ans.size;
	}
};