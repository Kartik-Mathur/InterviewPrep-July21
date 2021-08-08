#define pb push_back
class Solution {
public:
    vector<string> ans;
    int N;

    void solve(char *a, int i, int open, int close) {
        if (i == 2 * N) {
            a[i] = '\0';
            string x(a);
            ans.pb(x);
            return;
        }

        if (open < N) {
            a[i] = '(';
            solve(a, i + 1, open + 1, close);
        }
        if (close < open) {
            a[i] = ')';
            solve(a, i + 1, open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        char a[1000];
        N = n;
        solve(a, 0, 0, 0);
        return ans;
    }
};