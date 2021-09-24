// WordBreak - 2.cpp
class Solution {
public:
	unordered_map<string, vector<string> > dp;
	vector<string> solve(string s, vector<string>& wordDict) {
		// base case
		if (s.length() == 0) {
			return dp[s] = {""};
		}


		if (dp.count(s)) return dp[s];

		// recursive case
		vector<string> BadaAns, ChotaAns;
		for (auto word : wordDict) {
			int len = word.length();
			if (s.substr(0, len) == word) {
				ChotaAns = solve(s.substr(len), wordDict);
				for (auto ans : ChotaAns) {
					string space = ans.length() ? " " : "";
					BadaAns.push_back(word + space + ans);
				}
			}
		}

		return dp[s] = BadaAns;
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> ans = solve(s, wordDict);
		return ans;
	}
};