// EditDistance.cpp
#include <iostream>
using namespace std;

int dp[100][100];


int EditDistance(char *s1, char *s2, int i, int j) {
	// base case
	if (i == 0) return dp[i][j] = j;
	if (j == 0) return dp[i][j] = i;

	if (dp[i][j] != -1) return dp[i][j];
	// recursive case
	if (s1[i - 1] != s2[j - 1]) {
		return dp[i][j] = 1 + min(EditDistance(s1, s2, i - 1, j),
		                          min(EditDistance(s1, s2, i - 1, j - 1),
		                              EditDistance(s1, s2, i, j - 1)));
	}
	else {
		return dp[i][j] = EditDistance(s1, s2, i - 1, j - 1);
	}
}

int main() {

	char s1[] = "Sunday";
	char s2[] = "Saturday";
	memset(dp, -1, sizeof dp);
	cout << EditDistance(s1, s2, strlen(s1), strlen(s2)) << endl;

	return 0;
}
















