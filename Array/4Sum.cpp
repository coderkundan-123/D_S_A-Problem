class Solution {
public:
    //T.C :O(nlogn + n^3)
    //S.C :O(uniqueTraplate)
    typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            for(int j=i+1; j<n; ){
                // if(j >=0 && nums[j] == nums[j-1])continue;
                int p=j+1;
                int q=n-1;
                while(p < q){
                    ll sum = (ll)nums[i]+ (ll)nums[j]+ (ll)nums[p]+ (ll)nums[q];
                    if(sum > tar){
                        q--;
                    }else if(sum < tar){
                        p++;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;q--;

                        while(p < q && nums[p] == nums[p-1])p++;
                       
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j-1])j++;
            }
        }

        return ans;
    }
};
