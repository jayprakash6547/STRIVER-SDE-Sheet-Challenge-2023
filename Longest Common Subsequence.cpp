#include<vector>
int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int ind2=0; ind2<=m; ind2++){
        dp[0][ind2]=0;
    }
    for(int ind1=0; ind1<=n; ind1++){
        dp[ind1][0]=0;
    }
    for(int ind1=1; ind1<=n; ind1++){
        for(int ind2=1; ind2<=m; ind2++){
            if(s[ind1-1]==t[ind2-1])
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2]=0+max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }
    return dp[n][m];
}