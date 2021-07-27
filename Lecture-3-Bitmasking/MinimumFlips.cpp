class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0 ; i < 32 ; i++) {
            if ( ((a | b) & 1) != (c & 1)) {
                if ((c & 1)) {
                    ans++;
                }
                else {
                    if (a & 1) ans++;
                    if (b & 1) ans++;
                }
            }

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }

        return ans;
    }
};