/**
 * Problem: 1582. Special Positions in a Binary Matrix
 * Time Complexity: O(m * n) - where m is rows and n is columns
 * Space Complexity: O(m + n) - for row and column sum arrays
 */
/* ******************* First Method **************** */
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       int m = mat.size();
       int n = mat[0].size();

       vector<int> rowCount(m,0);// hom many 1s in a row
       vector<int> colCount(n,0);//hom many 1s in a colum

       for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            if(mat[row][col] == 1){
                rowCount[row]++;
                colCount[col]++;
            }
        }
       }

       int ans = 0;
       for(int row = 0; row < m; row++){
           for(int col = 0; col < n; col++){
               if(mat[row][col] == 0) continue;
               
               if(rowCount[row] == 1 && colCount[col] == 1){
                   ans++;
               }
           }
       }

       return ans;
    }
};

/******************* Sec Method ****************** */
/* 
    Time Complexity: O((m*n) . (m + n ))
  */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for(int row = 0; row < m; row++){
            for(int col=0; col<n; col++){

                if(mat[row][col] == 0)continue;

                bool special = true;
                //check columan
                for(int r = 0; r < m; r++){
                    if(r != row && mat[r][col] == 1){
                        special = false;
                        break;
                    }
                }

                //check row
                for(int c= 0; c<n; c++){
                    if(c != col && mat[row][c] == 1){
                        special = false;
                        break;
                    }
                }

                if(special == true){
                    ans++;
                }
            }
        }

        return ans;
    }
};
