/***************** GFG PROBLEM *************/
/* T.C : O(n*m)
   S.C : O(n*m)
*/
class Solution {
  public:
    int t[1001][1001];
    int LCS(string &s, int i, int j, int n){
        if(i == n || j == n){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s[i] == s[j] && i != j){
            return  t[i][j] = 1 + LCS(s, i+1 ,j+1, n);
        }
        return t[i][j]=  max(LCS(s, i+1, j, n), LCS(s, i, j+1, n));
    }
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int n = s.size();
        memset(t, -1, sizeof(t));
        return LCS(s, 0,0,n);
    }
};
