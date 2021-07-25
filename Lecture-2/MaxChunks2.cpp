// MaxChunks2.cpp
class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {

		int lmax[100000];
		int rmin[100000];
		int n = arr.size();

		int ans = 0;
		for (int i = 0 ; i < n ; i++) {
			ans = max(ans, arr[i]);
			lmax[i] = ans;
		}

		rmin[n] = INT_MAX;
		ans = INT_MAX;
		for (int i = n - 1; i >= 0 ; i--) {
			ans = min(ans, arr[i]);
			rmin[i] = ans;
		}

		int res = 0;
		for (int i = 0 ; i < n ; i++) {
			if (lmax[i] <= rmin[i + 1]) {
				res++;
			}
		}
		return res;
	}
};

class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		multiset<int> meraArray;
		multiset<int> idealArray;

		vector<int> ideal(arr.begin(), arr.end());
		sort(ideal.begin(), ideal.end());

		int ans = 0;
		for (int i = 0 ; i < arr.size() ; i++) {
			meraArray.insert(arr[i]);
			idealArray.insert(ideal[i]);

			if (meraArray == idealArray) {
				ans++;
			}
		}
		return ans;

	}
};