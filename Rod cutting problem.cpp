#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int maxRevenue = INT_MIN;
        for (int j = 1; j <= i; ++j) {
            maxRevenue = max(maxRevenue, price[j - 1] + dp[i - j]);
        }
        dp[i] = maxRevenue;
    }
    return dp[n];
}
