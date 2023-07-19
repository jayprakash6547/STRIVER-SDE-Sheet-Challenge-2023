#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
  vector<long> dp(value + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = denominations[i]; j <= value; ++j) {
            dp[j] += dp[j - denominations[i]];
        }
    }
    return dp[value];
}