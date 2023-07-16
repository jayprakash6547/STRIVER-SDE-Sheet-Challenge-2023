#include <bits/stdc++.h> 
graphNode* cloneGraph(graphNode* node) {
    // Write your code here.
    unordered_map<graphNode*, graphNode*> cloned;
    function<graphNode*(graphNode*)> dfs = [&](graphNode* node) {
        if (cloned.count(node)) {
            return cloned[node];
        }
        graphNode* node_copy = new graphNode(node->data);
        cloned[node] = node_copy;
        for (graphNode* n : node->neighbours) {
            node_copy->neighbours.push_back(dfs(n));
        }
        return node_copy;
    };
    return node ? dfs(node) : nullptr;
}
