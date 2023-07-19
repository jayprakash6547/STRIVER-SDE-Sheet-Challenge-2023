#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<int> dp(n, 0);
    dp[0] = rack[0]; 

    for (int i = 1; i < n; ++i) {
        dp[i] = rack[i]; 

        for (int j = 0; j < i; ++j) {
            if (rack[i] > rack[j]) {
                dp[i] = max(dp[i], dp[j] + rack[i]);
            }
        }
    }
    int maxSum = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > maxSum) {
            maxSum = dp[i];
        }
    }

    return maxSum;
}