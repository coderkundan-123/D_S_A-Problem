/****************** first Method ************************/
class Solution {
public:
    //T.C :O(n^2)
    //S.C :O(1)
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int first = nums[i];
            for(int j=i+1; j<n; j++){
                int sec = nums[j];
                int sum = nums[i]+nums[j];
                if(sum == tar){
                    return {i,j};
                }
            }
        }

        return {};
    }
};
/**************** second Method *************/
class Solution {
public:
    //T.C :O(nlogn)
    //S.C :O(1)
    //Apporch two pointer apporch
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());
        int st = 0, end = n-1;
        while(st < end){
            int sum = arr[st].first + arr[end].first;
            if(sum == tar){
                return {arr[st].second, arr[end].second};
            
            }else if(sum > tar){
                end--;
            }else
               st++;
        }

        return {};
    }
};
/******************* 3rd methods *************/
/* Hashing Concept hai */
class Solution {
public:
    //T.C :O(n)
    //S.C :O(n)
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i=0; i<n; i++){
            int first = nums[i];
            int sec = tar - first;

            if(m.find(sec) != m.end()){
                return {m[sec], i};
            }

            m[first] = i;
        }

        return {};
    }
};
