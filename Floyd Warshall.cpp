#include <bits/stdc++.h>
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> edges) {
    vector<vector<int>> dist(n+1, vector<int>(n+1));
    int high = 1000000000;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<= n; j++) {
            if(i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = high;
            }
        }
    }

    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
    }

    for(int k=1; k<=n; k++) {
        for(int u=1; u<=n; u++) {
            for(int v=1; v<= n; v++) {
                if((dist[u][k] != high && dist[k][v] != high) && dist[u][k] + dist[k][v] < dist[u][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }

    bool isCycle = false;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<= n; j++) {
            if(i == j && dist[i][j] != 0) {
                isCycle = true;
            }
        }
    }

    if(isCycle) {
        return -1;
    }

    return dist[src][dest];
}
