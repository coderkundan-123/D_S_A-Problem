/* T.C : O(V + E)
   S.C : O(V) */
class Solution {
public:
    bool isCycleDFS(vector<vector<int>> &adj, int u, vector<bool> &vis, vector<bool> &inRecursion){
        vis[u] = true;
        inRecursion[u] = true;

        for(int v : adj[u]){
            if(!vis[v]){
                if(isCycleDFS(adj, v, vis, inRecursion))
                    return true;
            }
            else if(inRecursion[v]){
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        // Directed graph
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> vis(V, false);
        vector<bool> inRecursion(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleDFS(adj, i, vis, inRecursion))
                    return true;
            }
        }
        return false;
    }
};
