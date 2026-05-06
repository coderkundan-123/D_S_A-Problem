/* Patterns 1 problem */
/* constant window */
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int sum = 0;
        // first window of size k
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        
        int maxSum = sum;
        
        // sliding window
        for(int i = k; i < n; i++){
            sum += arr[i];        // add next element
            sum -= arr[i - k];    // remove previous window element
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
