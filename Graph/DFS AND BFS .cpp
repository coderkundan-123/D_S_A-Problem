/* DFS traversal */
/* Time Complexity
     O(V + E)
  Space Complexity
     O(V) (visited + recursion stack)
*/
class Solution {
  public:
    int dfs(int curr, vector<vector<int>>& adj, vector<int> &vis, vector<int> &ans){
        vis[curr] = 1;
        ans.push_back(curr);
        
        
        for(auto it : adj[curr]){
            if(!vis[it]){
                dfs(it, adj, vis, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n,0);
        vector<int> ans;
        dfs(0, adj, vis, ans);
        
        return ans;
    }
};

/* BFS traversal */

