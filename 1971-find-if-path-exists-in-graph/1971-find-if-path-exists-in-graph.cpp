class Solution {
public:
    bool dfs(int source,  int destination, vector<vector<int>> &adj, vector<bool> &vis) {
        if(source == destination) {
            return true;
        }
        vis[source] = true; 
        for(int v : adj[source]) { 
            if(!vis[v]) {
                if(dfs(v, destination, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size(); 
        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        return dfs(source, destination, adj, vis);
    }
};