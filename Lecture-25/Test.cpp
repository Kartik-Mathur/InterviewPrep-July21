class Solution {
public:
    unordered_map<string, bool> h;
    int dp[1000] = {0};
    bool solve(string &s, int i) {
        if (i == s.length()) return dp[i] = true;
        if (dp[i] != -1) return dp[i];

        for (int j = i ; j < s.length() ; j++) {
            string word = s.substr(i, j - i + 1);
            if (h.count(word)) {
                bool chotaAns = solve(s, j + 1);
                if (chotaAns) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Insert all the words in the hashmap
        for (auto word : wordDict) {
            h[word] = true;
        }
        memset(dp, -1, sizeof dp);
        return solve(s, 0);
    }
};