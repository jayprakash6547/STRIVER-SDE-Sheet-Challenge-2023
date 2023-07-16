#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    vector<int>adj[vertex];
    for (int i = 0; i < vertex; i++) {
      adj[i].push_back(i);
    }
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<vertex;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    vector<int>V(vertex,0);
    queue<int>q;
    vector<int>ans;
    for(int i=0;i<vertex;i++)
    {
        if(V[i]==0)
        {
            q.push(i);
            V[i]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node])
                {
                    if(V[it]==0)
                    {
                        q.push(it);
                        V[it]=1;
                    }
                }
            }
        }
    }
    return ans;
}