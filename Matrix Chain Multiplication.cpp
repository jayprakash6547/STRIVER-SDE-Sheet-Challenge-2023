#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
     vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 2; len < N; len++) {
        for (int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }

    return dp[1][N - 1];
}