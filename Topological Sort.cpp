#include <bits/stdc++.h> 
    void dfs(int node, vector<int> &ans, vector<vector<int>> &adj,
    vector<int> &vis){
        vis[node] =1;
        
        for(auto it: adj[node]){
            if(!vis[it])dfs(it,ans,adj,vis);
        }
        ans.push_back(node);
    }
    void bfs(vector<int> &ans, vector<vector<int>> &adj){
        queue<int> q;
        vector<int> indegree(adj.size(),0);
        for(auto i: adj){
            for(auto j: i){
                indegree[j]++;
            }
        }
        for(int i=0; i<indegree.size(); i++)if(indegree[i]==0)q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    }
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    vector<vector<int>> adj(v);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }
    vector<int> vis(v,0);
    // for(int i=0; i<v; i++){
        // if(!vis[i])dfs(i,ans,adj,vis);
    // }
    bfs(ans,adj);
    // reverse(ans.begin(),ans.end());///uncomment in case of dfs
    return ans;
}