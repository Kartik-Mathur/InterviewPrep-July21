// StockSpan.cpp
#include <iostream>
#include <vector>
using namespace std;


int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}

	vector<int> ans(n);
	ans[0] = 1;

	stack<int> s;
	s.push(0);

	for (int i = 1; i < n ; i++) {
		while (!s.empty() and a[s.top()] < a[i]) {
			s.pop();
		}

		if (!s.empty())
			ans[i] = i - s.top();
		else
			ans[i] = i + 1;

		s.push(i);
	}
	for (int i = 0; i < n ; i++) {
		cout << ans[i] << " ";
	}
	cout << "END";


	return 0;
}
















