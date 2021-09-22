// LCS.cpp
#include <iostream>
using namespace std;

void printLCS(char *s1, char*s2, char *ans, int len, int i, int j, int dp[][100]) {
	// base case
	if (len == 0) {
		cout << ans << endl;
		return;
	}
	// recursive case
	if (s1[i - 1] == s2[j - 1]) {
		ans[len - 1] = s1[i - 1];
		printLCS(s1, s2, ans, len - 1, i - 1, j - 1, dp);
	}
	else {
		if (dp[i - 1][j] > dp[i][j - 1]) {
			printLCS(s1, s2, ans, len, i - 1, j, dp);
		}
		else if (dp[i - 1][j] < dp[i][j - 1]) {
			printLCS(s1, s2, ans, len, i, j - 1, dp);
		}
		else { // Only if we want to print all the possible LCS
			printLCS(s1, s2, ans, len, i - 1, j, dp);
			printLCS(s1, s2, ans, len, i, j - 1, dp);
		}
	}
}

int LCS(char *s1, char *s2) {
	int dp[100][100] = {0};
	int n = strlen(s1);
	int m = strlen(s2);
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m ; j++) {
			if (s1[i - 1] != s2[j - 1]) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i <= strlen(s1) ; i++) {
		for (int j = 0; j <= strlen(s2) ; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	// Printing the LCS
	char ans[100];
	int len = dp[n][m];
	ans[len] = '\0';
	printLCS(s1, s2, ans, dp[n][m], n, m, dp);
	// int i = n;
	// int j = m;
	// char ans[100];
	// int indx = dp[n][m];
	// ans[indx] = '\0';
	// indx--;
	// while (i > 0 and j > 0) {
	// 	if (s1[i - 1] == s2[j - 1]) {
	// 		ans[indx--] = s1[i - 1];
	// 		i--;
	// 		j--;
	// 	}
	// 	else {
	// 		if (dp[i - 1][j] > dp[i][j - 1]) {
	// 			i--;
	// 		}
	// 		else {
	// 			j--;
	// 		}
	// 	}
	// }
	// cout << ans << endl;
	return dp[n][m];
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char s1[100], s2[100];

	cin >> s1 >> s2;

	cout << LCS(s1, s2) << endl;

	return 0;
}
















