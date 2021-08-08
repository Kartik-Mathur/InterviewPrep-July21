// CombinationSum.cpp
#define pb push_back

class Solution {
public:
	vector<vector<int>> ans;

	void solve(vector<int>& candidates, int i, int target, int sum, vector<int>& v) {
		// base case
		if (sum == target) {
			ans.pb(v);
			return;
		}
		if (sum > target || i >= candidates.size()) {
			return;
		}

		// recursive case
		// include ith character
		if (sum + candidates[i] <= target) {
			v.pb(candidates[i]);
			solve(candidates, i, target, sum + candidates[i], v);
			v.pop_back();
		}

		// ignore ith character
		solve(candidates, i + 1, target, sum, v);
	}
//     void solve(vector<int>& candidates,int s,int target,int sum,vector<int>& v){
//         // base case
//         if(sum == target){
//             ans.pb(v);
//             return;
//         }
//         if(sum>target){
//             return;
//         }

//         // recursive case
//         for(int i = s ; i <candidates.size() ; i++){
//             if(sum+candidates[i] <= target){
//                 v.pb(candidates[i]);
//                 solve(candidates,i,target,sum+candidates[i],v);
//                 v.pop_back(); // Backtracking
//             }
//         }
//     }

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> v;
		solve(candidates, 0, target, 0, v);

		return ans;
	}
};