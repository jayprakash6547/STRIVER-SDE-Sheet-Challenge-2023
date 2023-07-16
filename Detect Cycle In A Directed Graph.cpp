#include<bits/stdc++.h>

bool checkCycle(int node, unordered_map<int, bool> &visited,unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int> > &adj)
 {
     visited[node] = true;
     dfsvisited[node] = true;
     for(auto neighbour : adj[node])
     {
       if(!visited[neighbour])
       {
         bool cycleDetected = checkCycle(neighbour, visited, dfsvisited, adj);

         if(cycleDetected)
         {
           return true;
         }
       }
       else if(dfsvisited[neighbour])
       {
         // Visited Case
         return true;
       }
     }
     dfsvisited[node] = false;
     return false;
 }


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
 
 // Create adj list
 unordered_map<int, list<int> > adj;
 for(int i = 0; i<edges.size(); i++)
 {
   int u = edges[i].first;
   int v = edges[i].second;

   // Directed Graph
   adj[u].push_back(v);
 }

 // Visited 
 unordered_map<int, bool>visited;
 unordered_map<int, bool>dfsvisited;

 // Triverse all the vertices

 // Nodes are tstarting from 1 as per question
 for(int i = 1; i<n; i++)
 {
   if(!visited[i])
   {
     bool cycleFound = checkCycle(i, visited, dfsvisited,  adj);
     if(cycleFound)
     {
       return true;
     }
   }
 }
 return false;
}