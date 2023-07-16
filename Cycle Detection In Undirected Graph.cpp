#include <bits/stdc++.h>

using namespace std;

struct Pair {
    int prv;
    int n;
    Pair(int n, int prv) {
        this->prv = prv;
        this->n = n;
    }
};

string cycleDetection(vector<vector<int>> edges, int n, int m) {
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);

    for (int i = 0; i < m; ++i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    queue<Pair> q;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            q.push(Pair(i, -1));
            while (!q.empty()) {
                Pair t = q.front();
                q.pop();
                if (!vis[t.n]) {
                    vis[t.n] = true;
                    for (int j : adj[t.n]) {
                        if (!vis[j]) q.push(Pair(j, t.n));
                    }
                } else return "Yes";
            }
        }
    }

    return "No";
}
