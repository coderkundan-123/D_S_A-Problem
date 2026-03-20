/******************** cpp solution *********************/
/* T.C : O(m * n * k^2 log k)
   S.C : O(k^2 + m * n)
*/
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));

        for(int i=0; i<=m-k; i++){
            for(int j=0; j<=n-k; j++){
                set<int>val;

                for(int p=i; p <= i+k-1; p++){
                    for(int q=j; q<=j+k-1; q++){
                        val.insert(grid[p][q]);
                    }
                }

                if(val.size() == 1){
                    ans[i][j] = 0;
                    continue;
                }

                int minDiff = INT_MAX;
                auto prev = val.begin();
                auto curr = next(prev);

                while(curr != val.end()){
                    minDiff = min(minDiff, *curr- *prev);
                    prev = curr;
                    curr++;
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};
