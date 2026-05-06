/* 2 Patterns Longest Subarray with Sum K */
/* Code (Brute Force) 
 T.C : O(N^2) */
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxlen = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += arr[j];
                
                if(sum <= k){
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        
        return maxlen;
    }
};
/* optimal solution */
/*(Prefix Sum + HashMap) */
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int sum = 0, maxlen = 0;

        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];

            if(sum == k){
                maxlen = i + 1;
            }

            if(mp.find(sum - k) != mp.end()){
                maxlen = max(maxlen, i - mp[sum - k]);
            }

            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }

        return maxlen;
    }
};
