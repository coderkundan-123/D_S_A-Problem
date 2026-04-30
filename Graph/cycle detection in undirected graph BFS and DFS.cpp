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
/* BFS Methods */
class Solution {
public:
    bool isCycleBFS(vector<vector<int>> &adj, int u, vector<bool> &vis){
        queue<pair<int, int>> que;
        que.push({u, -1});
        vis[u] = true;

        while(!que.empty()){
            auto P = que.front();
            que.pop();

            int source = P.first;
            int parent = P.second;

            for(int v : adj[source]){
                if(!vis[v]){
                    vis[v] = true;
                    que.push({v, source});
                }
                else if(v != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // build graph
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleBFS(adj, i, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
