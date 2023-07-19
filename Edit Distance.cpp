#include<bits/stdc++.h>
int editDistance(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    // Create a 2D DP array to store the edit distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base case: if one of the strings is empty
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    // Fill in the DP array
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    // The edit distance is stored in the bottom-right cell of the DP array
    return dp[m][n];
}