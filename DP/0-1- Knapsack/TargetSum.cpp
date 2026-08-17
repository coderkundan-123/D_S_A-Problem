//T.C = O(n * totalSum)
//S.C = O(n * totalSum)
/***************************Problem 05 ***************/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();

        int totalSum = 0;
        for(int x : nums){
            totalSum +=x;
        }

        if(abs(tar) > totalSum){
            return 0;
        }

        if((totalSum + tar) % 2 !=0){
            return 0;
        }
        int target = (totalSum + tar)/2;
        vector<vector<int>> t(n+1,vector<int>(target+1,-1));

        for(int i=0; i<=n; i++){// row first ok true karna hai
            t[i][0] = 1;
        }
        for(int j=1; j<=target; j++){// col first ko true karna hai
            t[0][j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<=target; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][target];
    }
};
