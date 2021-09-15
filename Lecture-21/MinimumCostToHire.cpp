// MinimumCostToHire.cpp
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
class worker {
public:
	int quality;
	int wage;
	double ratio;
};
class Solution {
public:
	static bool compare(worker a, worker b) {
		return a.ratio < b.ratio;
	}

	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		worker w[wage.size()];
		int n = wage.size();
		for (int i = 0 ; i < wage.size() ; i++) {
			w[i].quality = quality[i];
			w[i].wage = wage[i];
			w[i].ratio = (double)(wage[i]) / quality[i];
		}

		// for(int i = 0 ; i < n ; i++){
		//     cout<<w[i].quality<<" "<<w[i].wage<<" "<<w[i].ratio<<endl;
		// }

		sort(w, w + n, compare);

		for (int i = 0 ; i < n ; i++) {
			cout << w[i].quality << " " << w[i].wage << " " << w[i].ratio << endl;
		}

		double ans = INT_MAX;

		priority_queue<int> q;
		int total_quality = 0;
		for (int i = 0 ; i < n ; i++) {
			total_quality += w[i].quality;
			q.push(w[i].quality);

			if (q.size() > k) {
				total_quality -= q.top();
				q.pop();
			}
			if (q.size() == k) {
				ans = min(ans, total_quality * w[i].ratio);
			}
		}


		return ans;
	}
};















