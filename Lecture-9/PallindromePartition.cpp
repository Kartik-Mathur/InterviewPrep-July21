// PallinromePartition.cpp
// https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
	vector<vector<string>> ans;
	void solve(string &s, int start, vector<string> &x) {
		// base case
		if (start == s.size()) {
			ans.push_back(x);
			return;
		}

		// recursive case
		for (int end = start ; end < s.size() ; end++) {
			string meriWali = s.substr(start, end - start + 1);
			if (isPallindrome(meriWali)) {
				x.push_back(meriWali);
				solve(s, end + 1, x);
				x.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		vector<string> x;
		solve(s, 0, x);
		return ans;
	}

	bool isPallindrome(string &s) {
		// cout<<"Checking: "<<s<<endl;
		int start = 0;
		int end = s.size() - 1;
		while (start < end) {
			if (s[start] != s[end]) {
				return false;
			}
			start++;
			end--;
		}

		return true;
	}
};