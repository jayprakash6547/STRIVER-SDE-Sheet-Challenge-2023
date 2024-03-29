vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    map<int,set<int>>adj_list;
    map<int,bool>vis;
    for(int i=0;i<edges.size();i++)
    {
      adj_list[edges[i][0]].insert(edges[i][1]);
      adj_list[edges[i][1]].insert(edges[i][0]);
    }
    vector<vector<int>>v;
    vector<int>ans;
    for(int i=0;i<V;i++)
    {
      if(vis[i]==0)
      {
        stack<int>st;
        st.push(i);
        int top;
        vis[i]=1;
        while(!st.empty())
        {
          top=st.top();
          st.pop();
          ans.push_back(top);
          for(auto it:adj_list[top])
          {
            if (vis[it] == 0) {
              st.push(it);
              vis[it]=1;
            }
          }
        }
         v.push_back(ans);
          ans.clear();
      } 
    }
    return v;
}