/********** memo + top - down Apporch ***********/
/* T.C :O(n^2)
    S.C :O(n^2)
*/
class Solution {
  public:
    int t[1001][1001];
    int LCS(string &a, string &b, int i, int j){
        //base case
        if(i == a.size() || j == b.size()){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(a[i] == b[j]){
            return t[i][j] = 1+ LCS(a,b,i+1,j+1);
        }
        
        return t[i][j] =  max(LCS(a,b,i+1,j), LCS(a,b,i,j+1));
    }
    int longestPalinSubseq(string &s) {
        // code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        memset(t,-1, sizeof(t));
        
        return LCS(s, rev, 0, 0);
    }
};
