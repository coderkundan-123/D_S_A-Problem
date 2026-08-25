class Solution {
public:
    // total source = [0][0];
    //         Dest = [0][0];
    int uniquePaths(int m, int n) {
        vector<vector<int>>t(m, vector<int>(n));

        t[0][0] = 1;

        //fill the 0th row
        for(int j=1; j<n; j++){
            t[0][j] = 1;
        }

        //fill the 0th col
        for(int i=1; i<m; i++){
            t[i][0] = 1;
        }


        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};
