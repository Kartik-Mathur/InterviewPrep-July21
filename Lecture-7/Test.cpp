#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

	int total = 0 ;
	int cur = 0 ;
	int s = 0;
	for (int i = 0 ; i < gas.size() ; i++) {
		total = total + gas[i] - cost[i];
		cur += gas[i] - cost[i];
		if (cur < 0) {
			cur =  0 ;
			s = i + 1 ;
		}
	}
	if (total >= 0 )
		return s;
	else
		return -1;

}

int main () {

	int n ;
	cin >> n;

	vector<int>gas(n);
	vector<int>cost(n);


	for (int i = 0; i < n; i++) {
		cin >> gas[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	int ans = canCompleteCircuit(gas, cost);

	cout << ans;

}
