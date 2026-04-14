class Solution {
public:
    /*
    story Point 
    1. when new element comes nums[i], space for it (window size can't be greater than k)
    2. Now, when nums[i] comes, there is no need to keep small elements in that window pop then 
    3. Now push i in deque -> for nums[i]
    4. if(i >= k-1), then deq.front() is our answer for that window
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> ans;
        for(int i=0;i<n; i++){

            //step1 make space for nums[i]
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }

            //step 2
            while(!deq.empty() &&nums[i] > nums[deq.back()]){
                deq.pop_back();
            }

            //step 3
            deq.push_back(i);

            //step 4
            if(i >= k-1){
                ans.push_back(nums[deq.front()]);
            }
        }

        return ans;
    }
};
