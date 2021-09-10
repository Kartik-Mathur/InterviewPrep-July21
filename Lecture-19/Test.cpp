class Solution {
public:
	int countPaths(TreeNode* root, int ts) {
		// base case
		if (!root) return NULL;

		int ans = 0;
		// recursive case
		if (root->val - ts == 0) {
			ans++;
		}

		ans += countPaths(root->left, ts - root->val);
		ans += countPaths(root->right, ts - root->val);
		return ans;
	}

	int pathSum(TreeNode* root, int targetSum) {
		if (root == NULL) {
			return 0;
		}
		// Include root and calculate all the paths that have ts
		int ans = countPaths(root, targetSum);
		// Find all the paths in left tree equals to ts
		ans += pathSum(root->left, targetSum);
		// Find all the paths in right subtree equals to ts
		ans += pathSum(root->right, targetSum);
		return ans;
	}
};









