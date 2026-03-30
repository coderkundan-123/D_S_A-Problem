class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n){
        if(i > n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int take = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] =  max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        memset(t, -1, sizeof(t));

        // case 1 -> take first house oth index wala house
        int take_0th_house = solve(nums, 0, n-2);

        memset(t, -1, sizeof(t));
        
        //case 2 -> take second house 1th index wala house
        int take_1st_house = solve(nums, 1, n-1);

        return max(take_0th_house, take_1st_house);
    }
};
/************* BOttom-Up *******************/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1, 0);
        t[0] = 0;

        for(int i=1; i<=n-1; i++){
            int skip = t[i-1];
            int take = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0);
            t[i] = max(skip, take);
        }
        int result1 = t[n-1];

        t.clear();

        //case2 skip first house
        t[0] = 0;
        t[1] = 0;
        for(int i=2; i<=n; i++){
            int skip = t[i-1];
            int take = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0);
            t[i] = max(skip, take);
        }
        int result2 = t[n];

        return max(result1, result2);
    }
};
