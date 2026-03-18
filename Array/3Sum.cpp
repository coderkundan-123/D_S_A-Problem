/******** TLE SOLUTION ********************/
class Solution {
public:
    //T.C :O(n^3 *log(uniqueTreplet))
    //S.C :O(uniqueTreplet)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
       // vector<vector<int>> ans;
        set<vector<int>> uniqueTriplets;
        for(int i=0; i<n; i++){
            int tar = -nums[i];
            set<int> s;

            for(int j=i+1; j<n; j++){
                int third = tar - nums[j];

                if(s.find(third) != s.end()){
                    vector<int> trip = {nums[i], nums[j], third};
                    sort(trip.begin(), trip.end());
                    uniqueTriplets.insert(trip);
                }
                s.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};
/**************** sec Methods ********************/
class Solution {
public:
    //T.C :O(nlong + n^2)
    //S.C :O(uniqueTriplate)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j=i+1;
            int k=n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};
