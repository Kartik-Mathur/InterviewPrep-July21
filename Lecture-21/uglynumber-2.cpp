// uglynumber - 2.cpp
class Solution {
public:
	int nthUglyNumber(int n) {
		set<long long int> s;

		s.insert(1);
		long long int ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			ans = *s.begin();
			s.erase(s.begin());

			s.insert(ans * 2);
			s.insert(ans * 3);
			s.insert(ans * 5);
		}
		return ans;
	}
};