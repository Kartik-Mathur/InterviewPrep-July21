#include <iostream>
#include <vector>
using namespace std;

int solve(int sum, int k, int pe, int n, vector<int> &v) {
	if (sum == 0 and k == 0) {
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
		return 1;
	}
	if (sum > 0 and k == 0 || sum < 0 || sum < k) {
		return 0;
	}


	int ans = 0;
	for (int i = pe; i <= n; i++) {
		v.push_back(i);
		ans += solve(sum - i, k - 1, i, n, v);
		v.pop_back();
	}
	return ans;
}

int main() {
	int n = 8;
	int k = 4;
	vector<int> ans;
	cout << solve(n, k, 1, n, ans) << endl;

	return 0;
}
















