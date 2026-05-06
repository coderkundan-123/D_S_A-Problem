/* patterns 3 most important */
/* GFG PROBLEM -  Maximum point you can obtain from cards */
class Solution {
  public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        
        int lsum = 0, rsum = 0, maxSum = 0;
        
        // take first k elements from left
        for(int i = 0; i < k; i++){
            lsum += arr[i];
        }
        
        maxSum = lsum;
        
        int ridx = n - 1;
        
        // remove from left and add from right
        for(int i = k - 1; i >= 0; i--){
            lsum -= arr[i];
            rsum += arr[ridx];
            ridx--;
            
            maxSum = max(maxSum, lsum + rsum);
        }
        
        return maxSum;
    }
};

