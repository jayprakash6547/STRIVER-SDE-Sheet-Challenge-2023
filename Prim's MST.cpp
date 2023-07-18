#include <bits/stdc++.h>

vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < m; i++) {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int wt = g[i].second;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
  priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
  vector<int> dist(n + 1, INT_MAX);
  vector<int> parent(n + 1, -1);
  vector<int> vis(n + 1, 0);
  pq.push({0, 1});
  dist[1] = 0;
  parent[1] = -1;
  while (!pq.empty()) {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (vis[node])
      continue;
    vis[node] = 1;
    for (auto it : adj[node]) {
      int adjnode = it.first;
      int wt = it.second;
      if (!vis[adjnode] && dist[adjnode] > wt) {
        dist[adjnode] = wt;
        parent[adjnode] = node;
        pq.push({wt, adjnode});
      }
    }
  }
  vector<pair<pair<int, int>, int>> ans;
  for (int i = 2; i <= n; i++) {
    ans.push_back({{parent[i], i}, dist[i]});
  }
  return ans;
}