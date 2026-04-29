/* T.C : O(V + E) 
   S.C : O(V) both BFS and DFS */
class Solution {
  public:
  
    bool dfs(vector<vector<int>> &adj, int u, vector<bool> &vis, int parent){
        vis[u] = true;
        
        for(int v : adj[u]){
            if(v == parent) continue;
            
            if(vis[v]) return true;
            
            if(!vis[v]){
                if(dfs(adj, v, vis, u)) return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        // build graph
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(adj, i, vis, -1)) return true;
            }
        }
        
        return false;
    }
};
