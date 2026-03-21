/***************** Recursion Methods ****************/
/* T.C :O(2^n)
   S.C :(n);
*/
class Solution {
public:
    int solve(vector<int>& nums, int i){
        if(i >= nums.size()){
            return 0;
        }
        int steal = nums[i] + solve(nums, i+2);
        int skip = solve(nums, i+1);

        return max(steal, skip);
    }
    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};
/**************** memo ****************/
/* T.C :O(n)
   S.C :(n);
*/
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n){
        if(i >= n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};
/************ Bottom-up ***************/
/* T.C :O(n)
   S.C :(n);
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
           return nums[0];

        vector<int> t(n+1, 0);
        t[0] = 0;
        t[1] = nums[0];

        for(int i = 2; i <= n; i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(steal, skip); 
        }

        return t[n];
    }
};
