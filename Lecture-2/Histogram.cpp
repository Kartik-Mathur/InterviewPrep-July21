class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int pse [1000000];
        int nse [1000000];
        pse[0] = -1;
        int n = heights.size();
        stack<int> s;

        for (int i = 0 ; i < n ; i++) {
            while (!s.empty() and heights[s.top()] > heights[i]) {
                nse[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        while (!s.empty()) {
            nse[s.top()] = n;
            s.pop();
        }

        for (int i = 0 ; i < n ; i++)cout << nse[i] << " ";
        cout << endl;

        s.push(0);

        for (int i = 1 ; i < n ; i++) {
            while (!s.empty() and heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (!s.empty()) {
                pse[i] = s.top();
            }
            else {
                pse[i] = -1;
            }
            s.push(i);
        }

        for (int i = 0 ; i < n ; i++)cout << pse[i] << " ";
        cout << endl;


        // return 10;
        int res = 0;

        for (int curr = 0 ; curr < n ; curr++) {
            int i = pse[curr];
            int j = nse[curr];

            int area = (j - i - 1) * heights[curr];
            res = max(res, area);
        }
        return res;

    }
};
















