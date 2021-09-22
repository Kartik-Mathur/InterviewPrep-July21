// Knapsack.cpp
#include <iostream>
#include <vector>
using namespace std;

int dp[100][100];

// Top Down
int Knapsack(int *price, int *weight, int n, int capacity) {
	// Base case
	if (n == 0 || capacity == 0) {
		return dp[n][capacity] = 0;
	}

	// Recursive case
	if (dp[n][capacity] != -1) {
		return dp[n][capacity];
	}

	int op1, op2;
	op1 = op2 = INT_MIN;
	// 1. rob the current item
	if (weight[n - 1] <= capacity) {
		op1 = price[n - 1] + Knapsack(price, weight, n - 1, capacity - weight[n - 1]);
	}

	// 2. dont rob the current item
	op2 = 0 + Knapsack(price, weight, n - 1, capacity);

	return dp[n][capacity] = max(op1, op2);
}

int BottomUp(int *price, int *weight, int N, int capacity) {

	// int dp[100][100] = {0};
	vector<vector<int> > dp(N + 1, vector<int>(capacity + 1, 0));

	for (int n = 1; n <= N ; n++) {
		for (int c = 1; c <= capacity ; c++) {
			int op1 = INT_MIN, op2 = INT_MIN;
			if (weight[n - 1] <= c) {
				op1 = price[n - 1] + dp[n - 1][c - weight[n - 1]];
			}
			op2 = dp[n - 1][c];
			dp[n][c] = max(op1, op2);
		}
	}

	for (int n = 0; n <= N ; n++) {
		for (int c = 0; c <= capacity ; c++) {
			cout << dp[n][c] << " ";
		}
		cout << endl;
	}

	return dp[N][capacity];

}

int main() {

	int price[] = {2, 1, 4 , 4};
	int weight[] = {1, 2, 3, 2};

	int n = sizeof(price) / sizeof(int);

	memset(dp, -1, sizeof dp);

	cout << Knapsack(price, weight, n, 4) << endl;
	cout << BottomUp(price, weight, n, 4) << endl;
	return 0;
}
















