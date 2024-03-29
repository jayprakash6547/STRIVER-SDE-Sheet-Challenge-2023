#include <bits/stdc++.h> 

void path(vector<pair<int,int>>adj[],vector<int>&dis,int source){
    //min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    //dist, node
    dis[source]=0;
    while(!pq.empty()){
        int dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            pair<int,int>p=it;
            //node,weight
            int n=p.first;
            int wt=p.second;
            if(dist+wt<dis[n]){
                dis[n]=dist+wt;
                pq.push({dist+wt,n});
            }
        }
    }
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<int>dis(vertices,INT_MAX);
    vector<pair<int,int>>adj[vertices];
    for(int i=0;i<vec.size();i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int wt=vec[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    path(adj,dis,source);
    return dis;
}