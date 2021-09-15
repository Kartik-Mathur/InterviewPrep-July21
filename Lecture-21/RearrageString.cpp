// RearrageString.cpp
class Solution {
public:
	string rearrangeString(string s, int k) {
		int freq[26] = {0};
		for (auto ch : s) {
			freq[ch - 'a']++;
		}

		int freq_max = 0;
		for (int i = 0 ; i < 26 ; i++) {
			freq_max = max(freq_max, freq[i]);
		}

		int freq_max_cnt = 0;
		priority_queue<pair<int, char> > pq;
		for (int i = 0 ; i < 26 ; i++) { // 'a'+0: 'a', 'a'+1: 'b', 'a'+2: 'c'
			if (freq_max == freq[i])
				freq_max_cnt++;
			if (freq[i] > 0) {
				pq.push({freq[i], 'a' + i});
			}
		}

		int len = s.length();
		if ((freq_max - 1)*k + freq_max_cnt > len) return "";

		string ans;
		queue<pair<int, char> > q;

		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			ans.push_back(p.second);

			q.push({p.first - 1, p.second});
			if (q.size() >= k) {
				auto p1 = q.front();
				q.pop();
				if (p1.first != 0) {
					pq.push({p1.first, p1.second});
				}
			}

		}

		return ans;
	}
};

















