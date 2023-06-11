#include <bits/stdc++.h>
using namespace std;

int findPaths(vector<vector<int>>& dp, int m, int n) {
	if (m <= 0 || n <= 0)
		return 0;
	if (m == 1 && n == 1) 
		return 1;
	if (dp[m][n] != -1)
		return dp[m][n];
	
	int count = findPaths(dp, m, n-1) + findPaths(dp, m-1, n);
	return dp[m][n] = count;
}

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	dp[0][0] = 0;
	dp[1][1] = 1;

	return findPaths(dp, m, n);
}