#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    map<long long,pair<int,int>>mp;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long sum=arr[i]+arr[j];
            int ans=target-sum;
            if(mp.find(ans)!=mp.end()){
                if(mp[ans].first!=i && mp[ans].second!=i && mp[ans].first!=j && mp[ans].second!=j){
                    return "Yes";
                }
            }
            mp[sum] = {i,j};
        }
    }
    return "No";
}
