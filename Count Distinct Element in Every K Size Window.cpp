#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int>ans;
    unordered_map<int,int>umap;
    for(int i=0;i<arr.size();i++){
        umap[arr[i]]++;
        if(i>=k-1){
            ans.push_back(umap.size());
            if(--umap[arr[i-k+1]]==0)umap.erase(arr[i-k+1]);
        }
    }
	return ans;
}
