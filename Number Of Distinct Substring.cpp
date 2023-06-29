#include <bits/stdc++.h> 
int distinctSubstring(string &word) {
    int n=word.size();
    unordered_map<string ,int>umap;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            umap[word.substr(i,j-i+1)]++;
        }
    }
    return umap.size();
}
