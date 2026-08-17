// T.C = O(n * tar)
//S.C = O(n * tar)
/************************** Problem 03 *******************/
class Solution {
  public:
    int perfectSum(vector<int>& arr, int tar) {
        // code here
        int n = arr.size();
        vector<vector<int>> t(n+1, vector<int>(tar+1, -1));
        
        for(int i=0; i<=n; i++){
            t[i][0] = 1;
        }
        for(int j=1; j<=tar; j++){
            t[0][j] = 0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=tar; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][tar];
    }
};
